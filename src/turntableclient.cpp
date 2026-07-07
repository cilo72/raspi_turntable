#include "turntableclient.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrlQuery>

namespace
{
constexpr const char *DefaultBaseUrl = "http://192.168.7.2";
constexpr const char *KindProperty = "turntableRequestKind";

int jsonInt(const QJsonObject &object, const QString &key, int defaultValue = 0)
{
    const QJsonValue value = object.value(key);

    if (value.isDouble())
        return value.toInt();

    return defaultValue;
}

bool jsonBool(const QJsonObject &object, const QString &key, bool defaultValue = false)
{
    const QJsonValue value = object.value(key);

    if (value.isBool())
        return value.toBool();

    return defaultValue;
}

QString jsonString(const QJsonObject &object, const QString &key)
{
    const QJsonValue value = object.value(key);

    if (value.isString())
        return value.toString();

    return QString();
}
}

TurntableClient::TurntableClient(QObject *parent)
    : TurntableClient(QUrl(QString::fromLatin1(DefaultBaseUrl)), parent)
{
}

TurntableClient::TurntableClient(const QUrl &baseUrl, QObject *parent)
    : QObject(parent),
      baseUrl_(baseUrl),
      network_(new QNetworkAccessManager(this))
{
    qRegisterMetaType<TurntableClient::State>("TurntableClient::State");
    qRegisterMetaType<TurntableClient::Constants>("TurntableClient::Constants");

    connect(network_, &QNetworkAccessManager::finished,
            this, &TurntableClient::handleFinished);
}

QUrl TurntableClient::baseUrl() const
{
    return baseUrl_;
}

void TurntableClient::setBaseUrl(const QUrl &baseUrl)
{
    if (baseUrl_ == baseUrl)
        return;

    baseUrl_ = baseUrl;
    emit baseUrlChanged(baseUrl_);
}

void TurntableClient::refreshState()
{
    get(QStringLiteral("/api/state"), RequestKind::State);
}

void TurntableClient::readLogicalPosition()
{
    get(QStringLiteral("/api/logical/position"), RequestKind::LogicalPosition);
}

void TurntableClient::readLogicalConstants()
{
    get(QStringLiteral("/api/logical/constants"), RequestKind::Constants);
}

void TurntableClient::readHomingOffset()
{
    get(QStringLiteral("/api/offset"), RequestKind::HomingOffset);
}

void TurntableClient::init()
{
    post(QStringLiteral("/api/init"));
}

void TurntableClient::lock()
{
    post(QStringLiteral("/api/lock"));
}

void TurntableClient::unlock()
{
    post(QStringLiteral("/api/unlock"));
}

void TurntableClient::turnClockwise(int count)
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("count"), QString::number(count));
    post(QStringLiteral("/api/turn/cw"), query);
}

void TurntableClient::turnCounterClockwise(int count)
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("count"), QString::number(count));
    post(QStringLiteral("/api/turn/ccw"), query);
}

void TurntableClient::turnTenth(int count)
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("count"), QString::number(count));
    post(QStringLiteral("/api/turn-tenth"), query);
}

void TurntableClient::logicalInit()
{
    post(QStringLiteral("/api/logical/init"));
}

void TurntableClient::powerOn(TurntableClient::Side side)
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("side"),
                       side == TurntableClient::Side::Dot
                           ? QStringLiteral("dot")
                           : QStringLiteral("nodot"));
    post(QStringLiteral("/api/logical/power-on"), query);
}

void TurntableClient::powerOff()
{
    post(QStringLiteral("/api/logical/power-off"));
}

void TurntableClient::turnTo(int position)
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("position"), QString::number(position));
    post(QStringLiteral("/api/logical/turn-to"), query);
}

void TurntableClient::turn180()
{
    post(QStringLiteral("/api/logical/turn-180"));
}

void TurntableClient::turnRelative(int distance)
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("distance"), QString::number(distance));
    post(QStringLiteral("/api/logical/turn-relative"), query);
}

void TurntableClient::setOffset(int value)
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("value"), QString::number(value));
    post(QStringLiteral("/api/offset"), query);
}

void TurntableClient::saveOffset()
{
    post(QStringLiteral("/api/offset/save"));
}

void TurntableClient::setRelais(int index, int value)
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("index"), QString::number(index));
    query.addQueryItem(QStringLiteral("value"), QString::number(value));
    post(QStringLiteral("/api/relais"), query);
}

void TurntableClient::handleFinished(QNetworkReply *reply)
{
    const QUrl url = reply->url();
    const int status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    const auto kind = static_cast<RequestKind>(reply->property(KindProperty).toInt());
    const QByteArray body = reply->readAll();
    const QString networkError = reply->error() == QNetworkReply::NoError
                                     ? QString()
                                     : reply->errorString();

    reply->deleteLater();

    if (!networkError.isEmpty()) {
        emit requestFailed(url, status, errorMessage(body, networkError));
        return;
    }

    switch (kind) {
    case RequestKind::State: {
        const State state = parseState(body);
        emit stateReceived(state);
        break;
    }
    case RequestKind::LogicalPosition: {
        const QJsonDocument document = QJsonDocument::fromJson(body);
        const int position = jsonInt(document.object(), QStringLiteral("position"), -1);
        emit logicalPositionReceived(position);
        break;
    }
    case RequestKind::Constants:
        emit constantsReceived(parseConstants(body));
        break;
    case RequestKind::HomingOffset: {
        const QJsonDocument document = QJsonDocument::fromJson(body);
        const int offset = jsonInt(document.object(), QStringLiteral("homing_offset"), 0);
        emit homingOffsetReceived(offset);
        break;
    }
    case RequestKind::Action: {
        const State state = parseState(body);
        emit stateReceived(state);
        if (state.hasOk && !state.ok)
            emit requestFailed(url, status, errorMessage(body, QStringLiteral("turntable error")));
        break;
    }
    }
}

QUrl TurntableClient::makeUrl(const QString &path) const
{
    QUrl url = baseUrl_;
    url.setPath(path);
    return url;
}

QUrl TurntableClient::makeUrl(const QString &path, const QUrlQuery &query) const
{
    QUrl url = makeUrl(path);
    url.setQuery(query);
    return url;
}

void TurntableClient::get(const QString &path, RequestKind kind)
{
    QNetworkRequest request(makeUrl(path));
    QNetworkReply *reply = network_->get(request);
    reply->setProperty(KindProperty, static_cast<int>(kind));
}

void TurntableClient::post(const QString &path, const QUrlQuery &query)
{
    QNetworkRequest request(makeUrl(path, query));
    QNetworkReply *reply = network_->post(request, QByteArray());
    reply->setProperty(KindProperty, static_cast<int>(RequestKind::Action));
}

TurntableClient::State TurntableClient::parseState(const QByteArray &body)
{
    const QJsonDocument document = QJsonDocument::fromJson(body);
    const QJsonObject object = document.object();

    State state;
    state.hasOk = object.contains(QStringLiteral("ok"));
    state.ok = jsonBool(object, QStringLiteral("ok"));
    state.error = jsonInt(object, QStringLiteral("error"));
    state.position = jsonInt(object, QStringLiteral("position"));
    state.logicalPosition = jsonInt(object, QStringLiteral("logical_position"), -1);
    state.homingOffset = jsonInt(object, QStringLiteral("homing_offset"));
    state.halInitialized = jsonBool(object, QStringLiteral("hal_initialized"));
    state.lastAction = jsonString(object, QStringLiteral("last_action"));
    state.lastError = jsonInt(object, QStringLiteral("last_error"));

    return state;
}

TurntableClient::Constants TurntableClient::parseConstants(const QByteArray &body)
{
    const QJsonDocument document = QJsonDocument::fromJson(body);
    const QJsonObject object = document.object();

    Constants constants;
    constants.numberOfPositions = jsonInt(object, QStringLiteral("number_of_positions"));
    constants.minPosition = jsonInt(object, QStringLiteral("min_position"));
    constants.maxPosition = jsonInt(object, QStringLiteral("max_position"));
    constants.invalidPosition = jsonInt(object, QStringLiteral("invalid_position"), -1);

    return constants;
}

QString TurntableClient::errorMessage(const QByteArray &body, const QString &fallback)
{
    const QJsonDocument document = QJsonDocument::fromJson(body);
    const QJsonObject object = document.object();
    const QJsonValue error = object.value(QStringLiteral("error"));

    if (error.isString())
        return error.toString();
    if (error.isDouble())
        return QString::number(error.toInt());

    return fallback;
}

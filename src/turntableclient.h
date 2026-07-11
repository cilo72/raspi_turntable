#pragma once

#include <QObject>
#include <QString>
#include <QUrl>
#include <QUrlQuery>

class QNetworkAccessManager;
class QNetworkReply;
class QTimer;
class QWebSocket;

class TurntableClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl baseUrl READ baseUrl WRITE setBaseUrl NOTIFY baseUrlChanged)

public:
    enum class Side {
        Dot,
        NoDot
    };
    Q_ENUM(Side)

    struct State {
        bool hasOk = false;
        bool ok = false;
        int error = 0;
        int position = 0;
        int logicalPosition = -1;
        int homingOffset = 0;
        bool halInitialized = false;
        bool moving = false;
        QString lastAction;
        int lastError = 0;
    };

    struct Constants {
        int numberOfPositions = 0;
        int minPosition = 0;
        int maxPosition = 0;
        int invalidPosition = -1;
    };

    explicit TurntableClient(QObject *parent = nullptr);
    explicit TurntableClient(const QUrl &baseUrl, QObject *parent = nullptr);

    QUrl baseUrl() const;
    void setBaseUrl(const QUrl &baseUrl);

public slots:
    void refreshState();
    void readLogicalPosition();
    void readLogicalConstants();
    void readHomingOffset();

    void init();
    void lock();
    void unlock();
    void turnClockwise(int count = 1);
    void turnCounterClockwise(int count = 1);
    void turnTenth(int count);

    void logicalInit();
    void powerOn(TurntableClient::Side side);
    void powerOff();
    void turnTo(int position);
    void turn180();
    void turnRelative(int distance);

    void setOffset(int value);
    void saveOffset();
    void setRelais(int index, int value);

signals:
    void baseUrlChanged(const QUrl &baseUrl);
    void stateReceived(const TurntableClient::State &state);
    void logicalPositionReceived(int position);
    void constantsReceived(const TurntableClient::Constants &constants);
    void homingOffsetReceived(int homingOffset);
    void axisPositionReceived(int positionHundredths, bool moving);
    void positionStreamConnectedChanged(bool connected);
    void requestFailed(const QUrl &url, int httpStatus, const QString &error);

private slots:
    void handleFinished(QNetworkReply *reply);
    void handlePositionMessage(const QString &message);

private:
    enum class RequestKind {
        State,
        LogicalPosition,
        Constants,
        HomingOffset,
        Action
    };

    QUrl makeUrl(const QString &path) const;
    QUrl makeUrl(const QString &path, const QUrlQuery &query) const;
    void get(const QString &path, RequestKind kind);
    void post(const QString &path, const QUrlQuery &query = QUrlQuery());
    void connectPositionStream();
    void schedulePositionStreamReconnect();

    static State parseState(const QByteArray &body);
    static Constants parseConstants(const QByteArray &body);
    static QString errorMessage(const QByteArray &body, const QString &fallback);

private:
    QUrl baseUrl_;
    QNetworkAccessManager *network_;
    QWebSocket *positionSocket_;
    QTimer *positionReconnectTimer_;
    int positionReconnectDelayMs_ = 500;
};

Q_DECLARE_METATYPE(TurntableClient::State)
Q_DECLARE_METATYPE(TurntableClient::Constants)

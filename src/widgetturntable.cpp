#include "widgetturntable.h"

#include <QMouseEvent>
#include <QPainter>
#include <QtMath>

namespace {

constexpr qreal CanvasSize = 1200.0;
constexpr qreal Center = CanvasSize / 2.0;
constexpr int PositionCount = 20;
constexpr qreal PositionStep = 360.0 / PositionCount;
constexpr int HundredthsPerDegree = 100;
constexpr int FullRotationHundredths = 360 * HundredthsPerDegree;
const QColor BridgeColor(0xcf, 0xcf, 0xcf);
const QColor CenterDotColor(0x66, 0x66, 0x66);
const QColor CenterHubColor(0xb8, 0xb8, 0xb8);
const QColor DarkColor(0x11, 0x11, 0x11);
const QColor EdgeColor(0x66, 0x66, 0x66);
const QColor GuideColor(0xd0, 0xd0, 0xd0);
const QColor DisabledRailColor(0x99, 0x99, 0x99);
const QColor PitColor(0xf2, 0xf2, 0xf2);
const QColor RailBedColor(0x8b, 0x5a, 0x2b);
const QColor RimColor(0x88, 0x88, 0x88);
const QColor ServiceRingColor(0x55, 0x55, 0x55);
const QColor StrokeColor(0x22, 0x22, 0x22);
const QColor TargetColor(0x1f, 0x6f, 0xd1);

const int UsedTracks[] = {
    0, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19
};

bool isUsedTrack(int track)
{
    for (int usedTrack : UsedTracks) {
        if (usedTrack == track)
            return true;
    }

    return false;
}

QPointF polarPoint(qreal angleDegrees, qreal radius)
{
    const qreal angleRadians = qDegreesToRadians(angleDegrees);
    return QPointF(Center + std::cos(angleRadians) * radius,
                   Center + std::sin(angleRadians) * radius);
}

QPen pen(const QColor &color, qreal width, Qt::PenStyle style = Qt::SolidLine)
{
    QPen result(color, width, style, Qt::RoundCap, Qt::RoundJoin);
    return result;
}

} // namespace

WidgetTurntable::WidgetTurntable(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(300, 300);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

int WidgetTurntable::bridgePosition() const
{
    return m_bridgePosition;
}

int WidgetTurntable::targetPosition() const
{
    return m_targetPosition;
}

bool WidgetTurntable::bridgeEnabled() const
{
    return m_bridgeEnabled;
}

bool WidgetTurntable::trackEnabled(int trackNumber) const
{
    return trackNumber >= 0 && trackNumber < PositionCount
           && m_trackEnabled[trackNumber];
}

void WidgetTurntable::setBridgePosition(int positionHundredths)
{
    int normalizedPosition = positionHundredths % FullRotationHundredths;

    if (normalizedPosition < 0)
        normalizedPosition += FullRotationHundredths;

    if (m_bridgePosition == normalizedPosition)
        return;

    m_bridgePosition = normalizedPosition;
    update();
}

void WidgetTurntable::setTargetPosition(int position)
{
    const int boundedPosition = position < 0
                                    ? -1
                                    : qBound(0, position, PositionCount - 1);

    if (m_targetPosition == boundedPosition)
        return;

    m_targetPosition = boundedPosition;
    update();
}

void WidgetTurntable::setBridgeEnabled(bool enabled)
{
    if (m_bridgeEnabled == enabled)
        return;

    m_bridgeEnabled = enabled;
    update();
    emit bridgeEnabledChanged(enabled);
}

void WidgetTurntable::setTrackEnabled(int trackNumber, bool enabled)
{
    if (trackNumber < 0 || trackNumber >= PositionCount
        || m_trackEnabled[trackNumber] == enabled)
        return;

    m_trackEnabled[trackNumber] = enabled;
    update();
    emit trackEnabledChanged(trackNumber, enabled);
}

void WidgetTurntable::mousePressEvent(QMouseEvent *event)
{
    const QPointF worldPos = mapToWorld(event->pos());
    const int track = trackAtPoint(worldPos);

    if (track >= 0)
        emit trackClicked(track);

    QWidget::mousePressEvent(event);
}

void WidgetTurntable::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), Qt::white);

    const qreal scale = std::min(width() / CanvasSize, height() / CanvasSize);
    painter.translate((width() - CanvasSize * scale) / 2.0,
                      (height() - CanvasSize * scale) / 2.0);
    painter.scale(scale, scale);

    drawTurntable(painter);
}

QPointF WidgetTurntable::mapToWorld(const QPointF &widgetPos) const
{
    const qreal scale = std::min(width() / CanvasSize, height() / CanvasSize);

    if (scale <= 0.0)
        return QPointF();

    return QPointF((widgetPos.x() - (width() - CanvasSize * scale) / 2.0) / scale,
                   (widgetPos.y() - (height() - CanvasSize * scale) / 2.0) / scale);
}

int WidgetTurntable::trackAtPoint(const QPointF &worldPos) const
{
    const QPointF p = worldPos - QPointF(Center, Center);
    const double radius = std::hypot(p.x(), p.y());

    if (radius < 120.0)
        return -1;

    double angle = std::atan2(p.y(), p.x()) * 180.0 / M_PI;

    if (angle < 0.0)
        angle += 360.0;

    const int track = qRound(angle / PositionStep) % PositionCount;

    if (!isUsedTrack(track))
        return -1;

    return track;
}

void WidgetTurntable::drawBridge(QPainter &painter) const
{
    painter.save();

    painter.setPen(pen(StrokeColor, 3));
    painter.setBrush(BridgeColor);
    painter.drawRoundedRect(QRectF(295, 565, 610, 70), 4, 4);

    painter.setPen(pen(EdgeColor, 2));
    painter.drawLine(QPointF(305, 585), QPointF(895, 585));
    painter.drawLine(QPointF(305, 615), QPointF(895, 615));

    painter.setPen(pen(RailBedColor, 5));
    for (int x = 330; x <= 870; x += 30)
        painter.drawLine(QPointF(x, 580), QPointF(x, 620));

    const QColor railColor = m_bridgeEnabled ? DarkColor : DisabledRailColor;

    painter.setPen(pen(railColor, 5));
    painter.drawLine(QPointF(295, 590), QPointF(905, 590));

    painter.setPen(pen(railColor, 5));
    painter.drawLine(QPointF(295, 610), QPointF(905, 610));

    painter.setPen(pen(StrokeColor, 3));
    painter.setBrush(CenterHubColor);
    painter.drawEllipse(QPointF(Center, Center), 18, 18);

    painter.setPen(Qt::NoPen);
    painter.setBrush(CenterDotColor);
    painter.drawEllipse(QPointF(Center, Center), 7, 7);

    painter.setBrush(TargetColor);
    painter.drawEllipse(QPointF(900, 600), 14, 14);

    painter.restore();
}

void WidgetTurntable::drawTargetIndicator(QPainter &painter) const
{
    if (m_targetPosition < 0)
        return;

    const qreal angle = m_targetPosition * PositionStep;
    const QPointF targetPoint = polarPoint(angle, 322);

    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(TargetColor);
    painter.drawEllipse(targetPoint, 24, 24);
    painter.restore();
}

void WidgetTurntable::drawTrack(QPainter &painter, int trackNumber) const
{
    painter.save();

    painter.setPen(pen(RailBedColor, 5));
    for (int x = 945; x <= 1095; x += 25)
        painter.drawLine(QPointF(x, 580), QPointF(x, 620));

    const QColor railColor = m_trackEnabled[trackNumber]
                                 ? DarkColor
                                 : DisabledRailColor;

    painter.setPen(pen(railColor, 5));
    painter.drawLine(QPointF(920, 590), QPointF(1120, 590));

    painter.setPen(pen(railColor, 5));
    painter.drawLine(QPointF(920, 610), QPointF(1120, 610));

    painter.restore();
}

void WidgetTurntable::drawTurntable(QPainter &painter) const
{
    painter.setPen(pen(StrokeColor, 3));
    painter.setBrush(PitColor);
    painter.drawEllipse(QPointF(Center, Center), 315, 315);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(pen(RimColor, 36));
    painter.drawEllipse(QPointF(Center, Center), 345, 345);

    painter.setPen(pen(StrokeColor, 5));
    painter.drawEllipse(QPointF(Center, Center), 300, 300);

    painter.setPen(pen(ServiceRingColor, 2, Qt::DashLine));
    painter.drawEllipse(QPointF(Center, Center), 275, 275);

    painter.setPen(pen(GuideColor, 1.5, Qt::DashLine));
    for (int i = 0; i < PositionCount; ++i)
        painter.drawLine(QPointF(Center, Center), polarPoint(i * PositionStep, 250));

    painter.save();
    painter.translate(Center, Center);
    painter.rotate(static_cast<qreal>(m_bridgePosition) / HundredthsPerDegree);
    painter.translate(-Center, -Center);
    drawBridge(painter);
    painter.restore();

    for (int track : UsedTracks) {
        painter.save();
        painter.translate(Center, Center);
        painter.rotate(track * PositionStep);
        painter.translate(-Center, -Center);

        drawTrack(painter, track);
        painter.restore();
    }

    drawTargetIndicator(painter);

    QFont labelFont = painter.font();
    labelFont.setFamily(QStringLiteral("Arial"));
    labelFont.setPointSize(34);
    labelFont.setBold(true);
    painter.setFont(labelFont);
    painter.setPen(DarkColor);

    for (int track : UsedTracks) {
        const QPointF pos = polarPoint(track * PositionStep, 555);
        painter.drawText(QRectF(pos.x() - 45, pos.y() - 28, 90, 56),
                         Qt::AlignCenter,
                         QString::number(track));
    }
}

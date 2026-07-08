#include "widgetturntable.h"

#include <QMouseEvent>
#include <QPainter>
#include <QtMath>

namespace {

constexpr qreal CanvasSize = 1200.0;
constexpr qreal Center = CanvasSize / 2.0;
constexpr int PositionCount = 20;
constexpr qreal PositionStep = 360.0 / PositionCount;

const int UsedTracks[] = {
    0, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
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

void WidgetTurntable::mousePressEvent(QMouseEvent *event)
{
    const int track = trackAtPoint(mapToWorld(event->pos()));

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

    painter.setPen(pen(QColor("#222222"), 3));
    painter.setBrush(QColor("#cfcfcf"));
    painter.drawRoundedRect(QRectF(295, 565, 610, 70), 4, 4);

    painter.setPen(pen(QColor("#666666"), 2));
    painter.drawLine(QPointF(305, 585), QPointF(895, 585));
    painter.drawLine(QPointF(305, 615), QPointF(895, 615));

    painter.setPen(pen(QColor("#8b5a2b"), 5));
    for (int x = 330; x <= 870; x += 30)
        painter.drawLine(QPointF(x, 580), QPointF(x, 620));

    painter.setPen(pen(Qt::red, 5));
    painter.drawLine(QPointF(295, 590), QPointF(905, 590));

    painter.setPen(pen(QColor("#111111"), 5));
    painter.drawLine(QPointF(295, 610), QPointF(905, 610));

    painter.setPen(pen(QColor("#222222"), 3));
    painter.setBrush(QColor("#b8b8b8"));
    painter.drawEllipse(QPointF(Center, Center), 18, 18);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#666666"));
    painter.drawEllipse(QPointF(Center, Center), 7, 7);

    painter.setBrush(Qt::black);
    painter.drawEllipse(QPointF(900, 630), 7, 7);

    painter.restore();
}

void WidgetTurntable::drawTrack(QPainter &painter, TrackPolarity polarity, bool used) const
{
    painter.save();

    const QColor railColor = used ? QColor("#111111") : QColor("#999999");
    const QColor sleeperColor = used ? QColor("#8b5a2b") : QColor("#aaaaaa");
    const Qt::PenStyle railStyle = used ? Qt::SolidLine : Qt::DashLine;
    const Qt::PenStyle sleeperStyle = used ? Qt::SolidLine : Qt::DashLine;

    painter.setPen(pen(sleeperColor, 5, sleeperStyle));
    for (int x = 945; x <= 1095; x += 25)
        painter.drawLine(QPointF(x, 580), QPointF(x, 620));

    const bool dotUp = polarity == TrackPolarity::DotUp;

    painter.setPen(pen(dotUp && used ? Qt::red : railColor, 5, railStyle));
    painter.drawLine(QPointF(920, 590), QPointF(1120, 590));

    painter.setPen(pen(!dotUp && used ? Qt::red : railColor, 5, railStyle));
    painter.drawLine(QPointF(920, 610), QPointF(1120, 610));

    painter.restore();
}

void WidgetTurntable::drawTurntable(QPainter &painter) const
{
    painter.setPen(pen(QColor("#222222"), 3));
    painter.setBrush(QColor("#f2f2f2"));
    painter.drawEllipse(QPointF(Center, Center), 315, 315);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(pen(QColor("#888888"), 36));
    painter.drawEllipse(QPointF(Center, Center), 345, 345);

    painter.setPen(pen(QColor("#222222"), 5));
    painter.drawEllipse(QPointF(Center, Center), 300, 300);

    painter.setPen(pen(QColor("#555555"), 2, Qt::DashLine));
    painter.drawEllipse(QPointF(Center, Center), 275, 275);

    painter.setPen(pen(QColor("#d0d0d0"), 1.5, Qt::DashLine));
    for (int i = 0; i < PositionCount; ++i)
        painter.drawLine(QPointF(Center, Center), polarPoint(i * PositionStep, 250));

    painter.save();
    painter.translate(Center, Center);
    painter.rotate(270);
    painter.translate(-Center, -Center);
    drawBridge(painter);
    painter.restore();

    for (int track = 0; track < PositionCount; ++track) {
        const bool used = isUsedTrack(track);

        if (!used && track != 1 && track != 2 && track != 3 && track != 4)
            continue;

        painter.save();
        painter.translate(Center, Center);
        painter.rotate(track * PositionStep);
        painter.translate(-Center, -Center);

        const TrackPolarity polarity = track == 0 || track >= 16
                                           ? TrackPolarity::DotUp
                                           : TrackPolarity::DotDown;
        drawTrack(painter, polarity, used);
        painter.restore();
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#aabbcc"));
    painter.drawEllipse(polarPoint(180, 300), 22, 22);

    QFont labelFont = painter.font();
    labelFont.setFamily(QStringLiteral("Arial"));
    labelFont.setPointSize(34);
    labelFont.setBold(true);
    painter.setFont(labelFont);
    painter.setPen(QColor("#111111"));

    for (int track : UsedTracks) {
        const QPointF pos = polarPoint(track * PositionStep, 555);
        painter.drawText(QRectF(pos.x() - 45, pos.y() - 28, 90, 56),
                         Qt::AlignCenter,
                         QString::number(track));
    }
}

#include "widgetturntable.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QtMath>

WidgetTurntable::WidgetTurntable(QWidget *parent)
    : QWidget(parent),
    m_view(new QGraphicsView(this)),
    m_scene(new QGraphicsScene(this)),
    m_svg(new QGraphicsSvgItem(":/resources/images/turntable.svg"))
{
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_view);

    m_scene->addItem(m_svg);

    m_view->setScene(m_scene);
    m_view->setRenderHint(QPainter::Antialiasing);
    m_view->setDragMode(QGraphicsView::NoDrag);
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_view->viewport()->installEventFilter(this);

    m_scene->setSceneRect(m_svg->boundingRect());

    QRectF r = m_svg->boundingRect();
    m_center = r.center();

    fitSvg();
}

void WidgetTurntable::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    fitSvg();
}

void WidgetTurntable::fitSvg()
{
    if (!m_svg)
        return;

    m_view->fitInView(m_svg->boundingRect(), Qt::KeepAspectRatio);
}

bool WidgetTurntable::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_view->viewport() && event->type() == QEvent::MouseButtonPress) {
        auto *mouseEvent = static_cast<QMouseEvent *>(event);

        QPointF scenePos = m_view->mapToScene(mouseEvent->pos());
        int track = trackAtPoint(scenePos);

        if (track >= 0)
            emit trackClicked(track);

        return true;
    }

    return QWidget::eventFilter(watched, event);
}

int WidgetTurntable::trackAtPoint(const QPointF &scenePos) const
{
    QPointF p = scenePos - m_center;

    double radius = std::hypot(p.x(), p.y());

    if (radius < 120)
        return -1;   // Mitte ignorieren, Wert ggf. an dein SVG anpassen

    double angle = std::atan2(p.y(), p.x()) * 180.0 / M_PI;

    if (angle < 0)
        angle += 360.0;

    int track = qRound(angle / 18.0) % 20;

    if (track >= 1 && track <= 4)
        return -1;   // nicht verwendet

    return track;
}
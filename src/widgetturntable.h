#pragma once

#include <QWidget>

class QGraphicsView;
class QGraphicsScene;
class QGraphicsSvgItem;

class WidgetTurntable : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTurntable(QWidget *parent = nullptr);

signals:
    void trackClicked(int trackNumber);

protected:
    void resizeEvent(QResizeEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    int trackAtPoint(const QPointF &scenePos) const;
    void fitSvg();

private:
    QGraphicsView *m_view;
    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_svg;

    QPointF m_center;
};
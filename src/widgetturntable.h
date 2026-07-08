#pragma once

#include <QWidget>

class QMouseEvent;
class QPaintEvent;
class QPainter;

class WidgetTurntable : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTurntable(QWidget *parent = nullptr);

    int bridgePosition() const;
    int targetPosition() const;

public slots:
    void setBridgePosition(int position);
    void setTargetPosition(int position);

signals:
    void trackClicked(int trackNumber);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    enum class TrackPolarity {
        DotUp,
        DotDown
    };

    QPointF mapToWorld(const QPointF &widgetPos) const;
    int trackAtPoint(const QPointF &worldPos) const;
    void drawBridge(QPainter &painter) const;
    void drawTargetIndicator(QPainter &painter) const;
    void drawTrack(QPainter &painter, TrackPolarity polarity) const;
    void drawTurntable(QPainter &painter) const;

    int m_bridgePosition = 0;
    int m_targetPosition = -1;
};

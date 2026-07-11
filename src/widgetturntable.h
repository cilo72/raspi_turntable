#pragma once

#include <array>
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
    bool bridgeEnabled() const;
    bool trackEnabled(int trackNumber) const;

public slots:
    void setBridgePosition(int positionHundredths);
    void setTargetPosition(int position);
    void setBridgeEnabled(bool enabled);
    void setTrackEnabled(int trackNumber, bool enabled);

signals:
    void trackClicked(int trackNumber);
    void bridgeEnabledChanged(bool enabled);
    void trackEnabledChanged(int trackNumber, bool enabled);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPointF mapToWorld(const QPointF &widgetPos) const;
    int trackAtPoint(const QPointF &worldPos) const;
    void drawBridge(QPainter &painter) const;
    void drawTargetIndicator(QPainter &painter) const;
    void drawTrack(QPainter &painter, int trackNumber) const;
    void drawTurntable(QPainter &painter) const;

    int m_bridgePosition = 0;
    int m_targetPosition = -1;
    bool m_bridgeEnabled = false;
    std::array<bool, 20> m_trackEnabled{};
};

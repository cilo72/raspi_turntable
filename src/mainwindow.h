#pragma once

#include <QMainWindow>
#include "turntableclient.h"
#include "widgetturntable.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButtonLowLevelBridgeLock_clicked();

    void on_pushButtonLowLevelBridgeUnlock_clicked();

    void on_pushButtonLowLevelPowerOff_clicked();

    void on_pushButtonLowLevelPowerOnDot_clicked();

    void on_pushButtonLowLevelPowerOnNoDot_clicked();

    void on_pushButtonLowLevelInit_clicked();

    void on_LowLevelTurnPlusOne_clicked();

    void on_pushButtonLowLevelTurnMinusOne_clicked();

    void on_pushButtonLowLevelTurn180_clicked();

    void on_pushButtonLowLevelReset_clicked();

    void on_pushButtonCW1_0_clicked();

    void on_pushButtonCW0_1_clicked();

    void on_pushButtonCCW1_0_clicked();

    void on_pushButtonCCW0_1_clicked();

    void on_pushButtonPageMain_clicked();

    void on_pushButtonPageLowLevel_clicked();

private:
    Ui::MainWindow *ui;
    TurntableClient *turntableClient_;
    WidgetTurntable * widgetTurntable_;
};

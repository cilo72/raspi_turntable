#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QMutex>
#include <QTimer>
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

    void on_pushButtonMinus_clicked();

    void on_pushButtonPlus_clicked();

    void on_pushButtonInit_clicked();

    void on_pushButtonTurn_clicked();

    void on_pushButtonPowerOnDot_clicked();

    void on_pushButtonPowerOnNoDot_clicked();

    void on_pushButtonPowerOff_clicked();

    void on_pushButtonTurn180_clicked();

    void on_pushButtonPageErrorBack_clicked();

    void on_pushButtonLowLevelInit2_clicked();

    void on_pushButtonLowLevelSave_clicked();

    void on_pushButtonExit_clicked();

private:
    Ui::MainWindow *ui;
    TurntableClient *turntableClient_;
    WidgetTurntable * widgetTurntable_;
    int32_t position_;
    QTimer timer_;
    QPushButton * timerPushButton_;
    int32_t iconSize_;
    QMutex mutexButton_;
    QWidget * backToPage_;

    void updateWidgetTurntable();
    void disableButtons();
    void enableButtons();
    void setEnableButtons(bool enable);
    void setBlinkingButton(QPushButton * button);
};

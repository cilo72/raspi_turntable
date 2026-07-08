#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , turntableClient_(new TurntableClient(this))
    , widgetTurntable_(new WidgetTurntable(this))
{
    ui->setupUi(this);
    ui->horizontalLayoutDisplay->addWidget(widgetTurntable_);

    connect(turntableClient_, &TurntableClient::stateReceived,
            this, [this](const TurntableClient::State &state) {
        ui->labelLowLevelLogicalPosition->setText(QString("%1").arg(state.logicalPosition));
        ui->labelLowLevelLastError->setText(QString("%1").arg(state.lastError));
        ui->labelLowLevelLastAction->setText(QString("%1").arg(state.lastAction));
        ui->labelLowLevelAxisPosition->setText(QString("%1").arg(state.position));

        turntableClient_->readHomingOffset();

            });
    connect(turntableClient_, &TurntableClient::requestFailed,
            this, [this](const QUrl &, int httpStatus, const QString &error) {
            });
    connect(turntableClient_, &TurntableClient::homingOffsetReceived,
            this, [this](int homingOffset) {
            ui->labelLowLevelHomeOffset->setText(QString("%1").arg(homingOffset));
            });

    turntableClient_->readHomingOffset();
    turntableClient_->refreshState();
}

MainWindow::~MainWindow()
{
    delete widgetTurntable_;
    delete ui;
}

void MainWindow::on_pushButtonLowLevelBridgeLock_clicked()
{
    turntableClient_->lock();
}

void MainWindow::on_pushButtonLowLevelBridgeUnlock_clicked()
{
    turntableClient_->unlock();
}

void MainWindow::on_pushButtonLowLevelPowerOff_clicked()
{
    turntableClient_->powerOff();
}

void MainWindow::on_pushButtonLowLevelPowerOnDot_clicked()
{
    turntableClient_->powerOn(TurntableClient::Side::Dot);
}

void MainWindow::on_pushButtonLowLevelPowerOnNoDot_clicked()
{
    turntableClient_->powerOn(TurntableClient::Side::NoDot);
}

void MainWindow::on_pushButtonLowLevelInit_clicked()
{
    turntableClient_->logicalInit();
}

void MainWindow::on_LowLevelTurnPlusOne_clicked()
{
    turntableClient_->turnClockwise();
}

void MainWindow::on_pushButtonLowLevelTurnMinusOne_clicked()
{
    turntableClient_->turnCounterClockwise();
}

void MainWindow::on_pushButtonLowLevelTurn180_clicked()
{
    turntableClient_->turn180();
}

void MainWindow::on_pushButtonLowLevelReset_clicked()
{
    turntableClient_->setOffset(0);
}

void MainWindow::on_pushButtonCW1_0_clicked()
{
    turntableClient_->turnTenth(10);
}

void MainWindow::on_pushButtonCW0_1_clicked()
{
    turntableClient_->turnTenth(1);
}

void MainWindow::on_pushButtonCCW1_0_clicked()
{
    turntableClient_->turnTenth(-10);
}

void MainWindow::on_pushButtonCCW0_1_clicked()
{
    turntableClient_->turnTenth(-1);
}

void MainWindow::on_pushButtonPageMain_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
}

void MainWindow::on_pushButtonPageLowLevel_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageLowLevel);
}

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{

}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->label->setText(QString("%1").arg(position));
}

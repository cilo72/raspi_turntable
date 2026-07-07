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
    ui->verticalLayout->addWidget(widgetTurntable_);

    connect(turntableClient_, &TurntableClient::stateReceived,
            this, [this](const TurntableClient::State &state) {
        ui->labelLowLevelLogicalPosition->setText(QString("%1").arg(state.logicalPosition));
        ui->labelLowLevelLastError->setText(QString("%1").arg(state.lastError));
        ui->labelLowLevelLastAction->setText(QString("%1").arg(state.lastAction));
        ui->labelLowLevelAxisPosition->setText(QString("%1").arg(state.position));

        turntableClient_->readHomingOffset();

                ui->label->setText(QString("Init %1 | position: %2 | logical: %3 | error: %4")
                                       .arg(state.hasOk && state.ok ? "OK" : "failed")
                                       .arg(state.position)
                                       .arg(state.logicalPosition)
                                       .arg(state.lastError));
            });
    connect(turntableClient_, &TurntableClient::requestFailed,
            this, [this](const QUrl &, int httpStatus, const QString &error) {
                ui->label->setText(QString("Init failed | HTTP: %1 | %2")
                                       .arg(httpStatus)
                                       .arg(error));
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

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Init running...");
    turntableClient_->init();
}

void MainWindow::on_pushButtonLowLevelBridgeLock_clicked()
{
    ui->label->setText("Lock running...");
    turntableClient_->lock();
}

void MainWindow::on_pushButtonLowLevel_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageLowLevel);
}

void MainWindow::on_pushButtonLowLevelBridgeUnlock_clicked()
{
    ui->label->setText("Unlock running...");
    turntableClient_->unlock();
}

void MainWindow::on_pushButtonLowLevelPowerOff_clicked()
{
    ui->label->setText("Power Off running...");
    turntableClient_->powerOff();
}

void MainWindow::on_pushButtonLowLevelPowerOnDot_clicked()
{
    ui->label->setText("Power On Dot running...");
    turntableClient_->powerOn(TurntableClient::Side::Dot);
}

void MainWindow::on_pushButtonLowLevelPowerOnNoDot_clicked()
{
    ui->label->setText("Power On No Dot running...");
    turntableClient_->powerOn(TurntableClient::Side::NoDot);
}

void MainWindow::on_pushButtonLowLevelInit_clicked()
{
    ui->label->setText("Init running...");
    turntableClient_->logicalInit();
}

void MainWindow::on_LowLevelTurnPlusOne_clicked()
{
    ui->label->setText("Turn running...");
    turntableClient_->turnClockwise();
}

void MainWindow::on_pushButtonLowLevelTurnMinusOne_clicked()
{
    ui->label->setText("Turn running...");
    turntableClient_->turnCounterClockwise();
}

void MainWindow::on_pushButtonLowLevelTurn180_clicked()
{
    ui->label->setText("Turn running...");
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

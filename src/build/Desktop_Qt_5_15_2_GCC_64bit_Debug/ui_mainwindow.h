/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonPageMain;
    QPushButton *pushButtonPageLowLevel;
    QStackedWidget *stackedWidget;
    QWidget *pageMain;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayoutDisplay;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonTurn;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButtonMinus;
    QPushButton *pushButtonInit;
    QLabel *label;
    QPushButton *pushButton_9;
    QPushButton *pushButtonPlus;
    QWidget *pageLowLevel;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_10;
    QLabel *labelLowLevelLastAction;
    QFrame *frame_20;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QLabel *labelLowLevelHomeOffset;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *labelLowLevelAxisPosition;
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QLabel *labelLowLevelLogicalPosition;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_11;
    QLabel *labelLowLevelLastError;
    QFrame *frame_41;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonLowLevelBridgeLock;
    QPushButton *pushButtonLowLevelBridgeUnlock;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButtonLowLevelPowerOff;
    QPushButton *pushButtonLowLevelPowerOnDot;
    QPushButton *pushButtonLowLevelPowerOnNoDot;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButtonLowLevelInit;
    QPushButton *LowLevelTurnPlusOne;
    QPushButton *pushButtonLowLevelTurnMinusOne;
    QPushButton *pushButtonLowLevelTurn180;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonLowLevelReset;
    QPushButton *pushButtonLowLevelSave;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButtonCW1_0;
    QPushButton *pushButtonCW0_1;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonCCW1_0;
    QPushButton *pushButtonCCW0_1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonPageMain = new QPushButton(centralwidget);
        pushButtonPageMain->setObjectName(QString::fromUtf8("pushButtonPageMain"));
        pushButtonPageMain->setMinimumSize(QSize(80, 50));
        QFont font;
        font.setPointSize(20);
        pushButtonPageMain->setFont(font);

        horizontalLayout->addWidget(pushButtonPageMain);

        pushButtonPageLowLevel = new QPushButton(centralwidget);
        pushButtonPageLowLevel->setObjectName(QString::fromUtf8("pushButtonPageLowLevel"));
        pushButtonPageLowLevel->setMinimumSize(QSize(80, 50));
        pushButtonPageLowLevel->setFont(font);

        horizontalLayout->addWidget(pushButtonPageLowLevel);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pageMain = new QWidget();
        pageMain->setObjectName(QString::fromUtf8("pageMain"));
        horizontalLayout_2 = new QHBoxLayout(pageMain);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayoutDisplay = new QHBoxLayout();
        horizontalLayoutDisplay->setObjectName(QString::fromUtf8("horizontalLayoutDisplay"));

        horizontalLayout_2->addLayout(horizontalLayoutDisplay);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonTurn = new QPushButton(pageMain);
        pushButtonTurn->setObjectName(QString::fromUtf8("pushButtonTurn"));
        pushButtonTurn->setMinimumSize(QSize(70, 70));
        pushButtonTurn->setMaximumSize(QSize(70, 70));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        pushButtonTurn->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/rotate-right.svg"), QSize(), QIcon::Normal, QIcon::On);
        pushButtonTurn->setIcon(icon);
        pushButtonTurn->setIconSize(QSize(48, 48));

        gridLayout_2->addWidget(pushButtonTurn, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(pageMain);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(70, 70));
        pushButton_8->setMaximumSize(QSize(70, 70));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        pushButton_8->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/refresh.svg"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_8->setIcon(icon1);
        pushButton_8->setIconSize(QSize(48, 48));

        gridLayout_2->addWidget(pushButton_8, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(pageMain);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(70, 70));
        pushButton_7->setMaximumSize(QSize(70, 70));
        pushButton_7->setFont(font1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/circle-empty.svg"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_7->setIcon(icon2);
        pushButton_7->setIconSize(QSize(48, 48));

        gridLayout_2->addWidget(pushButton_7, 3, 2, 1, 1);

        pushButton_6 = new QPushButton(pageMain);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(70, 70));
        pushButton_6->setMaximumSize(QSize(70, 70));
        pushButton_6->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/circle-full.svg"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_6->setIcon(icon3);
        pushButton_6->setIconSize(QSize(48, 48));

        gridLayout_2->addWidget(pushButton_6, 3, 0, 1, 1);

        pushButtonMinus = new QPushButton(pageMain);
        pushButtonMinus->setObjectName(QString::fromUtf8("pushButtonMinus"));
        pushButtonMinus->setMinimumSize(QSize(70, 70));
        pushButtonMinus->setMaximumSize(QSize(70, 70));
        QFont font3;
        font3.setPointSize(32);
        font3.setBold(true);
        pushButtonMinus->setFont(font3);

        gridLayout_2->addWidget(pushButtonMinus, 1, 0, 1, 1);

        pushButtonInit = new QPushButton(pageMain);
        pushButtonInit->setObjectName(QString::fromUtf8("pushButtonInit"));
        pushButtonInit->setMinimumSize(QSize(70, 70));
        pushButtonInit->setMaximumSize(QSize(70, 70));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/rocket-lunch.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonInit->setIcon(icon4);
        pushButtonInit->setIconSize(QSize(48, 48));
        pushButtonInit->setCheckable(false);
        pushButtonInit->setAutoExclusive(false);

        gridLayout_2->addWidget(pushButtonInit, 0, 1, 1, 1);

        label = new QLabel(pageMain);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        label->setFont(font4);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 2, 0, 1, 3);

        pushButton_9 = new QPushButton(pageMain);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(70, 70));
        pushButton_9->setMaximumSize(QSize(70, 70));
        pushButton_9->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/power.svg"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_9->setIcon(icon5);
        pushButton_9->setIconSize(QSize(48, 48));

        gridLayout_2->addWidget(pushButton_9, 3, 1, 1, 1);

        pushButtonPlus = new QPushButton(pageMain);
        pushButtonPlus->setObjectName(QString::fromUtf8("pushButtonPlus"));
        pushButtonPlus->setMinimumSize(QSize(70, 70));
        pushButtonPlus->setMaximumSize(QSize(70, 70));
        pushButtonPlus->setFont(font3);

        gridLayout_2->addWidget(pushButtonPlus, 1, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        stackedWidget->addWidget(pageMain);
        pageLowLevel = new QWidget();
        pageLowLevel->setObjectName(QString::fromUtf8("pageLowLevel"));
        sizePolicy.setHeightForWidth(pageLowLevel->sizePolicy().hasHeightForWidth());
        pageLowLevel->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(pageLowLevel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(pageLowLevel);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font5;
        font5.setPointSize(16);
        label_10->setFont(font5);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_10);

        labelLowLevelLastAction = new QLabel(frame_4);
        labelLowLevelLastAction->setObjectName(QString::fromUtf8("labelLowLevelLastAction"));
        labelLowLevelLastAction->setFont(font1);
        labelLowLevelLastAction->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(labelLowLevelLastAction);


        gridLayout->addWidget(frame_4, 0, 3, 1, 1);

        frame_20 = new QFrame(pageLowLevel);
        frame_20->setObjectName(QString::fromUtf8("frame_20"));
        frame_20->setFrameShape(QFrame::StyledPanel);
        frame_20->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_20);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_9 = new QLabel(frame_20);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font5);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_9);

        labelLowLevelHomeOffset = new QLabel(frame_20);
        labelLowLevelHomeOffset->setObjectName(QString::fromUtf8("labelLowLevelHomeOffset"));
        labelLowLevelHomeOffset->setFont(font1);
        labelLowLevelHomeOffset->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(labelLowLevelHomeOffset);


        gridLayout->addWidget(frame_20, 0, 2, 1, 1);

        frame_2 = new QFrame(pageLowLevel);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font5);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        labelLowLevelAxisPosition = new QLabel(frame_2);
        labelLowLevelAxisPosition->setObjectName(QString::fromUtf8("labelLowLevelAxisPosition"));
        labelLowLevelAxisPosition->setFont(font1);
        labelLowLevelAxisPosition->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelLowLevelAxisPosition);


        gridLayout->addWidget(frame_2, 0, 1, 1, 1);

        frame = new QFrame(pageLowLevel);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font6;
        font6.setPointSize(16);
        font6.setBold(false);
        label_3->setFont(font6);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_3);

        labelLowLevelLogicalPosition = new QLabel(frame);
        labelLowLevelLogicalPosition->setObjectName(QString::fromUtf8("labelLowLevelLogicalPosition"));
        labelLowLevelLogicalPosition->setFont(font1);
        labelLowLevelLogicalPosition->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelLowLevelLogicalPosition);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        frame1 = new QFrame(pageLowLevel);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame1);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_11 = new QLabel(frame1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font5);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_11);

        labelLowLevelLastError = new QLabel(frame1);
        labelLowLevelLastError->setObjectName(QString::fromUtf8("labelLowLevelLastError"));
        labelLowLevelLastError->setFont(font1);
        labelLowLevelLastError->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(labelLowLevelLastError);


        gridLayout->addWidget(frame1, 0, 4, 1, 1);

        frame_41 = new QFrame(pageLowLevel);
        frame_41->setObjectName(QString::fromUtf8("frame_41"));
        sizePolicy.setHeightForWidth(frame_41->sizePolicy().hasHeightForWidth());
        frame_41->setSizePolicy(sizePolicy);
        frame_41->setFrameShape(QFrame::StyledPanel);
        frame_41->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_41);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_4 = new QLabel(frame_41);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);

        pushButtonLowLevelBridgeLock = new QPushButton(frame_41);
        pushButtonLowLevelBridgeLock->setObjectName(QString::fromUtf8("pushButtonLowLevelBridgeLock"));
        pushButtonLowLevelBridgeLock->setMinimumSize(QSize(80, 50));
        pushButtonLowLevelBridgeLock->setFont(font5);

        verticalLayout_9->addWidget(pushButtonLowLevelBridgeLock);

        pushButtonLowLevelBridgeUnlock = new QPushButton(frame_41);
        pushButtonLowLevelBridgeUnlock->setObjectName(QString::fromUtf8("pushButtonLowLevelBridgeUnlock"));
        pushButtonLowLevelBridgeUnlock->setMinimumSize(QSize(80, 50));
        pushButtonLowLevelBridgeUnlock->setFont(font5);

        verticalLayout_9->addWidget(pushButtonLowLevelBridgeUnlock);


        gridLayout->addWidget(frame_41, 1, 0, 1, 1);

        frame_3 = new QFrame(pageLowLevel);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font4);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        pushButtonLowLevelPowerOff = new QPushButton(frame_3);
        pushButtonLowLevelPowerOff->setObjectName(QString::fromUtf8("pushButtonLowLevelPowerOff"));
        pushButtonLowLevelPowerOff->setMinimumSize(QSize(80, 50));
        pushButtonLowLevelPowerOff->setFont(font5);

        verticalLayout_4->addWidget(pushButtonLowLevelPowerOff);

        pushButtonLowLevelPowerOnDot = new QPushButton(frame_3);
        pushButtonLowLevelPowerOnDot->setObjectName(QString::fromUtf8("pushButtonLowLevelPowerOnDot"));
        pushButtonLowLevelPowerOnDot->setMinimumSize(QSize(80, 50));
        pushButtonLowLevelPowerOnDot->setFont(font5);

        verticalLayout_4->addWidget(pushButtonLowLevelPowerOnDot);

        pushButtonLowLevelPowerOnNoDot = new QPushButton(frame_3);
        pushButtonLowLevelPowerOnNoDot->setObjectName(QString::fromUtf8("pushButtonLowLevelPowerOnNoDot"));
        pushButtonLowLevelPowerOnNoDot->setMinimumSize(QSize(80, 50));
        pushButtonLowLevelPowerOnNoDot->setFont(font5);

        verticalLayout_4->addWidget(pushButtonLowLevelPowerOnNoDot);


        gridLayout->addWidget(frame_3, 1, 1, 1, 1);

        frame_5 = new QFrame(pageLowLevel);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_5);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_6 = new QLabel(frame_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font4);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_5);

        pushButtonLowLevelInit = new QPushButton(frame_5);
        pushButtonLowLevelInit->setObjectName(QString::fromUtf8("pushButtonLowLevelInit"));
        pushButtonLowLevelInit->setMinimumSize(QSize(80, 50));
        pushButtonLowLevelInit->setFont(font5);

        verticalLayout_10->addWidget(pushButtonLowLevelInit);

        LowLevelTurnPlusOne = new QPushButton(frame_5);
        LowLevelTurnPlusOne->setObjectName(QString::fromUtf8("LowLevelTurnPlusOne"));
        LowLevelTurnPlusOne->setMinimumSize(QSize(80, 50));
        LowLevelTurnPlusOne->setFont(font5);

        verticalLayout_10->addWidget(LowLevelTurnPlusOne);

        pushButtonLowLevelTurnMinusOne = new QPushButton(frame_5);
        pushButtonLowLevelTurnMinusOne->setObjectName(QString::fromUtf8("pushButtonLowLevelTurnMinusOne"));
        pushButtonLowLevelTurnMinusOne->setMinimumSize(QSize(80, 50));
        pushButtonLowLevelTurnMinusOne->setFont(font5);

        verticalLayout_10->addWidget(pushButtonLowLevelTurnMinusOne);

        pushButtonLowLevelTurn180 = new QPushButton(frame_5);
        pushButtonLowLevelTurn180->setObjectName(QString::fromUtf8("pushButtonLowLevelTurn180"));
        pushButtonLowLevelTurn180->setMinimumSize(QSize(80, 50));
        pushButtonLowLevelTurn180->setFont(font5);

        verticalLayout_10->addWidget(pushButtonLowLevelTurn180);


        gridLayout->addWidget(frame_5, 1, 2, 1, 1);

        frame_6 = new QFrame(pageLowLevel);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy);
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_7 = new QLabel(frame_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font4);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_7);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButtonLowLevelReset = new QPushButton(frame_6);
        pushButtonLowLevelReset->setObjectName(QString::fromUtf8("pushButtonLowLevelReset"));
        pushButtonLowLevelReset->setMinimumSize(QSize(80, 50));
        pushButtonLowLevelReset->setFont(font5);

        horizontalLayout_5->addWidget(pushButtonLowLevelReset);

        pushButtonLowLevelSave = new QPushButton(frame_6);
        pushButtonLowLevelSave->setObjectName(QString::fromUtf8("pushButtonLowLevelSave"));
        pushButtonLowLevelSave->setMinimumSize(QSize(80, 50));
        pushButtonLowLevelSave->setFont(font5);

        horizontalLayout_5->addWidget(pushButtonLowLevelSave);


        verticalLayout_11->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButtonCW1_0 = new QPushButton(frame_6);
        pushButtonCW1_0->setObjectName(QString::fromUtf8("pushButtonCW1_0"));
        pushButtonCW1_0->setMinimumSize(QSize(80, 50));
        pushButtonCW1_0->setFont(font5);

        horizontalLayout_6->addWidget(pushButtonCW1_0);

        pushButtonCW0_1 = new QPushButton(frame_6);
        pushButtonCW0_1->setObjectName(QString::fromUtf8("pushButtonCW0_1"));
        pushButtonCW0_1->setMinimumSize(QSize(80, 50));
        pushButtonCW0_1->setFont(font5);

        horizontalLayout_6->addWidget(pushButtonCW0_1);


        verticalLayout_11->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButtonCCW1_0 = new QPushButton(frame_6);
        pushButtonCCW1_0->setObjectName(QString::fromUtf8("pushButtonCCW1_0"));
        pushButtonCCW1_0->setMinimumSize(QSize(80, 50));
        pushButtonCCW1_0->setFont(font5);

        horizontalLayout_7->addWidget(pushButtonCCW1_0);

        pushButtonCCW0_1 = new QPushButton(frame_6);
        pushButtonCCW0_1->setObjectName(QString::fromUtf8("pushButtonCCW0_1"));
        pushButtonCCW0_1->setMinimumSize(QSize(80, 50));
        pushButtonCCW0_1->setFont(font5);

        horizontalLayout_7->addWidget(pushButtonCCW0_1);


        verticalLayout_11->addLayout(horizontalLayout_7);


        gridLayout->addWidget(frame_6, 1, 3, 1, 2);


        verticalLayout_2->addLayout(gridLayout);

        stackedWidget->addWidget(pageLowLevel);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonPageMain->setText(QCoreApplication::translate("MainWindow", "Main", nullptr));
        pushButtonPageLowLevel->setText(QCoreApplication::translate("MainWindow", "Low Level", nullptr));
        pushButtonTurn->setText(QString());
        pushButton_8->setText(QString());
        pushButton_7->setText(QString());
        pushButton_6->setText(QString());
        pushButtonMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButtonInit->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));
        pushButton_9->setText(QString());
        pushButtonPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Last Action", nullptr));
        labelLowLevelLastAction->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Homing offset", nullptr));
        labelLowLevelHomeOffset->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Axis Position", nullptr));
        labelLowLevelAxisPosition->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Logical Position", nullptr));
        labelLowLevelLogicalPosition->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Last Error", nullptr));
        labelLowLevelLastError->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Bridge", nullptr));
        pushButtonLowLevelBridgeLock->setText(QCoreApplication::translate("MainWindow", "Lock", nullptr));
        pushButtonLowLevelBridgeUnlock->setText(QCoreApplication::translate("MainWindow", "Unlock", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));
        pushButtonLowLevelPowerOff->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        pushButtonLowLevelPowerOnDot->setText(QCoreApplication::translate("MainWindow", "On Dot", nullptr));
        pushButtonLowLevelPowerOnNoDot->setText(QCoreApplication::translate("MainWindow", "On No Dot", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Logical", nullptr));
        pushButtonLowLevelInit->setText(QCoreApplication::translate("MainWindow", "Init", nullptr));
        LowLevelTurnPlusOne->setText(QCoreApplication::translate("MainWindow", "+1", nullptr));
        pushButtonLowLevelTurnMinusOne->setText(QCoreApplication::translate("MainWindow", "-1", nullptr));
        pushButtonLowLevelTurn180->setText(QCoreApplication::translate("MainWindow", "180\302\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Calibration", nullptr));
        pushButtonLowLevelReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        pushButtonLowLevelSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButtonCW1_0->setText(QCoreApplication::translate("MainWindow", "CW 1.0", nullptr));
        pushButtonCW0_1->setText(QCoreApplication::translate("MainWindow", "CW 0.1", nullptr));
        pushButtonCCW1_0->setText(QCoreApplication::translate("MainWindow", "CCW 1.0", nullptr));
        pushButtonCCW0_1->setText(QCoreApplication::translate("MainWindow", "CCW 0.1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

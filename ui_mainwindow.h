/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *lb_33;
    QSlider *slider_33;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_12;
    QLabel *lb_63;
    QSlider *slider_63;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_17;
    QLabel *lb_87;
    QSlider *slider_87;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_11;
    QLabel *lb_125;
    QSlider *slider_125;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *lb_175;
    QSlider *slider_175;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_14;
    QLabel *lb_250;
    QSlider *slider_250;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_21;
    QLabel *lb_350;
    QSlider *slider_350;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_9;
    QLabel *lb_500;
    QSlider *slider_500;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_16;
    QLabel *lb_700;
    QSlider *slider_700;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_20;
    QLabel *lb_1000;
    QSlider *slider_1000;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_15;
    QLabel *lb_1400;
    QSlider *slider_1400;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_8;
    QLabel *lb_2000;
    QSlider *slider_2000;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_7;
    QLabel *lb_2800;
    QSlider *slider_2800;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_6;
    QLabel *lb_4000;
    QSlider *slider_4000;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_19;
    QLabel *lb_5600;
    QSlider *slider_5600;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_18;
    QLabel *lb_8000;
    QSlider *slider_8000;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_13;
    QLabel *lb_11200;
    QSlider *slider_11200;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_5;
    QLabel *lb_16000;
    QSlider *slider_16000;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lb_volume;
    QSpinBox *sb_volume;
    QLabel *lb_setDevice;
    QComboBox *cb_device;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_Play;
    QPushButton *btn_Pause;
    QPushButton *btn_Stop;
    QPushButton *btn_Next;
    QPushButton *btn_Previous;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_SavePlayList;
    QPushButton *btn_OpenPlayList;
    QPushButton *pushButton;
    QPushButton *btn_OpenFile;
    QListView *listView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(510, 514);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lb_33 = new QLabel(centralWidget);
        lb_33->setObjectName(QStringLiteral("lb_33"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lb_33->sizePolicy().hasHeightForWidth());
        lb_33->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(lb_33);

        slider_33 = new QSlider(centralWidget);
        slider_33->setObjectName(QStringLiteral("slider_33"));
        sizePolicy.setHeightForWidth(slider_33->sizePolicy().hasHeightForWidth());
        slider_33->setSizePolicy(sizePolicy);
        slider_33->setMinimum(-15);
        slider_33->setMaximum(15);
        slider_33->setPageStep(1);
        slider_33->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(slider_33);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(label_2);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        lb_63 = new QLabel(centralWidget);
        lb_63->setObjectName(QStringLiteral("lb_63"));
        sizePolicy1.setHeightForWidth(lb_63->sizePolicy().hasHeightForWidth());
        lb_63->setSizePolicy(sizePolicy1);

        verticalLayout_12->addWidget(lb_63);

        slider_63 = new QSlider(centralWidget);
        slider_63->setObjectName(QStringLiteral("slider_63"));
        sizePolicy.setHeightForWidth(slider_63->sizePolicy().hasHeightForWidth());
        slider_63->setSizePolicy(sizePolicy);
        slider_63->setMinimum(-15);
        slider_63->setMaximum(15);
        slider_63->setPageStep(1);
        slider_63->setOrientation(Qt::Vertical);

        verticalLayout_12->addWidget(slider_63);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout_12->addWidget(label_3);


        horizontalLayout_4->addLayout(verticalLayout_12);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        lb_87 = new QLabel(centralWidget);
        lb_87->setObjectName(QStringLiteral("lb_87"));
        sizePolicy1.setHeightForWidth(lb_87->sizePolicy().hasHeightForWidth());
        lb_87->setSizePolicy(sizePolicy1);

        verticalLayout_17->addWidget(lb_87);

        slider_87 = new QSlider(centralWidget);
        slider_87->setObjectName(QStringLiteral("slider_87"));
        sizePolicy.setHeightForWidth(slider_87->sizePolicy().hasHeightForWidth());
        slider_87->setSizePolicy(sizePolicy);
        slider_87->setMinimum(-15);
        slider_87->setMaximum(15);
        slider_87->setPageStep(1);
        slider_87->setOrientation(Qt::Vertical);

        verticalLayout_17->addWidget(slider_87);

        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);

        verticalLayout_17->addWidget(label_18);


        horizontalLayout_4->addLayout(verticalLayout_17);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        lb_125 = new QLabel(centralWidget);
        lb_125->setObjectName(QStringLiteral("lb_125"));
        sizePolicy1.setHeightForWidth(lb_125->sizePolicy().hasHeightForWidth());
        lb_125->setSizePolicy(sizePolicy1);

        verticalLayout_11->addWidget(lb_125);

        slider_125 = new QSlider(centralWidget);
        slider_125->setObjectName(QStringLiteral("slider_125"));
        sizePolicy.setHeightForWidth(slider_125->sizePolicy().hasHeightForWidth());
        slider_125->setSizePolicy(sizePolicy);
        slider_125->setMinimum(-15);
        slider_125->setMaximum(15);
        slider_125->setPageStep(1);
        slider_125->setOrientation(Qt::Vertical);

        verticalLayout_11->addWidget(slider_125);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        verticalLayout_11->addWidget(label_4);


        horizontalLayout_4->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        lb_175 = new QLabel(centralWidget);
        lb_175->setObjectName(QStringLiteral("lb_175"));
        sizePolicy1.setHeightForWidth(lb_175->sizePolicy().hasHeightForWidth());
        lb_175->setSizePolicy(sizePolicy1);

        verticalLayout_10->addWidget(lb_175);

        slider_175 = new QSlider(centralWidget);
        slider_175->setObjectName(QStringLiteral("slider_175"));
        sizePolicy.setHeightForWidth(slider_175->sizePolicy().hasHeightForWidth());
        slider_175->setSizePolicy(sizePolicy);
        slider_175->setMinimum(-15);
        slider_175->setMaximum(15);
        slider_175->setPageStep(1);
        slider_175->setOrientation(Qt::Vertical);

        verticalLayout_10->addWidget(slider_175);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        verticalLayout_10->addWidget(label_5);


        horizontalLayout_4->addLayout(verticalLayout_10);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        lb_250 = new QLabel(centralWidget);
        lb_250->setObjectName(QStringLiteral("lb_250"));
        sizePolicy1.setHeightForWidth(lb_250->sizePolicy().hasHeightForWidth());
        lb_250->setSizePolicy(sizePolicy1);

        verticalLayout_14->addWidget(lb_250);

        slider_250 = new QSlider(centralWidget);
        slider_250->setObjectName(QStringLiteral("slider_250"));
        sizePolicy.setHeightForWidth(slider_250->sizePolicy().hasHeightForWidth());
        slider_250->setSizePolicy(sizePolicy);
        slider_250->setMinimum(-15);
        slider_250->setMaximum(15);
        slider_250->setPageStep(1);
        slider_250->setOrientation(Qt::Vertical);

        verticalLayout_14->addWidget(slider_250);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        verticalLayout_14->addWidget(label_6);


        horizontalLayout_4->addLayout(verticalLayout_14);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        lb_350 = new QLabel(centralWidget);
        lb_350->setObjectName(QStringLiteral("lb_350"));
        sizePolicy1.setHeightForWidth(lb_350->sizePolicy().hasHeightForWidth());
        lb_350->setSizePolicy(sizePolicy1);

        verticalLayout_21->addWidget(lb_350);

        slider_350 = new QSlider(centralWidget);
        slider_350->setObjectName(QStringLiteral("slider_350"));
        sizePolicy.setHeightForWidth(slider_350->sizePolicy().hasHeightForWidth());
        slider_350->setSizePolicy(sizePolicy);
        slider_350->setMinimum(-15);
        slider_350->setMaximum(15);
        slider_350->setPageStep(1);
        slider_350->setOrientation(Qt::Vertical);

        verticalLayout_21->addWidget(slider_350);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        verticalLayout_21->addWidget(label_7);


        horizontalLayout_4->addLayout(verticalLayout_21);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        lb_500 = new QLabel(centralWidget);
        lb_500->setObjectName(QStringLiteral("lb_500"));
        sizePolicy1.setHeightForWidth(lb_500->sizePolicy().hasHeightForWidth());
        lb_500->setSizePolicy(sizePolicy1);

        verticalLayout_9->addWidget(lb_500);

        slider_500 = new QSlider(centralWidget);
        slider_500->setObjectName(QStringLiteral("slider_500"));
        sizePolicy.setHeightForWidth(slider_500->sizePolicy().hasHeightForWidth());
        slider_500->setSizePolicy(sizePolicy);
        slider_500->setMinimum(-15);
        slider_500->setMaximum(15);
        slider_500->setPageStep(1);
        slider_500->setOrientation(Qt::Vertical);

        verticalLayout_9->addWidget(slider_500);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        verticalLayout_9->addWidget(label_8);


        horizontalLayout_4->addLayout(verticalLayout_9);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        lb_700 = new QLabel(centralWidget);
        lb_700->setObjectName(QStringLiteral("lb_700"));
        sizePolicy1.setHeightForWidth(lb_700->sizePolicy().hasHeightForWidth());
        lb_700->setSizePolicy(sizePolicy1);

        verticalLayout_16->addWidget(lb_700);

        slider_700 = new QSlider(centralWidget);
        slider_700->setObjectName(QStringLiteral("slider_700"));
        sizePolicy.setHeightForWidth(slider_700->sizePolicy().hasHeightForWidth());
        slider_700->setSizePolicy(sizePolicy);
        slider_700->setMinimum(-15);
        slider_700->setMaximum(15);
        slider_700->setPageStep(1);
        slider_700->setOrientation(Qt::Vertical);

        verticalLayout_16->addWidget(slider_700);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        verticalLayout_16->addWidget(label_9);


        horizontalLayout_4->addLayout(verticalLayout_16);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        lb_1000 = new QLabel(centralWidget);
        lb_1000->setObjectName(QStringLiteral("lb_1000"));
        sizePolicy1.setHeightForWidth(lb_1000->sizePolicy().hasHeightForWidth());
        lb_1000->setSizePolicy(sizePolicy1);

        verticalLayout_20->addWidget(lb_1000);

        slider_1000 = new QSlider(centralWidget);
        slider_1000->setObjectName(QStringLiteral("slider_1000"));
        sizePolicy.setHeightForWidth(slider_1000->sizePolicy().hasHeightForWidth());
        slider_1000->setSizePolicy(sizePolicy);
        slider_1000->setMinimum(-15);
        slider_1000->setMaximum(15);
        slider_1000->setPageStep(1);
        slider_1000->setOrientation(Qt::Vertical);

        verticalLayout_20->addWidget(slider_1000);

        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);

        verticalLayout_20->addWidget(label_19);


        horizontalLayout_4->addLayout(verticalLayout_20);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        lb_1400 = new QLabel(centralWidget);
        lb_1400->setObjectName(QStringLiteral("lb_1400"));
        sizePolicy1.setHeightForWidth(lb_1400->sizePolicy().hasHeightForWidth());
        lb_1400->setSizePolicy(sizePolicy1);

        verticalLayout_15->addWidget(lb_1400);

        slider_1400 = new QSlider(centralWidget);
        slider_1400->setObjectName(QStringLiteral("slider_1400"));
        sizePolicy.setHeightForWidth(slider_1400->sizePolicy().hasHeightForWidth());
        slider_1400->setSizePolicy(sizePolicy);
        slider_1400->setMinimum(-15);
        slider_1400->setMaximum(15);
        slider_1400->setPageStep(1);
        slider_1400->setOrientation(Qt::Vertical);

        verticalLayout_15->addWidget(slider_1400);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        verticalLayout_15->addWidget(label_10);


        horizontalLayout_4->addLayout(verticalLayout_15);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        lb_2000 = new QLabel(centralWidget);
        lb_2000->setObjectName(QStringLiteral("lb_2000"));
        sizePolicy1.setHeightForWidth(lb_2000->sizePolicy().hasHeightForWidth());
        lb_2000->setSizePolicy(sizePolicy1);

        verticalLayout_8->addWidget(lb_2000);

        slider_2000 = new QSlider(centralWidget);
        slider_2000->setObjectName(QStringLiteral("slider_2000"));
        sizePolicy.setHeightForWidth(slider_2000->sizePolicy().hasHeightForWidth());
        slider_2000->setSizePolicy(sizePolicy);
        slider_2000->setMinimum(-15);
        slider_2000->setMaximum(15);
        slider_2000->setPageStep(1);
        slider_2000->setOrientation(Qt::Vertical);

        verticalLayout_8->addWidget(slider_2000);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        verticalLayout_8->addWidget(label_11);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        lb_2800 = new QLabel(centralWidget);
        lb_2800->setObjectName(QStringLiteral("lb_2800"));
        sizePolicy1.setHeightForWidth(lb_2800->sizePolicy().hasHeightForWidth());
        lb_2800->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(lb_2800);

        slider_2800 = new QSlider(centralWidget);
        slider_2800->setObjectName(QStringLiteral("slider_2800"));
        sizePolicy.setHeightForWidth(slider_2800->sizePolicy().hasHeightForWidth());
        slider_2800->setSizePolicy(sizePolicy);
        slider_2800->setMinimum(-15);
        slider_2800->setMaximum(15);
        slider_2800->setPageStep(1);
        slider_2800->setOrientation(Qt::Vertical);

        verticalLayout_7->addWidget(slider_2800);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(label_12);


        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        lb_4000 = new QLabel(centralWidget);
        lb_4000->setObjectName(QStringLiteral("lb_4000"));
        sizePolicy1.setHeightForWidth(lb_4000->sizePolicy().hasHeightForWidth());
        lb_4000->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(lb_4000);

        slider_4000 = new QSlider(centralWidget);
        slider_4000->setObjectName(QStringLiteral("slider_4000"));
        sizePolicy.setHeightForWidth(slider_4000->sizePolicy().hasHeightForWidth());
        slider_4000->setSizePolicy(sizePolicy);
        slider_4000->setMinimum(-15);
        slider_4000->setMaximum(15);
        slider_4000->setPageStep(1);
        slider_4000->setOrientation(Qt::Vertical);

        verticalLayout_6->addWidget(slider_4000);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(label_13);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        lb_5600 = new QLabel(centralWidget);
        lb_5600->setObjectName(QStringLiteral("lb_5600"));
        sizePolicy1.setHeightForWidth(lb_5600->sizePolicy().hasHeightForWidth());
        lb_5600->setSizePolicy(sizePolicy1);

        verticalLayout_19->addWidget(lb_5600);

        slider_5600 = new QSlider(centralWidget);
        slider_5600->setObjectName(QStringLiteral("slider_5600"));
        sizePolicy.setHeightForWidth(slider_5600->sizePolicy().hasHeightForWidth());
        slider_5600->setSizePolicy(sizePolicy);
        slider_5600->setMinimum(-15);
        slider_5600->setMaximum(15);
        slider_5600->setPageStep(1);
        slider_5600->setOrientation(Qt::Vertical);

        verticalLayout_19->addWidget(slider_5600);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);

        verticalLayout_19->addWidget(label_15);


        horizontalLayout_4->addLayout(verticalLayout_19);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        lb_8000 = new QLabel(centralWidget);
        lb_8000->setObjectName(QStringLiteral("lb_8000"));
        sizePolicy1.setHeightForWidth(lb_8000->sizePolicy().hasHeightForWidth());
        lb_8000->setSizePolicy(sizePolicy1);

        verticalLayout_18->addWidget(lb_8000);

        slider_8000 = new QSlider(centralWidget);
        slider_8000->setObjectName(QStringLiteral("slider_8000"));
        sizePolicy.setHeightForWidth(slider_8000->sizePolicy().hasHeightForWidth());
        slider_8000->setSizePolicy(sizePolicy);
        slider_8000->setMinimum(-15);
        slider_8000->setMaximum(15);
        slider_8000->setPageStep(1);
        slider_8000->setOrientation(Qt::Vertical);

        verticalLayout_18->addWidget(slider_8000);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        verticalLayout_18->addWidget(label_16);


        horizontalLayout_4->addLayout(verticalLayout_18);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        lb_11200 = new QLabel(centralWidget);
        lb_11200->setObjectName(QStringLiteral("lb_11200"));
        sizePolicy1.setHeightForWidth(lb_11200->sizePolicy().hasHeightForWidth());
        lb_11200->setSizePolicy(sizePolicy1);

        verticalLayout_13->addWidget(lb_11200);

        slider_11200 = new QSlider(centralWidget);
        slider_11200->setObjectName(QStringLiteral("slider_11200"));
        sizePolicy.setHeightForWidth(slider_11200->sizePolicy().hasHeightForWidth());
        slider_11200->setSizePolicy(sizePolicy);
        slider_11200->setMinimum(-15);
        slider_11200->setMaximum(15);
        slider_11200->setPageStep(1);
        slider_11200->setOrientation(Qt::Vertical);

        verticalLayout_13->addWidget(slider_11200);

        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);

        verticalLayout_13->addWidget(label_17);


        horizontalLayout_4->addLayout(verticalLayout_13);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lb_16000 = new QLabel(centralWidget);
        lb_16000->setObjectName(QStringLiteral("lb_16000"));
        sizePolicy1.setHeightForWidth(lb_16000->sizePolicy().hasHeightForWidth());
        lb_16000->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(lb_16000);

        slider_16000 = new QSlider(centralWidget);
        slider_16000->setObjectName(QStringLiteral("slider_16000"));
        sizePolicy.setHeightForWidth(slider_16000->sizePolicy().hasHeightForWidth());
        slider_16000->setSizePolicy(sizePolicy);
        slider_16000->setMinimum(-15);
        slider_16000->setMaximum(15);
        slider_16000->setPageStep(1);
        slider_16000->setOrientation(Qt::Vertical);

        verticalLayout_5->addWidget(slider_16000);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(label_14);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lb_volume = new QLabel(centralWidget);
        lb_volume->setObjectName(QStringLiteral("lb_volume"));
        sizePolicy.setHeightForWidth(lb_volume->sizePolicy().hasHeightForWidth());
        lb_volume->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lb_volume);

        sb_volume = new QSpinBox(centralWidget);
        sb_volume->setObjectName(QStringLiteral("sb_volume"));
        sizePolicy.setHeightForWidth(sb_volume->sizePolicy().hasHeightForWidth());
        sb_volume->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(sb_volume);

        lb_setDevice = new QLabel(centralWidget);
        lb_setDevice->setObjectName(QStringLiteral("lb_setDevice"));
        sizePolicy.setHeightForWidth(lb_setDevice->sizePolicy().hasHeightForWidth());
        lb_setDevice->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lb_setDevice);

        cb_device = new QComboBox(centralWidget);
        cb_device->setObjectName(QStringLiteral("cb_device"));

        horizontalLayout_3->addWidget(cb_device);


        verticalLayout->addLayout(horizontalLayout_3);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(100);

        verticalLayout->addWidget(progressBar);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_Play = new QPushButton(centralWidget);
        btn_Play->setObjectName(QStringLiteral("btn_Play"));

        horizontalLayout_2->addWidget(btn_Play);

        btn_Pause = new QPushButton(centralWidget);
        btn_Pause->setObjectName(QStringLiteral("btn_Pause"));

        horizontalLayout_2->addWidget(btn_Pause);

        btn_Stop = new QPushButton(centralWidget);
        btn_Stop->setObjectName(QStringLiteral("btn_Stop"));

        horizontalLayout_2->addWidget(btn_Stop);

        btn_Next = new QPushButton(centralWidget);
        btn_Next->setObjectName(QStringLiteral("btn_Next"));

        horizontalLayout_2->addWidget(btn_Next);

        btn_Previous = new QPushButton(centralWidget);
        btn_Previous->setObjectName(QStringLiteral("btn_Previous"));

        horizontalLayout_2->addWidget(btn_Previous);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_SavePlayList = new QPushButton(centralWidget);
        btn_SavePlayList->setObjectName(QStringLiteral("btn_SavePlayList"));

        horizontalLayout->addWidget(btn_SavePlayList);

        btn_OpenPlayList = new QPushButton(centralWidget);
        btn_OpenPlayList->setObjectName(QStringLiteral("btn_OpenPlayList"));

        horizontalLayout->addWidget(btn_OpenPlayList);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        btn_OpenFile = new QPushButton(centralWidget);
        btn_OpenFile->setObjectName(QStringLiteral("btn_OpenFile"));

        horizontalLayout->addWidget(btn_OpenFile);


        verticalLayout->addLayout(horizontalLayout);

        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 510, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(slider_33, SIGNAL(valueChanged(int)), lb_33, SLOT(setNum(int)));
        QObject::connect(slider_63, SIGNAL(valueChanged(int)), lb_63, SLOT(setNum(int)));
        QObject::connect(slider_87, SIGNAL(valueChanged(int)), lb_87, SLOT(setNum(int)));
        QObject::connect(slider_125, SIGNAL(valueChanged(int)), lb_125, SLOT(setNum(int)));
        QObject::connect(slider_175, SIGNAL(valueChanged(int)), lb_175, SLOT(setNum(int)));
        QObject::connect(slider_250, SIGNAL(valueChanged(int)), lb_250, SLOT(setNum(int)));
        QObject::connect(slider_350, SIGNAL(valueChanged(int)), lb_350, SLOT(setNum(int)));
        QObject::connect(slider_500, SIGNAL(valueChanged(int)), lb_500, SLOT(setNum(int)));
        QObject::connect(slider_700, SIGNAL(valueChanged(int)), lb_700, SLOT(setNum(int)));
        QObject::connect(slider_1000, SIGNAL(valueChanged(int)), lb_1000, SLOT(setNum(int)));
        QObject::connect(slider_1400, SIGNAL(valueChanged(int)), lb_1400, SLOT(setNum(int)));
        QObject::connect(slider_2000, SIGNAL(valueChanged(int)), lb_2000, SLOT(setNum(int)));
        QObject::connect(slider_2800, SIGNAL(valueChanged(int)), lb_2800, SLOT(setNum(int)));
        QObject::connect(slider_4000, SIGNAL(valueChanged(int)), lb_4000, SLOT(setNum(int)));
        QObject::connect(slider_5600, SIGNAL(valueChanged(int)), lb_5600, SLOT(setNum(int)));
        QObject::connect(slider_8000, SIGNAL(valueChanged(int)), lb_8000, SLOT(setNum(int)));
        QObject::connect(slider_11200, SIGNAL(valueChanged(int)), lb_11200, SLOT(setNum(int)));
        QObject::connect(slider_16000, SIGNAL(valueChanged(int)), lb_16000, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lb_33->setText(QApplication::translate("MainWindow", "0", 0));
        label_2->setText(QApplication::translate("MainWindow", "31", 0));
        lb_63->setText(QApplication::translate("MainWindow", "0", 0));
        label_3->setText(QApplication::translate("MainWindow", "63", 0));
        lb_87->setText(QApplication::translate("MainWindow", "0", 0));
        label_18->setText(QApplication::translate("MainWindow", "87", 0));
        lb_125->setText(QApplication::translate("MainWindow", "0", 0));
        label_4->setText(QApplication::translate("MainWindow", "125", 0));
        lb_175->setText(QApplication::translate("MainWindow", "0", 0));
        label_5->setText(QApplication::translate("MainWindow", "175", 0));
        lb_250->setText(QApplication::translate("MainWindow", "0", 0));
        label_6->setText(QApplication::translate("MainWindow", "250", 0));
        lb_350->setText(QApplication::translate("MainWindow", "0", 0));
        label_7->setText(QApplication::translate("MainWindow", "350", 0));
        lb_500->setText(QApplication::translate("MainWindow", "0", 0));
        label_8->setText(QApplication::translate("MainWindow", "500", 0));
        lb_700->setText(QApplication::translate("MainWindow", "0", 0));
        label_9->setText(QApplication::translate("MainWindow", "700", 0));
        lb_1000->setText(QApplication::translate("MainWindow", "0", 0));
        label_19->setText(QApplication::translate("MainWindow", "1KHz", 0));
        lb_1400->setText(QApplication::translate("MainWindow", "0", 0));
        label_10->setText(QApplication::translate("MainWindow", "1.4", 0));
        lb_2000->setText(QApplication::translate("MainWindow", "0", 0));
        label_11->setText(QApplication::translate("MainWindow", "2.0", 0));
        lb_2800->setText(QApplication::translate("MainWindow", "0", 0));
        label_12->setText(QApplication::translate("MainWindow", "2.8", 0));
        lb_4000->setText(QApplication::translate("MainWindow", "0", 0));
        label_13->setText(QApplication::translate("MainWindow", "4.0", 0));
        lb_5600->setText(QApplication::translate("MainWindow", "0", 0));
        label_15->setText(QApplication::translate("MainWindow", "5.6", 0));
        lb_8000->setText(QApplication::translate("MainWindow", "0", 0));
        label_16->setText(QApplication::translate("MainWindow", "8", 0));
        lb_11200->setText(QApplication::translate("MainWindow", "0", 0));
        label_17->setText(QApplication::translate("MainWindow", "11.2", 0));
        lb_16000->setText(QApplication::translate("MainWindow", "0", 0));
        label_14->setText(QApplication::translate("MainWindow", "16", 0));
        lb_volume->setText(QApplication::translate("MainWindow", "Volume", 0));
        lb_setDevice->setText(QApplication::translate("MainWindow", "Set Device", 0));
        progressBar->setFormat(QString());
        btn_Play->setText(QApplication::translate("MainWindow", "Play", 0));
        btn_Pause->setText(QApplication::translate("MainWindow", "Pause", 0));
        btn_Stop->setText(QApplication::translate("MainWindow", "Stop", 0));
        btn_Next->setText(QApplication::translate("MainWindow", "Next", 0));
        btn_Previous->setText(QApplication::translate("MainWindow", "Previous", 0));
        btn_SavePlayList->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\202\320\265\320\272\321\203\321\211\320\270\320\271 \320\277\320\273\321\215\320\271\320\273\320\270\321\201\321\202  ", 0));
        btn_OpenPlayList->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\320\273\321\215\320\271\320\273\320\270\321\201\321\202", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        btn_OpenFile->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

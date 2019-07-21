/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelView_2;
    QLabel *labelView;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonPlay;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *cbProcessImage;
    QHBoxLayout *horizontalLayout_2;
    QSlider *hsldThreshold;
    QLabel *lblThresholdValue;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnSendUDP;
    QGroupBox *Qualidade;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *sboxAreaRef;
    QSpinBox *sboxAreaOffset;
    QSpinBox *sboxPosition;
    QSpinBox *sboxPontoOK;
    QLabel *lbl_Status;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *lblPontosOK;
    QLabel *lblPontosNOK;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(888, 564);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 761, 311));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelView_2 = new QLabel(layoutWidget);
        labelView_2->setObjectName(QStringLiteral("labelView_2"));
        labelView_2->setStyleSheet(QStringLiteral("border: 1px solid;"));
        labelView_2->setScaledContents(true);

        horizontalLayout->addWidget(labelView_2);

        labelView = new QLabel(layoutWidget);
        labelView->setObjectName(QStringLiteral("labelView"));
        labelView->setStyleSheet(QStringLiteral("border: 1px solid;"));
        labelView->setScaledContents(true);

        horizontalLayout->addWidget(labelView);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 340, 271, 151));
        QFont font;
        font.setFamily(QStringLiteral("Nirmala UI"));
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(false);
        groupBox_3->setFont(font);
        groupBox_3->setTitle(QStringLiteral("Controlo"));
        groupBox_3->setFlat(false);
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 251, 111));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonPlay = new QPushButton(layoutWidget1);
        pushButtonPlay->setObjectName(QStringLiteral("pushButtonPlay"));

        horizontalLayout_5->addWidget(pushButtonPlay);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        cbProcessImage = new QCheckBox(layoutWidget1);
        cbProcessImage->setObjectName(QStringLiteral("cbProcessImage"));

        horizontalLayout_14->addWidget(cbProcessImage);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        hsldThreshold = new QSlider(layoutWidget1);
        hsldThreshold->setObjectName(QStringLiteral("hsldThreshold"));
        hsldThreshold->setMaximum(255);
        hsldThreshold->setValue(245);
        hsldThreshold->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(hsldThreshold);

        lblThresholdValue = new QLabel(layoutWidget1);
        lblThresholdValue->setObjectName(QStringLiteral("lblThresholdValue"));

        horizontalLayout_2->addWidget(lblThresholdValue);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(290, 340, 121, 151));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 82, 111));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnSendUDP = new QPushButton(horizontalLayoutWidget);
        btnSendUDP->setObjectName(QStringLiteral("btnSendUDP"));
        btnSendUDP->setEnabled(true);

        horizontalLayout_3->addWidget(btnSendUDP);

        Qualidade = new QGroupBox(centralWidget);
        Qualidade->setObjectName(QStringLiteral("Qualidade"));
        Qualidade->setGeometry(QRect(420, 340, 301, 151));
        label = new QLabel(Qualidade);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 81, 16));
        label_2 = new QLabel(Qualidade);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 81, 16));
        label_3 = new QLabel(Qualidade);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 81, 16));
        label_4 = new QLabel(Qualidade);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 120, 71, 16));
        sboxAreaRef = new QSpinBox(Qualidade);
        sboxAreaRef->setObjectName(QStringLiteral("sboxAreaRef"));
        sboxAreaRef->setGeometry(QRect(120, 30, 171, 22));
        sboxAreaRef->setValue(25);
        sboxAreaOffset = new QSpinBox(Qualidade);
        sboxAreaOffset->setObjectName(QStringLiteral("sboxAreaOffset"));
        sboxAreaOffset->setGeometry(QRect(120, 60, 171, 22));
        sboxAreaOffset->setValue(10);
        sboxPosition = new QSpinBox(Qualidade);
        sboxPosition->setObjectName(QStringLiteral("sboxPosition"));
        sboxPosition->setGeometry(QRect(120, 90, 171, 22));
        sboxPosition->setValue(20);
        sboxPontoOK = new QSpinBox(Qualidade);
        sboxPontoOK->setObjectName(QStringLiteral("sboxPontoOK"));
        sboxPontoOK->setGeometry(QRect(120, 120, 171, 22));
        sboxPontoOK->setValue(5);
        lbl_Status = new QLabel(centralWidget);
        lbl_Status->setObjectName(QStringLiteral("lbl_Status"));
        lbl_Status->setGeometry(QRect(740, 410, 111, 71));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        lbl_Status->setFont(font1);
        lbl_Status->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(730, 360, 61, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(730, 380, 61, 16));
        lblPontosOK = new QLabel(centralWidget);
        lblPontosOK->setObjectName(QStringLiteral("lblPontosOK"));
        lblPontosOK->setGeometry(QRect(800, 360, 31, 16));
        lblPontosNOK = new QLabel(centralWidget);
        lblPontosNOK->setObjectName(QStringLiteral("lblPontosNOK"));
        lblPontosNOK->setGeometry(QRect(800, 380, 41, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 888, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Laborat\303\263rios Integrados 2", Q_NULLPTR));
        labelView_2->setText(QString());
        labelView->setText(QString());
#ifndef QT_NO_STATUSTIP
        groupBox_3->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButtonPlay->setText(QApplication::translate("MainWindow", "Start Camera", Q_NULLPTR));
        cbProcessImage->setText(QApplication::translate("MainWindow", "Enable Process Image", Q_NULLPTR));
        lblThresholdValue->setText(QApplication::translate("MainWindow", "245", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "PLC", Q_NULLPTR));
        btnSendUDP->setText(QApplication::translate("MainWindow", "Enviar", Q_NULLPTR));
        Qualidade->setTitle(QApplication::translate("MainWindow", "Qualidade", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Area Refer\303\252ncia", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Offset Area", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Offset Posi\303\247\303\243o", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Pontos OK", Q_NULLPTR));
        lbl_Status->setText(QApplication::translate("MainWindow", "STATUS", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Pontos OK", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Pontos NOK", Q_NULLPTR));
        lblPontosOK->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lblPontosNOK->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

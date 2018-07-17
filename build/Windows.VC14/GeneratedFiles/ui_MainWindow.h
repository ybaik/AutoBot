/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QRadioButton *windowhandle;
    QRadioButton *adb;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *auto_on;
    QRadioButton *auto_off;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *resolution;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *interval;
    QTextBrowser *log;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *start;
    QPushButton *stop;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(440, 362);
        layoutWidget = new QWidget(MainWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 401, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        windowhandle = new QRadioButton(layoutWidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(windowhandle);
        windowhandle->setObjectName(QStringLiteral("windowhandle"));
        windowhandle->setChecked(true);

        horizontalLayout->addWidget(windowhandle);

        adb = new QRadioButton(layoutWidget);
        buttonGroup->addButton(adb);
        adb->setObjectName(QStringLiteral("adb"));
        adb->setEnabled(true);
        adb->setChecked(false);

        horizontalLayout->addWidget(adb);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        auto_on = new QRadioButton(layoutWidget);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(auto_on);
        auto_on->setObjectName(QStringLiteral("auto_on"));
        auto_on->setChecked(false);

        horizontalLayout_2->addWidget(auto_on);

        auto_off = new QRadioButton(layoutWidget);
        buttonGroup_2->addButton(auto_off);
        auto_off->setObjectName(QStringLiteral("auto_off"));
        auto_off->setChecked(true);

        horizontalLayout_2->addWidget(auto_off);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        resolution = new QComboBox(layoutWidget);
        resolution->addItem(QString());
        resolution->addItem(QString());
        resolution->addItem(QString());
        resolution->addItem(QString());
        resolution->setObjectName(QStringLiteral("resolution"));

        horizontalLayout_3->addWidget(resolution);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        interval = new QLineEdit(layoutWidget);
        interval->setObjectName(QStringLiteral("interval"));
        interval->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(interval);


        verticalLayout->addLayout(horizontalLayout_4);

        log = new QTextBrowser(layoutWidget);
        log->setObjectName(QStringLiteral("log"));

        verticalLayout->addWidget(log);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        start = new QPushButton(layoutWidget);
        start->setObjectName(QStringLiteral("start"));

        horizontalLayout_5->addWidget(start);

        stop = new QPushButton(layoutWidget);
        stop->setObjectName(QStringLiteral("stop"));

        horizontalLayout_5->addWidget(stop);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(MainWindow);
        QObject::connect(start, SIGNAL(clicked()), MainWindow, SLOT(start()));
        QObject::connect(stop, SIGNAL(clicked()), MainWindow, SLOT(stop()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Dialog", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Grabber", nullptr));
        windowhandle->setText(QApplication::translate("MainWindow", "Window Handle", nullptr));
        adb->setText(QApplication::translate("MainWindow", "Adb", nullptr));
        label->setText(QApplication::translate("MainWindow", "Auto mode", nullptr));
        auto_on->setText(QApplication::translate("MainWindow", "On", nullptr));
        auto_off->setText(QApplication::translate("MainWindow", "Off", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Resolution", nullptr));
        resolution->setItemText(0, QApplication::translate("MainWindow", "480x320", nullptr));
        resolution->setItemText(1, QApplication::translate("MainWindow", "480x300", nullptr));
        resolution->setItemText(2, QApplication::translate("MainWindow", "800x480", nullptr));
        resolution->setItemText(3, QApplication::translate("MainWindow", "1920x1080", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "Grabbing interval", nullptr));
        interval->setText(QApplication::translate("MainWindow", "1000", nullptr));
        interval->setPlaceholderText(QApplication::translate("MainWindow", "millisec", nullptr));
        start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

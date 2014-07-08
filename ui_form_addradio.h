/********************************************************************************
** Form generated from reading UI file 'form_addradio.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_ADDRADIO_H
#define UI_FORM_ADDRADIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_addRadio
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_radioUrl;
    QLineEdit *lE_radioUrl;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_radioName;
    QLineEdit *lE_radioName;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_Ok;
    QPushButton *pb_Cansel;

    void setupUi(QWidget *form_addRadio)
    {
        if (form_addRadio->objectName().isEmpty())
            form_addRadio->setObjectName(QStringLiteral("form_addRadio"));
        form_addRadio->resize(361, 113);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(form_addRadio->sizePolicy().hasHeightForWidth());
        form_addRadio->setSizePolicy(sizePolicy);
        form_addRadio->setMinimumSize(QSize(361, 113));
        form_addRadio->setMaximumSize(QSize(361, 113));
        verticalLayout_2 = new QVBoxLayout(form_addRadio);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        lb_radioUrl = new QLabel(form_addRadio);
        lb_radioUrl->setObjectName(QStringLiteral("lb_radioUrl"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(57);
        sizePolicy1.setVerticalStretch(13);
        sizePolicy1.setHeightForWidth(lb_radioUrl->sizePolicy().hasHeightForWidth());
        lb_radioUrl->setSizePolicy(sizePolicy1);
        lb_radioUrl->setMinimumSize(QSize(57, 13));

        horizontalLayout->addWidget(lb_radioUrl);

        lE_radioUrl = new QLineEdit(form_addRadio);
        lE_radioUrl->setObjectName(QStringLiteral("lE_radioUrl"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lE_radioUrl->sizePolicy().hasHeightForWidth());
        lE_radioUrl->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(lE_radioUrl);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        lb_radioName = new QLabel(form_addRadio);
        lb_radioName->setObjectName(QStringLiteral("lb_radioName"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lb_radioName->sizePolicy().hasHeightForWidth());
        lb_radioName->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(lb_radioName);

        lE_radioName = new QLineEdit(form_addRadio);
        lE_radioName->setObjectName(QStringLiteral("lE_radioName"));
        sizePolicy2.setHeightForWidth(lE_radioName->sizePolicy().hasHeightForWidth());
        lE_radioName->setSizePolicy(sizePolicy2);
        lE_radioName->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(lE_radioName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pb_Ok = new QPushButton(form_addRadio);
        pb_Ok->setObjectName(QStringLiteral("pb_Ok"));

        horizontalLayout_3->addWidget(pb_Ok);

        pb_Cansel = new QPushButton(form_addRadio);
        pb_Cansel->setObjectName(QStringLiteral("pb_Cansel"));

        horizontalLayout_3->addWidget(pb_Cansel);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(form_addRadio);

        QMetaObject::connectSlotsByName(form_addRadio);
    } // setupUi

    void retranslateUi(QWidget *form_addRadio)
    {
        form_addRadio->setWindowTitle(QApplication::translate("form_addRadio", "Form", 0));
        lb_radioUrl->setText(QApplication::translate("form_addRadio", "URL", 0));
        lb_radioName->setText(QApplication::translate("form_addRadio", "Radio Name", 0));
        lE_radioName->setText(QApplication::translate("form_addRadio", "My radio", 0));
        pb_Ok->setText(QApplication::translate("form_addRadio", "Ok", 0));
        pb_Cansel->setText(QApplication::translate("form_addRadio", "Cansel", 0));
    } // retranslateUi

};

namespace Ui {
    class form_addRadio: public Ui_form_addRadio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_ADDRADIO_H

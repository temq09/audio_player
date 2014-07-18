/********************************************************************************
** Form generated from reading UI file 'playlistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTITEM_H
#define UI_PLAYLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayListItem
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lb_trackName;
    QLabel *lb_lenght;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_type;
    QLabel *lb_beatrate;
    QLabel *lb_freq;
    QLabel *lb_size;

    void setupUi(QWidget *PlayListItem)
    {
        if (PlayListItem->objectName().isEmpty())
            PlayListItem->setObjectName(QStringLiteral("PlayListItem"));
        PlayListItem->resize(456, 62);
        PlayListItem->setMinimumSize(QSize(0, 62));
        horizontalLayout = new QHBoxLayout(PlayListItem);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lb_trackName = new QLabel(PlayListItem);
        lb_trackName->setObjectName(QStringLiteral("lb_trackName"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lb_trackName->setFont(font);

        horizontalLayout_3->addWidget(lb_trackName);

        lb_lenght = new QLabel(PlayListItem);
        lb_lenght->setObjectName(QStringLiteral("lb_lenght"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_lenght->sizePolicy().hasHeightForWidth());
        lb_lenght->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        lb_lenght->setFont(font1);

        horizontalLayout_3->addWidget(lb_lenght);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lb_type = new QLabel(PlayListItem);
        lb_type->setObjectName(QStringLiteral("lb_type"));
        sizePolicy.setHeightForWidth(lb_type->sizePolicy().hasHeightForWidth());
        lb_type->setSizePolicy(sizePolicy);
        lb_type->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_type->setMargin(3);

        horizontalLayout_2->addWidget(lb_type);

        lb_beatrate = new QLabel(PlayListItem);
        lb_beatrate->setObjectName(QStringLiteral("lb_beatrate"));
        sizePolicy.setHeightForWidth(lb_beatrate->sizePolicy().hasHeightForWidth());
        lb_beatrate->setSizePolicy(sizePolicy);
        lb_beatrate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lb_beatrate);

        lb_freq = new QLabel(PlayListItem);
        lb_freq->setObjectName(QStringLiteral("lb_freq"));
        sizePolicy.setHeightForWidth(lb_freq->sizePolicy().hasHeightForWidth());
        lb_freq->setSizePolicy(sizePolicy);
        lb_freq->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lb_freq);

        lb_size = new QLabel(PlayListItem);
        lb_size->setObjectName(QStringLiteral("lb_size"));
        sizePolicy.setHeightForWidth(lb_size->sizePolicy().hasHeightForWidth());
        lb_size->setSizePolicy(sizePolicy);
        lb_size->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lb_size);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(PlayListItem);

        QMetaObject::connectSlotsByName(PlayListItem);
    } // setupUi

    void retranslateUi(QWidget *PlayListItem)
    {
        PlayListItem->setWindowTitle(QApplication::translate("PlayListItem", "Form", 0));
        lb_trackName->setText(QString());
        lb_lenght->setText(QString());
        lb_type->setText(QString());
        lb_beatrate->setText(QString());
        lb_freq->setText(QString());
        lb_size->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlayListItem: public Ui_PlayListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTITEM_H

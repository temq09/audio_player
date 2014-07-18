/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *lb_setTitle;
    QLabel *lb_setGenre;
    QLabel *lb_setAutor;
    QLabel *lb_setYear;
    QLabel *lb_numTrack;
    QLabel *lb_title;
    QLabel *lb_autor;
    QLabel *lb_setNumTrack;
    QLabel *lb_year;
    QLabel *lb_format;
    QLabel *lb_setFormat;
    QLabel *lb_duration;
    QLabel *lb_setDuration;
    QLabel *lb_quality;
    QLabel *lb_setQuality;
    QLabel *lb_size;
    QLabel *lb_setSize;
    QLabel *lb_album;
    QLabel *lb_setAlbum;
    QLabel *lb_genre;
    QLabel *label;
    QLabel *lb_pathToFile;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(707, 313);
        Form->setMinimumSize(QSize(707, 313));
        Form->setMaximumSize(QSize(10000, 313));
        verticalLayout_5 = new QVBoxLayout(Form);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(5);
        lb_setTitle = new QLabel(Form);
        lb_setTitle->setObjectName(QStringLiteral("lb_setTitle"));
        QFont font;
        font.setPointSize(12);
        lb_setTitle->setFont(font);
        lb_setTitle->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_setTitle, 0, 1, 1, 1);

        lb_setGenre = new QLabel(Form);
        lb_setGenre->setObjectName(QStringLiteral("lb_setGenre"));
        lb_setGenre->setFont(font);
        lb_setGenre->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_setGenre, 3, 1, 1, 1);

        lb_setAutor = new QLabel(Form);
        lb_setAutor->setObjectName(QStringLiteral("lb_setAutor"));
        lb_setAutor->setFont(font);
        lb_setAutor->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_setAutor, 1, 1, 1, 1);

        lb_setYear = new QLabel(Form);
        lb_setYear->setObjectName(QStringLiteral("lb_setYear"));
        lb_setYear->setFont(font);
        lb_setYear->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_setYear, 4, 1, 1, 1);

        lb_numTrack = new QLabel(Form);
        lb_numTrack->setObjectName(QStringLiteral("lb_numTrack"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_numTrack->sizePolicy().hasHeightForWidth());
        lb_numTrack->setSizePolicy(sizePolicy);
        lb_numTrack->setFont(font);
        lb_numTrack->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_numTrack, 5, 0, 1, 1);

        lb_title = new QLabel(Form);
        lb_title->setObjectName(QStringLiteral("lb_title"));
        sizePolicy.setHeightForWidth(lb_title->sizePolicy().hasHeightForWidth());
        lb_title->setSizePolicy(sizePolicy);
        lb_title->setFont(font);
        lb_title->setAutoFillBackground(false);
        lb_title->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_title, 0, 0, 1, 1);

        lb_autor = new QLabel(Form);
        lb_autor->setObjectName(QStringLiteral("lb_autor"));
        sizePolicy.setHeightForWidth(lb_autor->sizePolicy().hasHeightForWidth());
        lb_autor->setSizePolicy(sizePolicy);
        lb_autor->setFont(font);
        lb_autor->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_autor, 1, 0, 1, 1);

        lb_setNumTrack = new QLabel(Form);
        lb_setNumTrack->setObjectName(QStringLiteral("lb_setNumTrack"));
        lb_setNumTrack->setFont(font);
        lb_setNumTrack->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_setNumTrack, 5, 1, 1, 1);

        lb_year = new QLabel(Form);
        lb_year->setObjectName(QStringLiteral("lb_year"));
        sizePolicy.setHeightForWidth(lb_year->sizePolicy().hasHeightForWidth());
        lb_year->setSizePolicy(sizePolicy);
        lb_year->setFont(font);
        lb_year->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_year, 4, 0, 1, 1);

        lb_format = new QLabel(Form);
        lb_format->setObjectName(QStringLiteral("lb_format"));
        sizePolicy.setHeightForWidth(lb_format->sizePolicy().hasHeightForWidth());
        lb_format->setSizePolicy(sizePolicy);
        lb_format->setFont(font);
        lb_format->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_format, 6, 0, 1, 1);

        lb_setFormat = new QLabel(Form);
        lb_setFormat->setObjectName(QStringLiteral("lb_setFormat"));
        lb_setFormat->setFont(font);
        lb_setFormat->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_setFormat, 6, 1, 1, 1);

        lb_duration = new QLabel(Form);
        lb_duration->setObjectName(QStringLiteral("lb_duration"));
        sizePolicy.setHeightForWidth(lb_duration->sizePolicy().hasHeightForWidth());
        lb_duration->setSizePolicy(sizePolicy);
        lb_duration->setFont(font);
        lb_duration->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_duration, 7, 0, 1, 1);

        lb_setDuration = new QLabel(Form);
        lb_setDuration->setObjectName(QStringLiteral("lb_setDuration"));
        lb_setDuration->setFont(font);
        lb_setDuration->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_setDuration, 7, 1, 1, 1);

        lb_quality = new QLabel(Form);
        lb_quality->setObjectName(QStringLiteral("lb_quality"));
        sizePolicy.setHeightForWidth(lb_quality->sizePolicy().hasHeightForWidth());
        lb_quality->setSizePolicy(sizePolicy);
        lb_quality->setFont(font);
        lb_quality->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_quality, 8, 0, 1, 1);

        lb_setQuality = new QLabel(Form);
        lb_setQuality->setObjectName(QStringLiteral("lb_setQuality"));
        lb_setQuality->setFont(font);
        lb_setQuality->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_setQuality, 8, 1, 1, 1);

        lb_size = new QLabel(Form);
        lb_size->setObjectName(QStringLiteral("lb_size"));
        sizePolicy.setHeightForWidth(lb_size->sizePolicy().hasHeightForWidth());
        lb_size->setSizePolicy(sizePolicy);
        lb_size->setFont(font);
        lb_size->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_size, 9, 0, 1, 1);

        lb_setSize = new QLabel(Form);
        lb_setSize->setObjectName(QStringLiteral("lb_setSize"));
        lb_setSize->setFont(font);
        lb_setSize->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_setSize, 9, 1, 1, 1);

        lb_album = new QLabel(Form);
        lb_album->setObjectName(QStringLiteral("lb_album"));
        sizePolicy.setHeightForWidth(lb_album->sizePolicy().hasHeightForWidth());
        lb_album->setSizePolicy(sizePolicy);
        lb_album->setFont(font);
        lb_album->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_album, 2, 0, 1, 1);

        lb_setAlbum = new QLabel(Form);
        lb_setAlbum->setObjectName(QStringLiteral("lb_setAlbum"));
        lb_setAlbum->setFont(font);
        lb_setAlbum->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_setAlbum, 2, 1, 1, 1);

        lb_genre = new QLabel(Form);
        lb_genre->setObjectName(QStringLiteral("lb_genre"));
        sizePolicy.setHeightForWidth(lb_genre->sizePolicy().hasHeightForWidth());
        lb_genre->setSizePolicy(sizePolicy);
        lb_genre->setFont(font);
        lb_genre->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_genre, 3, 0, 1, 1);

        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);
        label->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(label, 10, 0, 1, 1);

        lb_pathToFile = new QLabel(Form);
        lb_pathToFile->setObjectName(QStringLiteral("lb_pathToFile"));
        lb_pathToFile->setFont(font);
        lb_pathToFile->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(lb_pathToFile, 10, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);

        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_5->addLayout(verticalLayout_2);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        lb_setTitle->setText(QString());
        lb_setGenre->setText(QString());
        lb_setAutor->setText(QString());
        lb_setYear->setText(QString());
        lb_numTrack->setText(QApplication::translate("Form", "\320\235\320\276\320\274\320\265\321\200 \321\202\321\200\320\265\320\272\320\260 \320\262 \320\260\320\273\321\214\320\261\320\276\320\274\320\265", 0));
        lb_title->setText(QApplication::translate("Form", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        lb_autor->setText(QApplication::translate("Form", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", 0));
        lb_setNumTrack->setText(QString());
        lb_year->setText(QApplication::translate("Form", "\320\223\320\276\320\264", 0));
        lb_format->setText(QApplication::translate("Form", "\320\244\320\276\321\200\320\274\320\260\321\202", 0));
        lb_setFormat->setText(QString());
        lb_duration->setText(QApplication::translate("Form", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", 0));
        lb_setDuration->setText(QString());
        lb_quality->setText(QApplication::translate("Form", "\320\232\320\260\321\207\320\265\321\201\321\202\320\262\320\276", 0));
        lb_setQuality->setText(QString());
        lb_size->setText(QApplication::translate("Form", "\320\240\320\260\320\267\320\274\320\265\321\200", 0));
        lb_setSize->setText(QString());
        lb_album->setText(QApplication::translate("Form", "\320\220\320\273\321\214\320\261\320\276\320\274", 0));
        lb_setAlbum->setText(QString());
        lb_genre->setText(QApplication::translate("Form", "\320\226\320\260\320\275\321\200", 0));
        label->setText(QApplication::translate("Form", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\270\320\265", 0));
        lb_pathToFile->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

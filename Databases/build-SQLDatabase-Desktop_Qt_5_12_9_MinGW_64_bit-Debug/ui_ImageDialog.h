/********************************************************************************
** Form generated from reading UI file 'ImageDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDIALOG_H
#define UI_IMAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageDialog
{
public:
    QGridLayout *gridLayout;
    QListWidget *tagList;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *addTagButton;
    QPushButton *addImageButton;
    QLabel *imagesLabel;
    QLabel *imageLabel;

    void setupUi(QWidget *ImageDialog)
    {
        if (ImageDialog->objectName().isEmpty())
            ImageDialog->setObjectName(QString::fromUtf8("ImageDialog"));
        ImageDialog->resize(589, 458);
        gridLayout = new QGridLayout(ImageDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tagList = new QListWidget(ImageDialog);
        tagList->setObjectName(QString::fromUtf8("tagList"));

        gridLayout->addWidget(tagList, 0, 4, 1, 1);

        previousButton = new QPushButton(ImageDialog);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));

        gridLayout->addWidget(previousButton, 1, 0, 1, 1);

        nextButton = new QPushButton(ImageDialog);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        gridLayout->addWidget(nextButton, 1, 1, 1, 1);

        addTagButton = new QPushButton(ImageDialog);
        addTagButton->setObjectName(QString::fromUtf8("addTagButton"));

        gridLayout->addWidget(addTagButton, 1, 2, 1, 1);

        addImageButton = new QPushButton(ImageDialog);
        addImageButton->setObjectName(QString::fromUtf8("addImageButton"));

        gridLayout->addWidget(addImageButton, 1, 3, 1, 1);

        imagesLabel = new QLabel(ImageDialog);
        imagesLabel->setObjectName(QString::fromUtf8("imagesLabel"));

        gridLayout->addWidget(imagesLabel, 1, 4, 1, 1);

        imageLabel = new QLabel(ImageDialog);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));

        gridLayout->addWidget(imageLabel, 0, 0, 1, 4);


        retranslateUi(ImageDialog);

        QMetaObject::connectSlotsByName(ImageDialog);
    } // setupUi

    void retranslateUi(QWidget *ImageDialog)
    {
        ImageDialog->setWindowTitle(QApplication::translate("ImageDialog", "Form", nullptr));
        previousButton->setText(QApplication::translate("ImageDialog", "Previous", nullptr));
        nextButton->setText(QApplication::translate("ImageDialog", "Next", nullptr));
        addTagButton->setText(QApplication::translate("ImageDialog", "Add Tag", nullptr));
        addImageButton->setText(QApplication::translate("ImageDialog", "Add Image", nullptr));
        imagesLabel->setText(QApplication::translate("ImageDialog", "Images:          #", nullptr));
        imageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageDialog: public Ui_ImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDIALOG_H

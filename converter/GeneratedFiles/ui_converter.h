/********************************************************************************
** Form generated from reading UI file 'converter.ui'
**
** Created: Thu 3. May 13:45:10 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTER_H
#define UI_CONVERTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_converterClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTreeView *tree;
    QListView *list;
    QProgressBar *progressBar;
    QPushButton *pushButtonConvert;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *labelWidth;
    QLabel *label_3;
    QLabel *labelHeight;
    QLabel *label_2;
    QLabel *labelColorMode;
    QLabel *label_4;
    QLabel *labelFrames;
    QLabel *labelPreview;
    QSlider *slider;
    QLabel *labelConversionStatus;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *converterClass)
    {
        if (converterClass->objectName().isEmpty())
            converterClass->setObjectName(QString::fromUtf8("converterClass"));
        converterClass->resize(600, 471);
        centralWidget = new QWidget(converterClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tree = new QTreeView(centralWidget);
        tree->setObjectName(QString::fromUtf8("tree"));

        gridLayout->addWidget(tree, 0, 0, 1, 1);

        list = new QListView(centralWidget);
        list->setObjectName(QString::fromUtf8("list"));
        list->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(list, 0, 1, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 1, 0, 1, 2);

        pushButtonConvert = new QPushButton(centralWidget);
        pushButtonConvert->setObjectName(QString::fromUtf8("pushButtonConvert"));

        gridLayout->addWidget(pushButtonConvert, 1, 2, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(200, 0));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        labelWidth = new QLabel(frame);
        labelWidth->setObjectName(QString::fromUtf8("labelWidth"));

        gridLayout_2->addWidget(labelWidth, 2, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        labelHeight = new QLabel(frame);
        labelHeight->setObjectName(QString::fromUtf8("labelHeight"));
        labelHeight->setFrameShape(QFrame::NoFrame);
        labelHeight->setFrameShadow(QFrame::Plain);

        gridLayout_2->addWidget(labelHeight, 3, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        labelColorMode = new QLabel(frame);
        labelColorMode->setObjectName(QString::fromUtf8("labelColorMode"));

        gridLayout_2->addWidget(labelColorMode, 1, 1, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        labelFrames = new QLabel(frame);
        labelFrames->setObjectName(QString::fromUtf8("labelFrames"));

        gridLayout_2->addWidget(labelFrames, 0, 1, 1, 1);

        labelPreview = new QLabel(frame);
        labelPreview->setObjectName(QString::fromUtf8("labelPreview"));
        labelPreview->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(labelPreview, 4, 0, 1, 2);

        slider = new QSlider(frame);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider, 5, 0, 1, 2);


        gridLayout->addWidget(frame, 0, 2, 1, 1);

        labelConversionStatus = new QLabel(centralWidget);
        labelConversionStatus->setObjectName(QString::fromUtf8("labelConversionStatus"));

        gridLayout->addWidget(labelConversionStatus, 2, 0, 1, 2);

        converterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(converterClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        converterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(converterClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        converterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(converterClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        converterClass->setStatusBar(statusBar);

        retranslateUi(converterClass);

        QMetaObject::connectSlotsByName(converterClass);
    } // setupUi

    void retranslateUi(QMainWindow *converterClass)
    {
        converterClass->setWindowTitle(QApplication::translate("converterClass", "converter", 0, QApplication::UnicodeUTF8));
        pushButtonConvert->setText(QApplication::translate("converterClass", "Convert", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("converterClass", "Width:", 0, QApplication::UnicodeUTF8));
        labelWidth->setText(QApplication::translate("converterClass", "n/A", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("converterClass", "Height:", 0, QApplication::UnicodeUTF8));
        labelHeight->setText(QApplication::translate("converterClass", "n/A", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("converterClass", "ColorMode:", 0, QApplication::UnicodeUTF8));
        labelColorMode->setText(QApplication::translate("converterClass", "n/A", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("converterClass", "Frames:", 0, QApplication::UnicodeUTF8));
        labelFrames->setText(QApplication::translate("converterClass", "n/A", 0, QApplication::UnicodeUTF8));
        labelPreview->setText(QString());
        labelConversionStatus->setText(QApplication::translate("converterClass", "idle", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class converterClass: public Ui_converterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTER_H

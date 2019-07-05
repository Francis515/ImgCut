/********************************************************************************
** Form generated from reading UI file 'ImgCut.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGCUT_H
#define UI_IMGCUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imageviewer.h"

QT_BEGIN_NAMESPACE

class Ui_ImgCutClass
{
public:
    QAction *actionOpenImg;
    QAction *actionSaveGray;
    QAction *actionRGB;
    QAction *actionLoadLabel;
    QAction *actionCloseImg;
    QAction *actionSaveAsGray;
    QAction *actionSaveAsRGB;
    QAction *actionCloseLabel;
    QAction *actionHelp;
    QAction *actionContact;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonROI;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonBrush;
    QCheckBox *checkBoxClean;
    QSpinBox *spinBoxBrush;
    QToolButton *toolButtonBrushSize;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButtonFinish;
    QToolButton *toolButtonGrabCut;
    ImageViewer *graphicsView;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menulabels;
    QMenu *menuSave_as;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImgCutClass)
    {
        if (ImgCutClass->objectName().isEmpty())
            ImgCutClass->setObjectName(QStringLiteral("ImgCutClass"));
        ImgCutClass->resize(597, 466);
        actionOpenImg = new QAction(ImgCutClass);
        actionOpenImg->setObjectName(QStringLiteral("actionOpenImg"));
        actionOpenImg->setCheckable(false);
        actionSaveGray = new QAction(ImgCutClass);
        actionSaveGray->setObjectName(QStringLiteral("actionSaveGray"));
        actionRGB = new QAction(ImgCutClass);
        actionRGB->setObjectName(QStringLiteral("actionRGB"));
        actionLoadLabel = new QAction(ImgCutClass);
        actionLoadLabel->setObjectName(QStringLiteral("actionLoadLabel"));
        actionCloseImg = new QAction(ImgCutClass);
        actionCloseImg->setObjectName(QStringLiteral("actionCloseImg"));
        actionSaveAsGray = new QAction(ImgCutClass);
        actionSaveAsGray->setObjectName(QStringLiteral("actionSaveAsGray"));
        actionSaveAsRGB = new QAction(ImgCutClass);
        actionSaveAsRGB->setObjectName(QStringLiteral("actionSaveAsRGB"));
        actionCloseLabel = new QAction(ImgCutClass);
        actionCloseLabel->setObjectName(QStringLiteral("actionCloseLabel"));
        actionHelp = new QAction(ImgCutClass);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionContact = new QAction(ImgCutClass);
        actionContact->setObjectName(QStringLiteral("actionContact"));
        centralWidget = new QWidget(ImgCutClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButtonROI = new QRadioButton(centralWidget);
        radioButtonROI->setObjectName(QStringLiteral("radioButtonROI"));

        verticalLayout->addWidget(radioButtonROI);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButtonBrush = new QRadioButton(centralWidget);
        radioButtonBrush->setObjectName(QStringLiteral("radioButtonBrush"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButtonBrush->sizePolicy().hasHeightForWidth());
        radioButtonBrush->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(radioButtonBrush);

        checkBoxClean = new QCheckBox(centralWidget);
        checkBoxClean->setObjectName(QStringLiteral("checkBoxClean"));
        sizePolicy.setHeightForWidth(checkBoxClean->sizePolicy().hasHeightForWidth());
        checkBoxClean->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(checkBoxClean);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        spinBoxBrush = new QSpinBox(centralWidget);
        spinBoxBrush->setObjectName(QStringLiteral("spinBoxBrush"));
        sizePolicy.setHeightForWidth(spinBoxBrush->sizePolicy().hasHeightForWidth());
        spinBoxBrush->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(spinBoxBrush);

        toolButtonBrushSize = new QToolButton(centralWidget);
        toolButtonBrushSize->setObjectName(QStringLiteral("toolButtonBrushSize"));

        horizontalLayout_4->addWidget(toolButtonBrushSize);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        toolButtonFinish = new QToolButton(centralWidget);
        toolButtonFinish->setObjectName(QStringLiteral("toolButtonFinish"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButtonFinish->sizePolicy().hasHeightForWidth());
        toolButtonFinish->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(toolButtonFinish);

        toolButtonGrabCut = new QToolButton(centralWidget);
        toolButtonGrabCut->setObjectName(QStringLiteral("toolButtonGrabCut"));
        sizePolicy1.setHeightForWidth(toolButtonGrabCut->sizePolicy().hasHeightForWidth());
        toolButtonGrabCut->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(toolButtonGrabCut);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        graphicsView = new ImageViewer(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout_4->addWidget(graphicsView);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_5);

        ImgCutClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImgCutClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 597, 23));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QStringLiteral("menufile"));
        menulabels = new QMenu(menuBar);
        menulabels->setObjectName(QStringLiteral("menulabels"));
        menuSave_as = new QMenu(menulabels);
        menuSave_as->setObjectName(QStringLiteral("menuSave_as"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        ImgCutClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImgCutClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImgCutClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImgCutClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImgCutClass->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menulabels->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menufile->addAction(actionOpenImg);
        menufile->addAction(actionCloseImg);
        menulabels->addAction(menuSave_as->menuAction());
        menuSave_as->addAction(actionSaveAsRGB);
        menuAbout->addAction(actionHelp);
        menuAbout->addAction(actionContact);

        retranslateUi(ImgCutClass);

        QMetaObject::connectSlotsByName(ImgCutClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImgCutClass)
    {
        ImgCutClass->setWindowTitle(QApplication::translate("ImgCutClass", "ImgCut", Q_NULLPTR));
        actionOpenImg->setText(QApplication::translate("ImgCutClass", "Open...", Q_NULLPTR));
        actionSaveGray->setText(QApplication::translate("ImgCutClass", "Grey", Q_NULLPTR));
        actionRGB->setText(QApplication::translate("ImgCutClass", "RGB", Q_NULLPTR));
        actionLoadLabel->setText(QApplication::translate("ImgCutClass", "Load txt...", Q_NULLPTR));
        actionCloseImg->setText(QApplication::translate("ImgCutClass", "Close", Q_NULLPTR));
        actionSaveAsGray->setText(QApplication::translate("ImgCutClass", "Gray", Q_NULLPTR));
        actionSaveAsRGB->setText(QApplication::translate("ImgCutClass", "RGB", Q_NULLPTR));
        actionCloseLabel->setText(QApplication::translate("ImgCutClass", "Close txt", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("ImgCutClass", "Help", Q_NULLPTR));
        actionContact->setText(QApplication::translate("ImgCutClass", "Contact", Q_NULLPTR));
        radioButtonROI->setText(QApplication::translate("ImgCutClass", "ROI", Q_NULLPTR));
        radioButtonBrush->setText(QApplication::translate("ImgCutClass", "Brush", Q_NULLPTR));
        checkBoxClean->setText(QApplication::translate("ImgCutClass", "Clean", Q_NULLPTR));
        toolButtonBrushSize->setText(QApplication::translate("ImgCutClass", "Brush Size", Q_NULLPTR));
        toolButtonFinish->setText(QApplication::translate("ImgCutClass", "Finish", Q_NULLPTR));
        toolButtonGrabCut->setText(QApplication::translate("ImgCutClass", "GrabCut", Q_NULLPTR));
        menufile->setTitle(QApplication::translate("ImgCutClass", "Image", Q_NULLPTR));
        menulabels->setTitle(QApplication::translate("ImgCutClass", "Label", Q_NULLPTR));
        menuSave_as->setTitle(QApplication::translate("ImgCutClass", "Save as", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("ImgCutClass", "About", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImgCutClass: public Ui_ImgCutClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGCUT_H

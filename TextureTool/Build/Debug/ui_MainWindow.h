/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ActionSetCurrentProject;
    QAction *ActionImportImage;
    QAction *ActionQuit;
    QWidget *CentralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *ListGroup;
    QVBoxLayout *verticalLayout;
    QListWidget *ListWidget;
    QGroupBox *PreviewGroup;
    QHBoxLayout *horizontalLayout_2;
    QWidget *Preview;
    QMenuBar *MenuBar;
    QMenu *MenuFile;
    QToolBar *MainToolBar;
    QStatusBar *StatusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(832, 620);
        ActionSetCurrentProject = new QAction(MainWindow);
        ActionSetCurrentProject->setObjectName(QStringLiteral("ActionSetCurrentProject"));
        ActionImportImage = new QAction(MainWindow);
        ActionImportImage->setObjectName(QStringLiteral("ActionImportImage"));
        ActionQuit = new QAction(MainWindow);
        ActionQuit->setObjectName(QStringLiteral("ActionQuit"));
        CentralWidget = new QWidget(MainWindow);
        CentralWidget->setObjectName(QStringLiteral("CentralWidget"));
        horizontalLayout = new QHBoxLayout(CentralWidget);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        ListGroup = new QGroupBox(CentralWidget);
        ListGroup->setObjectName(QStringLiteral("ListGroup"));
        verticalLayout = new QVBoxLayout(ListGroup);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ListWidget = new QListWidget(ListGroup);
        ListWidget->setObjectName(QStringLiteral("ListWidget"));

        verticalLayout->addWidget(ListWidget);


        horizontalLayout->addWidget(ListGroup);

        PreviewGroup = new QGroupBox(CentralWidget);
        PreviewGroup->setObjectName(QStringLiteral("PreviewGroup"));
        horizontalLayout_2 = new QHBoxLayout(PreviewGroup);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Preview = new QWidget(PreviewGroup);
        Preview->setObjectName(QStringLiteral("Preview"));
        Preview->setMinimumSize(QSize(512, 512));
        Preview->setStyleSheet(QStringLiteral("background-color: rgb(100, 100, 100);"));

        horizontalLayout_2->addWidget(Preview);


        horizontalLayout->addWidget(PreviewGroup);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        MainWindow->setCentralWidget(CentralWidget);
        MenuBar = new QMenuBar(MainWindow);
        MenuBar->setObjectName(QStringLiteral("MenuBar"));
        MenuBar->setGeometry(QRect(0, 0, 832, 22));
        MenuFile = new QMenu(MenuBar);
        MenuFile->setObjectName(QStringLiteral("MenuFile"));
        MainWindow->setMenuBar(MenuBar);
        MainToolBar = new QToolBar(MainWindow);
        MainToolBar->setObjectName(QStringLiteral("MainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, MainToolBar);
        StatusBar = new QStatusBar(MainWindow);
        StatusBar->setObjectName(QStringLiteral("StatusBar"));
        MainWindow->setStatusBar(StatusBar);

        MenuBar->addAction(MenuFile->menuAction());
        MenuFile->addAction(ActionSetCurrentProject);
        MenuFile->addSeparator();
        MenuFile->addAction(ActionImportImage);
        MenuFile->addSeparator();
        MenuFile->addAction(ActionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        ActionSetCurrentProject->setText(QApplication::translate("MainWindow", "Set current project...", 0));
        ActionImportImage->setText(QApplication::translate("MainWindow", "Import image...", 0));
        ActionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        ListGroup->setTitle(QApplication::translate("MainWindow", "Textures in project:", 0));
        PreviewGroup->setTitle(QApplication::translate("MainWindow", "Texture preview:", 0));
        MenuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

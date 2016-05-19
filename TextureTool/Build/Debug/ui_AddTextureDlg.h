/********************************************************************************
** Form generated from reading UI file 'AddTextureDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTEXTUREDLG_H
#define UI_ADDTEXTUREDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddTextureDlg
{
public:
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QLabel *ErrorMsg;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *TextureId;
    QLabel *Width;
    QLabel *Height;
    QLabel *PixelFormat;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddTextureDlg)
    {
        if (AddTextureDlg->objectName().isEmpty())
            AddTextureDlg->setObjectName(QStringLiteral("AddTextureDlg"));
        AddTextureDlg->resize(524, 233);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddTextureDlg->sizePolicy().hasHeightForWidth());
        AddTextureDlg->setSizePolicy(sizePolicy);
        AddTextureDlg->setModal(true);
        verticalLayout_3 = new QVBoxLayout(AddTextureDlg);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        ErrorMsg = new QLabel(AddTextureDlg);
        ErrorMsg->setObjectName(QStringLiteral("ErrorMsg"));
        ErrorMsg->setStyleSheet(QStringLiteral(""));
        ErrorMsg->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(ErrorMsg);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(AddTextureDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(AddTextureDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(AddTextureDlg);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(AddTextureDlg);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddTextureDlg);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        TextureId = new QLineEdit(AddTextureDlg);
        TextureId->setObjectName(QStringLiteral("TextureId"));
        TextureId->setMaxLength(250);

        horizontalLayout->addWidget(TextureId);


        verticalLayout_2->addLayout(horizontalLayout);

        Width = new QLabel(AddTextureDlg);
        Width->setObjectName(QStringLiteral("Width"));

        verticalLayout_2->addWidget(Width);

        Height = new QLabel(AddTextureDlg);
        Height->setObjectName(QStringLiteral("Height"));

        verticalLayout_2->addWidget(Height);

        PixelFormat = new QLabel(AddTextureDlg);
        PixelFormat->setObjectName(QStringLiteral("PixelFormat"));

        verticalLayout_2->addWidget(PixelFormat);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 6);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        buttonBox = new QDialogButtonBox(AddTextureDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(2, 1);
        verticalLayout_3->setStretch(3, 10);

        retranslateUi(AddTextureDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddTextureDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddTextureDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddTextureDlg);
    } // setupUi

    void retranslateUi(QDialog *AddTextureDlg)
    {
        AddTextureDlg->setWindowTitle(QApplication::translate("AddTextureDlg", "Dialog", 0));
        ErrorMsg->setText(QApplication::translate("AddTextureDlg", "TextLabel", 0));
        label_2->setText(QApplication::translate("AddTextureDlg", "Texture ID:", 0));
        label_3->setText(QApplication::translate("AddTextureDlg", "Width:", 0));
        label_4->setText(QApplication::translate("AddTextureDlg", "Height:", 0));
        label_5->setText(QApplication::translate("AddTextureDlg", "Pixel format:", 0));
        label->setText(QApplication::translate("AddTextureDlg", "TEX_", 0));
        Width->setText(QApplication::translate("AddTextureDlg", "0px", 0));
        Height->setText(QApplication::translate("AddTextureDlg", "0px", 0));
        PixelFormat->setText(QApplication::translate("AddTextureDlg", "RGBA", 0));
    } // retranslateUi

};

namespace Ui {
    class AddTextureDlg: public Ui_AddTextureDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTEXTUREDLG_H

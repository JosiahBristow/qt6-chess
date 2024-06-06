/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_start
{
public:
    QPushButton *normal;
    QPushButton *queen;
    QPushButton *queenpro;
    QPushButton *queenpro_2;
    QFrame *frame;
    QPushButton *pushButton_2;

    void setupUi(QDialog *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName("start");
        start->resize(557, 381);
        normal = new QPushButton(start);
        normal->setObjectName("normal");
        normal->setGeometry(QRect(220, 160, 111, 23));
        queen = new QPushButton(start);
        queen->setObjectName("queen");
        queen->setGeometry(QRect(220, 200, 111, 23));
        queenpro = new QPushButton(start);
        queenpro->setObjectName("queenpro");
        queenpro->setGeometry(QRect(220, 240, 111, 23));
        queenpro_2 = new QPushButton(start);
        queenpro_2->setObjectName("queenpro_2");
        queenpro_2->setGeometry(QRect(220, 280, 111, 23));
        frame = new QFrame(start);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 561, 381));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/pics/pic/00X58PICmv3JaPNIISj5y_origin_PIC2018.jpg!qt720_jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(start);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 70, 231, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Agency FB")});
        font.setPointSize(72);
        font.setBold(false);
        font.setItalic(false);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 75 72pt \"Agency FB\";\n"
"color rgb(170, 255, 255)"));
        pushButton_2->setFlat(true);
        frame->raise();
        normal->raise();
        queen->raise();
        queenpro->raise();
        queenpro_2->raise();
        pushButton_2->raise();

        retranslateUi(start);

        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QDialog *start)
    {
        start->setWindowTitle(QCoreApplication::translate("start", "Dialog", nullptr));
        normal->setText(QCoreApplication::translate("start", "\346\240\207\345\207\206\346\250\241\345\274\217", nullptr));
        queen->setText(QCoreApplication::translate("start", "\345\205\250\345\220\216\345\261\200", nullptr));
        queenpro->setText(QCoreApplication::translate("start", "\345\205\250\345\220\216\345\261\200\345\271\263\350\241\241\347\211\210", nullptr));
        queenpro_2->setText(QCoreApplication::translate("start", "\345\205\250\351\251\254\345\261\200", nullptr));
        pushButton_2->setText(QCoreApplication::translate("start", "CHESS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H

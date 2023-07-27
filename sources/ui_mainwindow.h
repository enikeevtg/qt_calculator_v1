/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_1;
    QPushButton *pushButton_0;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_op_div;
    QPushButton *pushButton_op_mult;
    QPushButton *pushButton_op_minus;
    QPushButton *pushButton_op_plus;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_calc;
    QPushButton *pushButton_open_bracket;
    QPushButton *pushButton_close_bracket;
    QLabel *label_input;
    QDoubleSpinBox *doubleSpinBox_var;
    QPushButton *pushButton_delete_prev;
    QPushButton *pushButton_mfunc_sqrt;
    QPushButton *pushButton_mfunc_cos;
    QPushButton *pushButton_mfunc_sin;
    QPushButton *pushButton_mfunc_tan;
    QPushButton *pushButton_mfunc_ln;
    QPushButton *pushButton_mfunc_log;
    QPushButton *pushButton_op_pow;
    QPushButton *pushButton_var;
    QPushButton *pushButton_mfunc_inv;
    QPushButton *pushButton_op_mod;
    QCustomPlot *expression_graph;
    QPushButton *pushButton_print_graph;
    QDoubleSpinBox *doubleSpinBox_xmin;
    QDoubleSpinBox *doubleSpinBox_xmax;
    QDoubleSpinBox *doubleSpinBox_ymin;
    QDoubleSpinBox *doubleSpinBox_ymax;
    QLabel *label_output;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1090, 650);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(14);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setIconSize(QSize(21, 21));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_AC = new QPushButton(centralwidget);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        pushButton_AC->setGeometry(QRect(670, 350, 70, 60));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_AC->sizePolicy().hasHeightForWidth());
        pushButton_AC->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font1.setPointSize(25);
        pushButton_AC->setFont(font1);
        pushButton_AC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(810, 410, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(58, 70, 90);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 61, 79)\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(810, 470, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(58, 70, 90);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 61, 79)\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(810, 530, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);
        pushButton_1->setFont(font1);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(58, 70, 90);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 61, 79)\n"
"}"));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(810, 590, 140, 60));
        sizePolicy.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy);
        pushButton_0->setFont(font1);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(58, 70, 90);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 61, 79)\n"
"}"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(880, 410, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(58, 70, 90);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 61, 79)\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(880, 470, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(58, 70, 90);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 61, 79)\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(880, 530, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(58, 70, 90);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 61, 79)\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(950, 410, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(58, 70, 90);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 61, 79)\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(950, 470, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(58, 70, 90);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 61, 79)\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(950, 530, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(58, 70, 90);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(50, 61, 79)\n"
"}"));
        pushButton_op_div = new QPushButton(centralwidget);
        pushButton_op_div->setObjectName(QString::fromUtf8("pushButton_op_div"));
        pushButton_op_div->setGeometry(QRect(1020, 350, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_op_div->sizePolicy().hasHeightForWidth());
        pushButton_op_div->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font2.setPointSize(28);
        pushButton_op_div->setFont(font2);
        pushButton_op_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color:rgb(114, 215, 151);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(104, 196, 138);\n"
"}"));
        pushButton_op_mult = new QPushButton(centralwidget);
        pushButton_op_mult->setObjectName(QString::fromUtf8("pushButton_op_mult"));
        pushButton_op_mult->setGeometry(QRect(1020, 410, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_op_mult->sizePolicy().hasHeightForWidth());
        pushButton_op_mult->setSizePolicy(sizePolicy);
        pushButton_op_mult->setFont(font2);
        pushButton_op_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color:rgb(114, 215, 151);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(104, 196, 138);\n"
"}"));
        pushButton_op_minus = new QPushButton(centralwidget);
        pushButton_op_minus->setObjectName(QString::fromUtf8("pushButton_op_minus"));
        pushButton_op_minus->setGeometry(QRect(1020, 470, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_op_minus->sizePolicy().hasHeightForWidth());
        pushButton_op_minus->setSizePolicy(sizePolicy);
        pushButton_op_minus->setFont(font2);
        pushButton_op_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color:rgb(114, 215, 151);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(104, 196, 138);\n"
"}"));
        pushButton_op_plus = new QPushButton(centralwidget);
        pushButton_op_plus->setObjectName(QString::fromUtf8("pushButton_op_plus"));
        pushButton_op_plus->setGeometry(QRect(1020, 530, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_op_plus->sizePolicy().hasHeightForWidth());
        pushButton_op_plus->setSizePolicy(sizePolicy);
        pushButton_op_plus->setFont(font2);
        pushButton_op_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color:rgb(114, 215, 151);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(104, 196, 138);\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(950, 590, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy);
        pushButton_dot->setFont(font1);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_dot->setCheckable(true);
        pushButton_dot->setChecked(false);
        pushButton_calc = new QPushButton(centralwidget);
        pushButton_calc->setObjectName(QString::fromUtf8("pushButton_calc"));
        pushButton_calc->setGeometry(QRect(1020, 590, 70, 60));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font3.setPointSize(28);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setKerning(true);
        pushButton_calc->setFont(font3);
        pushButton_calc->setMouseTracking(false);
        pushButton_calc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color:rgb(114, 215, 151);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(104, 196, 138);\n"
"}"));
        pushButton_calc->setIconSize(QSize(1, 1));
        pushButton_calc->setCheckable(false);
        pushButton_calc->setChecked(false);
        pushButton_open_bracket = new QPushButton(centralwidget);
        pushButton_open_bracket->setObjectName(QString::fromUtf8("pushButton_open_bracket"));
        pushButton_open_bracket->setGeometry(QRect(810, 350, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_open_bracket->sizePolicy().hasHeightForWidth());
        pushButton_open_bracket->setSizePolicy(sizePolicy);
        pushButton_open_bracket->setFont(font1);
        pushButton_open_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_close_bracket = new QPushButton(centralwidget);
        pushButton_close_bracket->setObjectName(QString::fromUtf8("pushButton_close_bracket"));
        pushButton_close_bracket->setGeometry(QRect(880, 350, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_close_bracket->sizePolicy().hasHeightForWidth());
        pushButton_close_bracket->setSizePolicy(sizePolicy);
        pushButton_close_bracket->setFont(font1);
        pushButton_close_bracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        label_input = new QLabel(centralwidget);
        label_input->setObjectName(QString::fromUtf8("label_input"));
        label_input->setGeometry(QRect(670, 0, 420, 160));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_input->sizePolicy().hasHeightForWidth());
        label_input->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font4.setPointSize(21);
        label_input->setFont(font4);
        label_input->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: disable;\n"
"}"));
        label_input->setFrameShape(QFrame::StyledPanel);
        label_input->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        label_input->setWordWrap(true);
        label_input->setMargin(11);
        label_input->setIndent(-1);
        doubleSpinBox_var = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_var->setObjectName(QString::fromUtf8("doubleSpinBox_var"));
        doubleSpinBox_var->setEnabled(true);
        doubleSpinBox_var->setGeometry(QRect(740, 290, 350, 60));
        doubleSpinBox_var->setFont(font4);
        doubleSpinBox_var->setMouseTracking(false);
        doubleSpinBox_var->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"	border : 2px solid rgb(41, 50, 66);\n"
"	background : rgb(58, 70, 90);\n"
"}"));
        doubleSpinBox_var->setSingleStep(0.100000000000000);
        pushButton_delete_prev = new QPushButton(centralwidget);
        pushButton_delete_prev->setObjectName(QString::fromUtf8("pushButton_delete_prev"));
        pushButton_delete_prev->setGeometry(QRect(950, 350, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_delete_prev->sizePolicy().hasHeightForWidth());
        pushButton_delete_prev->setSizePolicy(sizePolicy);
        pushButton_delete_prev->setFont(font1);
        pushButton_delete_prev->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_mfunc_sqrt = new QPushButton(centralwidget);
        pushButton_mfunc_sqrt->setObjectName(QString::fromUtf8("pushButton_mfunc_sqrt"));
        pushButton_mfunc_sqrt->setGeometry(QRect(740, 470, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_mfunc_sqrt->sizePolicy().hasHeightForWidth());
        pushButton_mfunc_sqrt->setSizePolicy(sizePolicy);
        pushButton_mfunc_sqrt->setFont(font1);
        pushButton_mfunc_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_mfunc_cos = new QPushButton(centralwidget);
        pushButton_mfunc_cos->setObjectName(QString::fromUtf8("pushButton_mfunc_cos"));
        pushButton_mfunc_cos->setGeometry(QRect(670, 470, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_mfunc_cos->sizePolicy().hasHeightForWidth());
        pushButton_mfunc_cos->setSizePolicy(sizePolicy);
        pushButton_mfunc_cos->setFont(font1);
        pushButton_mfunc_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_mfunc_sin = new QPushButton(centralwidget);
        pushButton_mfunc_sin->setObjectName(QString::fromUtf8("pushButton_mfunc_sin"));
        pushButton_mfunc_sin->setGeometry(QRect(670, 530, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_mfunc_sin->sizePolicy().hasHeightForWidth());
        pushButton_mfunc_sin->setSizePolicy(sizePolicy);
        pushButton_mfunc_sin->setFont(font1);
        pushButton_mfunc_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_mfunc_tan = new QPushButton(centralwidget);
        pushButton_mfunc_tan->setObjectName(QString::fromUtf8("pushButton_mfunc_tan"));
        pushButton_mfunc_tan->setGeometry(QRect(670, 590, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_mfunc_tan->sizePolicy().hasHeightForWidth());
        pushButton_mfunc_tan->setSizePolicy(sizePolicy);
        pushButton_mfunc_tan->setFont(font1);
        pushButton_mfunc_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_mfunc_ln = new QPushButton(centralwidget);
        pushButton_mfunc_ln->setObjectName(QString::fromUtf8("pushButton_mfunc_ln"));
        pushButton_mfunc_ln->setGeometry(QRect(740, 530, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_mfunc_ln->sizePolicy().hasHeightForWidth());
        pushButton_mfunc_ln->setSizePolicy(sizePolicy);
        pushButton_mfunc_ln->setFont(font1);
        pushButton_mfunc_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_mfunc_log = new QPushButton(centralwidget);
        pushButton_mfunc_log->setObjectName(QString::fromUtf8("pushButton_mfunc_log"));
        pushButton_mfunc_log->setGeometry(QRect(740, 590, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_mfunc_log->sizePolicy().hasHeightForWidth());
        pushButton_mfunc_log->setSizePolicy(sizePolicy);
        pushButton_mfunc_log->setFont(font1);
        pushButton_mfunc_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_op_pow = new QPushButton(centralwidget);
        pushButton_op_pow->setObjectName(QString::fromUtf8("pushButton_op_pow"));
        pushButton_op_pow->setGeometry(QRect(740, 410, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_op_pow->sizePolicy().hasHeightForWidth());
        pushButton_op_pow->setSizePolicy(sizePolicy);
        pushButton_op_pow->setFont(font1);
        pushButton_op_pow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_var = new QPushButton(centralwidget);
        pushButton_var->setObjectName(QString::fromUtf8("pushButton_var"));
        pushButton_var->setGeometry(QRect(670, 290, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_var->sizePolicy().hasHeightForWidth());
        pushButton_var->setSizePolicy(sizePolicy);
        pushButton_var->setFont(font1);
        pushButton_var->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_mfunc_inv = new QPushButton(centralwidget);
        pushButton_mfunc_inv->setObjectName(QString::fromUtf8("pushButton_mfunc_inv"));
        pushButton_mfunc_inv->setGeometry(QRect(670, 410, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_mfunc_inv->sizePolicy().hasHeightForWidth());
        pushButton_mfunc_inv->setSizePolicy(sizePolicy);
        pushButton_mfunc_inv->setFont(font1);
        pushButton_mfunc_inv->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_op_mod = new QPushButton(centralwidget);
        pushButton_op_mod->setObjectName(QString::fromUtf8("pushButton_op_mod"));
        pushButton_op_mod->setGeometry(QRect(740, 350, 70, 60));
        sizePolicy.setHeightForWidth(pushButton_op_mod->sizePolicy().hasHeightForWidth());
        pushButton_op_mod->setSizePolicy(sizePolicy);
        pushButton_op_mod->setFont(font1);
        pushButton_op_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        expression_graph = new QCustomPlot(centralwidget);
        expression_graph->setObjectName(QString::fromUtf8("expression_graph"));
        expression_graph->setGeometry(QRect(80, 0, 590, 590));
        expression_graph->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	border: 1px solid black;	\n"
"	background-color: rgb(58, 70, 90);\n"
"}"));
        pushButton_print_graph = new QPushButton(centralwidget);
        pushButton_print_graph->setObjectName(QString::fromUtf8("pushButton_print_graph"));
        pushButton_print_graph->setGeometry(QRect(305, 590, 140, 60));
        sizePolicy.setHeightForWidth(pushButton_print_graph->sizePolicy().hasHeightForWidth());
        pushButton_print_graph->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font5.setPointSize(29);
        pushButton_print_graph->setFont(font5);
        pushButton_print_graph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid rgb(31, 38, 50);\n"
"	background-color: rgb(41, 50, 66);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgb(32, 39, 53);\n"
"}"));
        pushButton_print_graph->setCheckable(true);
        pushButton_print_graph->setChecked(false);
        doubleSpinBox_xmin = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_xmin->setObjectName(QString::fromUtf8("doubleSpinBox_xmin"));
        doubleSpinBox_xmin->setGeometry(QRect(80, 590, 80, 20));
        doubleSpinBox_xmax = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_xmax->setObjectName(QString::fromUtf8("doubleSpinBox_xmax"));
        doubleSpinBox_xmax->setGeometry(QRect(590, 590, 80, 20));
        doubleSpinBox_ymin = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_ymin->setObjectName(QString::fromUtf8("doubleSpinBox_ymin"));
        doubleSpinBox_ymin->setGeometry(QRect(0, 570, 80, 20));
        doubleSpinBox_ymax = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_ymax->setObjectName(QString::fromUtf8("doubleSpinBox_ymax"));
        doubleSpinBox_ymax->setGeometry(QRect(0, 0, 80, 20));
        label_output = new QLabel(centralwidget);
        label_output->setObjectName(QString::fromUtf8("label_output"));
        label_output->setGeometry(QRect(670, 160, 420, 130));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(11);
        sizePolicy2.setHeightForWidth(label_output->sizePolicy().hasHeightForWidth());
        label_output->setSizePolicy(sizePolicy2);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font6.setPointSize(42);
        label_output->setFont(font6);
        label_output->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: disable;\n"
"}"));
        label_output->setFrameShape(QFrame::StyledPanel);
        label_output->setFrameShadow(QFrame::Plain);
        label_output->setLineWidth(0);
        label_output->setTextFormat(Qt::AutoText);
        label_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_output->setWordWrap(true);
        label_output->setMargin(11);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SmartCalc_v1.0", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_op_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_op_mult->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        pushButton_op_minus->setText(QCoreApplication::translate("MainWindow", "\342\210\222", nullptr));
        pushButton_op_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_calc->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_open_bracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_close_bracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        label_input->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_delete_prev->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        pushButton_mfunc_sqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        pushButton_mfunc_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_mfunc_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_mfunc_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_mfunc_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_mfunc_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_op_pow->setText(QCoreApplication::translate("MainWindow", "x\342\201\277", nullptr));
        pushButton_var->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_mfunc_inv->setText(QCoreApplication::translate("MainWindow", "Inv", nullptr));
        pushButton_op_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_print_graph->setText(QCoreApplication::translate("MainWindow", "plot", nullptr));
        label_output->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\323\231\320\275\320\274\320\265\321\201\320\265\320\267!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

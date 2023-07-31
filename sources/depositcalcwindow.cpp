#include "depositcalcwindow.h"
#include "ui_depositcalcwindow.h"

DepositCalcWindow::DepositCalcWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DepositCalcWindow)
{
    ui->setupUi(this);
}

DepositCalcWindow::~DepositCalcWindow()
{
    delete ui;
}

#include "depositcalcwindow.h"

#include "ui_depositcalcwindow.h"

DepositCalcWindow::DepositCalcWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::DepositCalcWindow) {
  ui->setupUi(this);

  ui->tableWidget_replenishments_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableWidget_withdrawals_list->setEditTriggers(QAbstractItemView::NoEditTriggers);

  ui->spinBox_replenishment_month->setMinimum(0);
  ui->spinBox_replenishment_month->setMaximum(std::numeric_limits<int>::max());
  ui->doubleSpinBox_replenishments_amount->setMinimum(0.0);
  ui->doubleSpinBox_replenishments_amount->setMaximum(
              std::numeric_limits<double>::max());

  ui->spinBox_withdrawals_month->setMinimum(0);
  ui->spinBox_withdrawals_month->setMaximum(std::numeric_limits<int>::max());
  ui->doubleSpinBox_withdrawals_amount->setMinimum(0.0);
  ui->doubleSpinBox_withdrawals_amount->setMaximum(
              std::numeric_limits<double>::max());

  connect(ui->pushButton_add_replenishment, SIGNAL(clicked()), this, SLOT(clickedAddRow()));
  connect(ui->pushButton_add_withdrawal, SIGNAL(clicked()), this, SLOT(clickedAddRow()));

  connect(ui->pushButton_remove_last_replenishment, SIGNAL(clicked()), this, SLOT(clickedRemoveRow()));
  connect(ui->pushButton_remove_last_withdrawal, SIGNAL(clicked()), this, SLOT(clickedRemoveRow()));
}



DepositCalcWindow::~DepositCalcWindow() { delete ui; }

void DepositCalcWindow::on_pushButton_calculate_clicked() {
    struct deposit_input data = {0, 0, 0, 0, 0, nullptr, nullptr};
//    struct deposit_output result = {0, 0, 0};
    data.total_begin = ui->doubleSpinBox_deposit_total_amount->value();
    int scale = 1;
    if (ui->comboBox_term_mode->currentText() == "years") scale = 12;
    data.term = scale * ui->spinBox_deposit_term->value();
    data.deposit_rate = ui->doubleSpinBox_deposit_rate->value();
    data.tax_rate = ui->doubleSpinBox_deposit_tax_rate->value();
    data.periodicity = 1;
    QString periodicity_text = ui->comboBox_periodicity->currentText();
    if (periodicity_text == "once a quarter") {
        data.periodicity = 3;
    } else if (periodicity_text == "semiannually") {
        data.periodicity = 6;
    } else if (periodicity_text == "once a year") {
        data.periodicity = 12;
    } else if (periodicity_text == "at the end of the term") {
        data.periodicity = data.term;
    }

//    QVector<double> replenishment_input(data.term + 1);
//    int replenishments_number = ui->tableWidget_replenishment_list->rowCount();
//    for (int i = 0; i < replenishments_number; i++) {
//        QString month_number = ui->tableWidget_replenishment_list->item(i, 1)->text();
//        replenishment_input[]
//    }
    QString month_number = ui->tableWidget_replenishments_list->item(0, 0)->text();
    ui->statusbar->showMessage(month_number);
//    ui->statusbar->showMessage(QString::number(replenishments_number));
//    replenishment_input.data()

}

void DepositCalcWindow::clickedAddRow() {
    QTableWidget* table;
    QSpinBox* month_box;
    QDoubleSpinBox* amount_box;
    QPushButton* button = (QPushButton*)sender();
    if (button->text() == "+ add new replenishment") {
        table = ui->tableWidget_replenishments_list;
        month_box = ui->spinBox_replenishment_month;
        amount_box = ui->doubleSpinBox_replenishments_amount;
    } else {
        table = ui->tableWidget_withdrawals_list;
        month_box = ui->spinBox_withdrawals_month;
        amount_box = ui->doubleSpinBox_withdrawals_amount;
    }

    int scale = 1;
    if (ui->comboBox_term_mode->currentText() == "years") scale = 12;
    int month = scale * month_box->value();
    double amount = amount_box->value();

    if (month == 0) {
        ui->statusbar->showMessage("Month must be greater than nill");
    } else if (month > ui->spinBox_deposit_term->value()) {
        ui->statusbar->showMessage("Month must be less than or equal to Deposit term");
    } else {
        addNewRow(table, month, amount);
    }
}

void DepositCalcWindow::addNewRow(QTableWidget* table, int month, double amount) {
    table->insertRow(table->rowCount());
    int current_row = table->rowCount();

    QTableWidgetItem* item_month = new QTableWidgetItem(QString::number(month));
    table->setItem(current_row - 1, 0, item_month);
    QTableWidgetItem* item_amount = new QTableWidgetItem(QString::number(amount));
    table->setItem(current_row - 1, 1, item_amount);
}

void DepositCalcWindow::clickedRemoveRow() {
    QTableWidget* table;
    QPushButton* button = (QPushButton*)sender();
    if (button->text() == "− remove last replenishment") {
        table = ui->tableWidget_replenishments_list;
    } else {
        table = ui->tableWidget_withdrawals_list;
    }

    int rows = table->rowCount();
    if (rows > 0) {
        table->setRowCount(rows - 1);
    }
}

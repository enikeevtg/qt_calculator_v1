#ifndef DEPOSITCALCWINDOW_H
#define DEPOSITCALCWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

extern "C" {
#include "07_deposit_calculator/deposit_calculator.h"
}

namespace Ui {
class DepositCalcWindow;
}

class DepositCalcWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit DepositCalcWindow(QWidget *parent = nullptr);
  ~DepositCalcWindow();

private slots:
    void on_pushButton_calculate_clicked();

    void clickedAddRow();
    void addNewRow(QTableWidget* table, int month, double amount);

    void clickedRemoveRow();

private:
  Ui::DepositCalcWindow *ui;
};

#endif  // DEPOSITCALCWINDOW_H

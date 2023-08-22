#ifndef SMARTCALC_05_UI_MAINWINDOW_H_
#define SMARTCALC_05_UI_MAINWINDOW_H_

#include <QMainWindow>
#include <cstring>
#include <limits>

#include "creditcalcwindow.h"
#include "depositcalcwindow.h"

extern "C" {
#include "../data_structures.h"
#include "../smart_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum {
  all_clean,
  num_token,
  dot_token,
  var_token,
  op_token,
  pow_token,
  open_bracket_token,
  close_bracket_token,
  math_func_token,
  calculation
};

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_AC_clicked();
  void on_pushButton_delete_prev_clicked();
  void lastTokenChecking();

  void clickedButtonDigits();
  void on_pushButton_dot_clicked();
  void on_pushButton_var_clicked();

  void clickedButtonOperations();
  void unaryMinusInput();
  void operatorInput(QString button_text);
  void unaryMinusChanging();
  void on_pushButton_op_pow_clicked();

  void on_pushButton_open_bracket_clicked();
  void on_pushButton_close_bracket_clicked();

  void on_pushButton_mfunc_inv_clicked();
  void clickedButtonMathFunctions();

  void on_pushButton_calc_clicked();
  void on_pushButton_print_graph_clicked();
  void graphPlot(double x_min, double x_max, double y_min, double y_max);

  void on_action_credit_calculator_triggered();
  void on_action_deposit_calculator_triggered();

 private:
  Ui::MainWindow* ui;
  CreditCalcWindow* window_credit_calc;
  DepositCalcWindow* window_deposit_calc;

  int last_token_type = num_token;
  bool is_dot_input = false;
  bool is_u_minus_input = false;
  int brackets_counter = 0;
};
#endif  // SMARTCALC_05_UI_MAINWINDOW_H_

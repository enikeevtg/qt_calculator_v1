#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstring>
#include <limits>

extern "C" {
    #include "data_structures.h"
    #include "smart_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
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

    int on_pushButton_calc_clicked();
    void on_pushButton_print_graph_clicked();
    void graphPlot(double x_min, double x_max, double y_min, double y_max);

private:
    Ui::MainWindow *ui;

    bool is_num_input = true;
    bool is_var_input = false;
    bool is_dot_input = false;
    bool is_op_input = false;
    bool is_pow_input = false;
    bool is_u_minus_input = false;
    bool is_open_bracket_input = false;
    bool is_close_bracket_input = false;
    int brackets_counter = 0;
    bool is_mfunc_input = false;
    bool is_calc_done = false;
};
#endif // MAINWINDOW_H

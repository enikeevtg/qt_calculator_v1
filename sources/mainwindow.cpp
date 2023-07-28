#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // INPUT_LABEL
  ui->label_input->setWordWrap(true);

  // DIGIT BUTTONS
  connect(ui->pushButton_0, SIGNAL(clicked()), this,
          SLOT(clickedButtonDigits()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this,
          SLOT(clickedButtonDigits()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this,
          SLOT(clickedButtonDigits()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this,
          SLOT(clickedButtonDigits()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this,
          SLOT(clickedButtonDigits()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this,
          SLOT(clickedButtonDigits()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this,
          SLOT(clickedButtonDigits()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this,
          SLOT(clickedButtonDigits()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this,
          SLOT(clickedButtonDigits()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this,
          SLOT(clickedButtonDigits()));

  // OPERATORS BUTTONS
  connect(ui->pushButton_op_plus, SIGNAL(clicked()), this,
          SLOT(clickedButtonOperations()));
  connect(ui->pushButton_op_minus, SIGNAL(clicked()), this,
          SLOT(clickedButtonOperations()));
  connect(ui->pushButton_op_mult, SIGNAL(clicked()), this,
          SLOT(clickedButtonOperations()));
  connect(ui->pushButton_op_div, SIGNAL(clicked()), this,
          SLOT(clickedButtonOperations()));
  connect(ui->pushButton_op_mod, SIGNAL(clicked()), this,
          SLOT(clickedButtonOperations()));

  // MATH FUNCTIONS BUTTONS
  ui->pushButton_mfunc_inv->setCheckable(true);
  connect(ui->pushButton_mfunc_cos, SIGNAL(clicked()), this,
          SLOT(clickedButtonMathFunctions()));
  connect(ui->pushButton_mfunc_sin, SIGNAL(clicked()), this,
          SLOT(clickedButtonMathFunctions()));
  connect(ui->pushButton_mfunc_tan, SIGNAL(clicked()), this,
          SLOT(clickedButtonMathFunctions()));
  connect(ui->pushButton_mfunc_sqrt, SIGNAL(clicked()), this,
          SLOT(clickedButtonMathFunctions()));
  connect(ui->pushButton_mfunc_log, SIGNAL(clicked()), this,
          SLOT(clickedButtonMathFunctions()));
  connect(ui->pushButton_mfunc_ln, SIGNAL(clicked()), this,
          SLOT(clickedButtonMathFunctions()));

  // VARIABLE SPINBOX
  ui->doubleSpinBox_var->setValue(0.0);
  ui->doubleSpinBox_var->setEnabled(false);
  ui->doubleSpinBox_var->setMaximum(std::numeric_limits<double>::max());
  ui->doubleSpinBox_var->setMinimum(-std::numeric_limits<double>::max());
  ui->doubleSpinBox_var->setDecimals(7);

  // GRAPH
  // RANGE SPINBOXES
  ui->doubleSpinBox_xmin->setMinimum(-1000000.0);
  ui->doubleSpinBox_xmin->setMaximum(1000000.0);

  ui->doubleSpinBox_xmax->setMinimum(-1000000.0);
  ui->doubleSpinBox_xmax->setMaximum(1000000.0);

  ui->doubleSpinBox_ymin->setMinimum(-1000000.0);
  ui->doubleSpinBox_ymin->setMaximum(1000000.0);

  ui->doubleSpinBox_ymax->setMinimum(-1000000.0);
  ui->doubleSpinBox_ymax->setMaximum(1000000.0);

  ui->doubleSpinBox_xmin->setValue(0);
  ui->doubleSpinBox_xmax->setValue(21.0);
  ui->doubleSpinBox_ymin->setValue(0);
  ui->doubleSpinBox_ymax->setValue(21.0);

  // GRAPH
  ui->expression_graph->setBackground(QColorConstants::Svg::grey);
  ui->expression_graph->xAxis->setLabel("x");
  ui->expression_graph->yAxis->setLabel("y(x)");

  ui->expression_graph->xAxis->setRange(0, 21);
  ui->expression_graph->yAxis->setRange(0, 21);
}

MainWindow::~MainWindow() { delete ui; }

// SERVICE
void MainWindow::on_pushButton_AC_clicked() {
  ui->label_input->setText("0");
  ui->label_output->setText("");
  ui->doubleSpinBox_var->setEnabled(false);
  ui->doubleSpinBox_var->setValue(0.0);
  ui->doubleSpinBox_xmin->setValue(0);
  ui->doubleSpinBox_xmax->setValue(21.0);
  ui->doubleSpinBox_ymin->setValue(0);
  ui->doubleSpinBox_ymax->setValue(21.0);
  ui->expression_graph->xAxis->setRange(0, 21);
  ui->expression_graph->yAxis->setRange(0, 21);
  ui->expression_graph->removeGraph(0);

  is_num_input = true;
  is_var_input = false;
  is_dot_input = false;
  is_op_input = false;
  is_pow_input = false;
  is_u_minus_input = false;
  is_open_bracket_input = false;
  is_close_bracket_input = false;
  brackets_counter = 0;
  is_mfunc_input = false;
  is_calc_done = false;
}

void MainWindow::on_pushButton_delete_prev_clicked() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  QString input_label_text = ui->label_input->text();
  size_t input_text_length = input_label_text.length();
  size_t reduced_size = input_text_length - 1;
  QString last_input_char = input_label_text.last(1);

  if (last_input_char == " ") {
    reduced_size -= 2;
  } else if (last_input_char == "(") {
    while (reduced_size > 0 && input_label_text[reduced_size - 1] != ' ' &&
           input_label_text[reduced_size - 1] != '(' &&
           input_label_text[reduced_size - 1] != ')' &&
           input_label_text[reduced_size - 1] != '^') {
      reduced_size--;
    }
    if (reduced_size > 0 && input_label_text[reduced_size - 1] == '^') {
      reduced_size--;
    }
  }
  input_label_text.resize(reduced_size);
  ui->label_input->setText(input_label_text);
  if (input_label_text == "") {
    ui->pushButton_0->click();
  } else {
    if (last_input_char == ")") {
      brackets_counter++;
    }
    lastTokenChecking();
  }
}

void MainWindow::lastTokenChecking() {
  is_num_input = false;
  is_dot_input = false;
  is_op_input = false;
  is_pow_input = false;
  is_u_minus_input = false;
  is_open_bracket_input = false;
  is_close_bracket_input = false;
  is_mfunc_input = false;
  is_calc_done = false;

  QString last_label_char = ui->label_input->text().last(1);

  if (last_label_char == " ") {
    is_op_input = true;
  } else if (last_label_char == "(") {
    is_open_bracket_input = true;
  } else if (last_label_char == ")") {
    is_close_bracket_input = true;
  } else if (last_label_char == "-") {
    is_op_input = true;
    is_u_minus_input = true;
  } else {
    QString input_label_text = ui->label_input->text();
    size_t input_text_length = input_label_text.length();
    int i = input_text_length - 1;
    while (i >= 0 && input_label_text[i] != ' ' && input_label_text[i] != '(' &&
           input_label_text[i] != '-') {
      if (input_label_text[i] == '.') {
        is_dot_input = true;
      }
      i--;
    }
    is_num_input = true;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DIGITS AND VARIABLE
void MainWindow::clickedButtonDigits() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  QPushButton* button = (QPushButton*)sender();

  if (ui->label_input->text() == "0" || ui->label_input->text() == "") {
    ui->label_input->setText(button->text());
  } else if (ui->label_input->text().length() > 1 &&
             (ui->label_input->text().last(2) == "(0" ||
              ui->label_input->text().last(2) == "-0" ||
              ui->label_input->text().last(2) == " 0")) {
  } else {
    if (is_close_bracket_input == true || is_var_input == true) {
      ui->pushButton_op_mult->click();
    }
    ui->label_input->setText(ui->label_input->text() + button->text());
  }
  is_num_input = true;
  is_var_input = false;
  is_op_input = false;
  is_u_minus_input = false;
  is_open_bracket_input = false;
  is_close_bracket_input = false;
}

void MainWindow::on_pushButton_dot_clicked() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  if (is_dot_input == false && is_var_input == false) {
    if (is_num_input == false) {
      ui->pushButton_0->click();
    }
    ui->label_input->setText(ui->label_input->text() + '.');
    is_dot_input = true;
  }
}

void MainWindow::on_pushButton_var_clicked() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  if (ui->doubleSpinBox_var->isEnabled() == false) {
    ui->doubleSpinBox_var->setEnabled(true);
  }

  if (ui->label_input->text() == "0") {
    ui->label_input->setText("x");
  } else {
    if (is_num_input == true || is_var_input == true ||
        is_close_bracket_input == true) {
      ui->pushButton_op_mult->click();
    }
    ui->label_input->setText(ui->label_input->text() + "x");
  }
  is_var_input = true;
  is_op_input = false;
  is_u_minus_input = false;
  is_open_bracket_input = false;
  is_close_bracket_input = false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OPERATORS
void MainWindow::clickedButtonOperations() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  QPushButton* button = (QPushButton*)sender();
  QString button_text = button->text();
  QString last_input_char = ui->label_input->text().last(1);

  if (button_text == "×")
    button_text = "*";
  else if (button_text == "÷")
    button_text = "/";
  else if (button_text == "−")
    button_text = "-";
  else if (button_text == "mod")
    button_text = "%";

  if (is_op_input == false) {
    if (last_input_char == ".") {
      ui->pushButton_0->click();
    }

    if ((ui->label_input->text() == "0" || is_open_bracket_input == true) &&
        button_text == "-") {
      unaryMinusInput();
    } else if (is_open_bracket_input == false) {
      operatorInput(button_text);
    }
  } else {  // is_op_input == true
    if (ui->label_input->text() == "-" && button_text != "-") {
      unaryMinusChanging();
    } else if (is_open_bracket_input == true && button_text != "-") {
      on_pushButton_delete_prev_clicked();
    } else if (is_u_minus_input == false) {
      on_pushButton_delete_prev_clicked();
      button->click();
    }
  }
}

void MainWindow::unaryMinusInput() {
  if (ui->label_input->text() == "0") {
    ui->label_input->setText("-");
  } else if (is_open_bracket_input == true) {
    ui->label_input->setText(ui->label_input->text() + "-");
  }
  is_num_input = false;
  is_op_input = true;
  is_u_minus_input = true;
  //    is_open_bracket_input = false;
}

void MainWindow::operatorInput(QString button_text) {
  ui->label_input->setText(ui->label_input->text() + " " + button_text + " ");
  is_num_input = false;
  is_dot_input = false;
  is_var_input = false;
  is_op_input = true;
  is_open_bracket_input = false;
  is_close_bracket_input = false;
}

void MainWindow::unaryMinusChanging() {
  on_pushButton_delete_prev_clicked();
  if (ui->label_input->text().length() == 0) {
    ui->pushButton_0->click();
  }
  is_op_input = false;
  is_open_bracket_input = false;
  is_close_bracket_input = false;
}

void MainWindow::on_pushButton_op_pow_clicked() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  if (is_num_input == true || is_close_bracket_input == true ||
      is_var_input == true || ui->label_input->text() == "0") {
    ui->label_input->setText(ui->label_input->text() + "^");
    is_pow_input = true;
    on_pushButton_open_bracket_clicked();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BRACKETS
void MainWindow::on_pushButton_open_bracket_clicked() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  if (ui->label_input->text() == "0") {
    ui->label_input->setText("(");
  } else if (is_u_minus_input == true || is_mfunc_input == true ||
             is_open_bracket_input == true || is_pow_input == true) {
    ui->label_input->setText(ui->label_input->text() + "(");
  } else {
    if (is_num_input == true || is_var_input == true) {
      ui->pushButton_op_mult->click();
    }
    ui->label_input->setText(ui->label_input->text() + "(");
  }

  is_num_input = false;
  is_dot_input = false;
  is_op_input = false;
  is_pow_input = false;
  is_u_minus_input = false;
  is_open_bracket_input = true;
  is_close_bracket_input = false;
  brackets_counter++;
  is_mfunc_input = false;
}

void MainWindow::on_pushButton_close_bracket_clicked() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  if (brackets_counter > 0 && is_op_input == false &&
      is_u_minus_input == false && is_open_bracket_input == false) {
    if (is_dot_input == true) {
      ui->pushButton_0->click();
    }
    ui->label_input->setText(ui->label_input->text() + ")");

    is_num_input = false;
    is_close_bracket_input = true;
    brackets_counter--;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MATH FUNCTIONS
void MainWindow::on_pushButton_mfunc_inv_clicked() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  if (ui->pushButton_mfunc_inv->isChecked()) {
    ui->pushButton_mfunc_cos->setText("acos");
    ui->pushButton_mfunc_sin->setText("asin");
    ui->pushButton_mfunc_tan->setText("atan");
  } else {
    ui->pushButton_mfunc_cos->setText("cos");
    ui->pushButton_mfunc_sin->setText("sin");
    ui->pushButton_mfunc_tan->setText("tan");
  }
}

void MainWindow::clickedButtonMathFunctions() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  QPushButton* button = (QPushButton*)sender();
  QString button_text = button->text();

  if (button_text == "√") button_text = "sqrt";  //!!!!!

  if (ui->label_input->text() == "0") {
    ui->label_input->setText(button_text);
  } else {
    if (is_num_input == true || is_close_bracket_input == true) {
      ui->pushButton_op_mult->click();
    }
    ui->label_input->setText(ui->label_input->text() + button_text);
  }
  is_mfunc_input = true;
  on_pushButton_open_bracket_clicked();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CALCULATIONS LAUNCH
void MainWindow::on_pushButton_calc_clicked() {
  if (is_calc_done == true) {
    on_pushButton_AC_clicked();
  }

  int error = OK;
  QString input_label_text = ui->label_input->text();
  char* str_for_calc = new char(input_label_text.length());
  QByteArray tmp_byte_array = input_label_text.toLatin1();
  strlcpy(str_for_calc, tmp_byte_array, input_label_text.length() + 1);

  double variable = ui->doubleSpinBox_var->value();
  double result = 0.0;
  node_t* q_root = NULL;

  error = convert_infix_to_RPN(str_for_calc, &q_root);
  if (error == OK) {
    error = evaluate_expression(q_root, variable, &result);
  }

  QString result_string;
  if (error == OK) {
    ui->label_input->setText(input_label_text + " =");
    result_string = QString::number(result);
  } else {
    ERRORS_MESSAGES;
    result_string = errors_msg[error];
  }

  ui->label_output->setText(result_string);
  is_calc_done = true;
  delete str_for_calc;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GRAPH
void MainWindow::on_pushButton_print_graph_clicked() {
  double x_min = ui->doubleSpinBox_xmin->value();
  double x_max = ui->doubleSpinBox_xmax->value();
  double y_min = ui->doubleSpinBox_ymin->value();
  double y_max = ui->doubleSpinBox_ymax->value();

  if (x_max - x_min > 0 && y_max - y_min > 0) {
    graphPlot(x_min, x_max, y_min, y_max);
  } else {
    ui->label_output->setText("incorrect range");
  }
}

void MainWindow::graphPlot(double x_min, double x_max, double y_min,
                           double y_max) {
  QString input_label_text = ui->label_input->text();
  if (is_calc_done == true) {
    input_label_text.resize(input_label_text.length() - 2);
  }
  char* str_for_calc = new char(input_label_text.length());
  QByteArray tmp_byte_array = input_label_text.toLatin1();

  strlcpy(str_for_calc, tmp_byte_array, input_label_text.length() + 1);

  double variable = ui->doubleSpinBox_var->value();
  double result = 0.0;
  node_t* q_root = NULL;

  int error = convert_infix_to_RPN(str_for_calc, &q_root);
  if (error == OK) {
    error = evaluate_expression(q_root, variable, &result);
  }

  QVector<double> x, y;
  if (error != OK) {
    ERRORS_MESSAGES;
    ui->label_output->setText(errors_msg[error]);

  } else {
    variable = x_min;
    double step_size = (x_max - x_min) / ui->expression_graph->width();
    while (variable <= x_max) {
      int error = convert_infix_to_RPN(str_for_calc, &q_root);
      if (error == OK) {
        error = evaluate_expression(q_root, variable, &result);
      }
      if (error == OK && result == result && result != 1.0 / 0.0) {
        x.push_back(variable);
        y.push_back(result);
      }
      variable += step_size;
    }

    ui->expression_graph->expression_graph();
    ui->expression_graph->graph(0)->setData(x, y);
    ui->expression_graph->xAxis->setRange(x_min, x_max);
    ui->expression_graph->yAxis->setRange(y_min, y_max);
    ui->expression_graph->replot();
  }
  delete str_for_calc;
  x.clear();
  y.clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GRAPH
// double stepSizeCalculation(QVector<double> x, QVector<double> y, double
// scale) {
//   QVector<double> delta_x = x.last(2);
//   QVector<double> delta_y = y.last(2);
//   double delta = sqrt(pow((delta_x.last() - delta_x.first()), 2) +
//   pow((delta_y.last() - delta_y.first()), 2)); if (delta > scale)

//}

// void MainWindow::graphPlot(double x_min, double x_max, double y_min, double
// y_max) {
//     QString input_label_text = ui->label_input->text();
//     char* str_for_calc = new char(input_label_text.length());
//     QByteArray tmp_byte_array = input_label_text.toLatin1();
//     strlcpy(str_for_calc, tmp_byte_array, input_label_text.length() + 1);

//    double variable = x_min;
//    double result = 0.0;
//    node_t* q_root = NULL;

//    int error = convert_infix_to_RPN(str_for_calc, &q_root);
//    QVector<double> x, y;
//    if (error != OK) {
//        ERRORS_MESSAGES;
//        ui->label_output->setText(errors_msg[error]);
//    } else {
//        double px_scale = ui->expression_graph->width() / (x_max - x_min);
//        double initial_step_size = (x_max - x_min) /
//        ui->expression_graph->width(); while (variable <= x_max) {
//            int error = convert_infix_to_RPN(str_for_calc, &q_root);
//            if (error == OK) {
//                error = evaluate_expression(q_root, variable, &result);
//            }
//            if (error == OK && result == result && result != 1.0 / 0.0) {
//                x.push_back(variable);
//                y.push_back(result);
//                qDebug() << "x = "<< variable << "y = " << result;
//            }
//            if (x.size() == 1) {
//                variable += initial_step_size;
//            } else {
//                variable += stepSizeCalculation(x, y, px_scale);
//            }
//        }
//        ui->expression_graph->expression_graph();
//        ui->expression_graph->graph(0)->setData(x, y);
//        ui->expression_graph->graph(0)->setPen(QPen(Qt::black));
//        ui->expression_graph->graph(0)->setLineStyle(QCPGraph::lsNone);
//        ui->expression_graph->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,
//        2));

//        ui->expression_graph->xAxis->setRange(x_min, x_max);
//        ui->expression_graph->yAxis->setRange(y_min, y_max);
//        ui->expression_graph->replot();
//    }
//    delete str_for_calc;
//    x.clear();
//    y.clear();
//}

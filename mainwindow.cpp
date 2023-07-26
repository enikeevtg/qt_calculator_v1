#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(clickedButtonDigits()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(clickedButtonDigits()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(clickedButtonDigits()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(clickedButtonDigits()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(clickedButtonDigits()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(clickedButtonDigits()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(clickedButtonDigits()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(clickedButtonDigits()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(clickedButtonDigits()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(clickedButtonDigits()));

    connect(ui->pushButton_op_plus, SIGNAL(clicked()), this, SLOT(clickedButtonOperations()));
    connect(ui->pushButton_op_minus, SIGNAL(clicked()), this, SLOT(clickedButtonOperations()));
    connect(ui->pushButton_op_mult, SIGNAL(clicked()), this, SLOT(clickedButtonOperations()));
    connect(ui->pushButton_op_div, SIGNAL(clicked()), this, SLOT(clickedButtonOperations()));

    ui->pushButton_mfunc_inv->setCheckable(true);
    connect(ui->pushButton_mfunc_cos, SIGNAL(clicked()), this, SLOT(clickedButtonMathFunctions()));
    connect(ui->pushButton_mfunc_sin, SIGNAL(clicked()), this, SLOT(clickedButtonMathFunctions()));
    connect(ui->pushButton_mfunc_tan, SIGNAL(clicked()), this, SLOT(clickedButtonMathFunctions()));
    connect(ui->pushButton_mfunc_sqrt, SIGNAL(clicked()), this, SLOT(clickedButtonMathFunctions()));
    connect(ui->pushButton_mfunc_log, SIGNAL(clicked()), this, SLOT(clickedButtonMathFunctions()));
    connect(ui->pushButton_mfunc_ln, SIGNAL(clicked()), this, SLOT(clickedButtonMathFunctions()));

    ui->doubleSpinBox->setEnabled(false);
    ui->doubleSpinBox->setMaximum(std::numeric_limits<double>::max());
    ui->doubleSpinBox->setMinimum(-std::numeric_limits<double>::max());
    ui->doubleSpinBox->setDecimals(7);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// SERVICE
void MainWindow::on_pushButton_AC_clicked() {
    ui->label_input->setText("0");
    ui->label_output->setText("");

    is_num_input = true;
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

    QString last_input_char = input_label_text.last(1);
    int reducing_size = 1;
    if (last_input_char == " ") {
        reducing_size = 3;
    } else if (last_input_char == "(") {
        int i = input_text_length - reducing_size;
        while (reducing_size < (int)input_text_length &&
               input_label_text[i] != ' ' && input_label_text[i] != '(' &&
               input_label_text[i] != ')' && input_label_text[i] != '^') {
            reducing_size++;
            i--;
        }
        if (i >= 0 && input_label_text[i - 1] == '^') {
            reducing_size++;
        }
    }
    input_label_text.resize(input_text_length - reducing_size);
    ui->label_input->setText(input_label_text);
    if (input_label_text == "") {
        ui->pushButton_0->click();
    } else {
        if(last_input_char == ")") {
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
        while (i >= 0 && input_label_text[i] != ' ' && input_label_text[i] != '(' && input_label_text[i] != '-') {
            if (input_label_text[i] == '.') {
                is_dot_input = true;
            }
            i--;
        }
        is_num_input = true;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DIGITS
void MainWindow::clickedButtonDigits() {
    if (is_calc_done == true) {
        on_pushButton_AC_clicked();
    }

    QPushButton* button = (QPushButton*)sender();

    if (ui->label_input->text() == "0" || ui->label_input->text() == "") {
        ui->label_input->setText(button->text());
    } else {
        if (is_close_bracket_input == true) {
            ui->pushButton_op_mult->click();
        }
        ui->label_input->setText(ui->label_input->text() + button->text());
    }
    is_num_input = true;
    is_op_input = false;
    is_u_minus_input = false;
    is_open_bracket_input = false;
    is_close_bracket_input = false;
}

void MainWindow::on_pushButton_dot_clicked() {
    if (is_calc_done == true) {
        on_pushButton_AC_clicked();
    }

    if (is_dot_input == false) {
        if (is_num_input == false) {
            ui->pushButton_0->click();
        }
        ui->label_input->setText(ui->label_input->text() + '.');
        is_dot_input = true;
        is_op_input = false;
        is_open_bracket_input = false;
        is_close_bracket_input = false;
    }
}

void MainWindow::on_pushButton_var_clicked() {
    ui->doubleSpinBox->setEnabled(true);
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

    if (is_op_input == false) {
        if (last_input_char == ".") {
            ui->pushButton_0->click();
        }

        if (ui->label_input->text() == "0" && button_text == "-") {
            unaryMinusInput();
        } else if (is_open_bracket_input == false) {
            operatorInput(button_text);
        }
    } else {  // is_op_input == true
        if (ui->label_input->text() == "-" && button_text != "-") {
            unaryMinusChanging();
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
}

void MainWindow::operatorInput(QString button_text) {
    ui->label_input->setText(ui->label_input->text() + " " + button_text + " ");
    is_num_input = false;
    is_dot_input = false;
    is_op_input = true;
    is_open_bracket_input = false;
    is_close_bracket_input = false;
}

void MainWindow::unaryMinusChanging() {
    on_pushButton_delete_prev_clicked();
    ui->pushButton_0->click();
    is_op_input = false;
    is_open_bracket_input = false;
    is_close_bracket_input = false;
}

void MainWindow::on_pushButton_op_pow_clicked() {
    if (is_calc_done == true) {
        on_pushButton_AC_clicked();
    }

    if (is_num_input == true || is_close_bracket_input == true || ui->label_input->text() == "0") {
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
    } else if (is_u_minus_input == true || is_mfunc_input == true || is_open_bracket_input == true || is_pow_input == true) {
        ui->label_input->setText(ui->label_input->text() + "(");
    } else {
        ui->pushButton_op_mult->click();
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

    if (brackets_counter > 0 && is_op_input == false && is_u_minus_input == false && is_open_bracket_input == false) {
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

    if (button_text == "√")
        button_text = "sqrt";  //!!!!!

    if (ui->label_input->text() == "0") {
        ui->label_input->setText(button_text);
    } else {
        if (is_num_input == true) {
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

    QString input_label_text = ui->label_input->text();
    char* str_for_calc = new char(input_label_text.length());
    QByteArray tmp_byte_array = input_label_text.toLatin1();
    strlcpy(str_for_calc, tmp_byte_array, input_label_text.length() + 1);

    double variable = 0;
    double result = 0.0;
    node_t* q_root = NULL;
    int error = convert_infix_to_RPN(str_for_calc, &q_root);
    if (error == OK) {
        error = evaluate_expression(q_root, variable, &result);
    }

    QString result_string;
    if (error == OK) {
        result_string = QString::number(result);
    } else {
        ERRORS_MESSAGES;
        result_string = errors_msg[error];
    }

    ui->label_output->setText(result_string);
    is_calc_done = true;
    delete str_for_calc;
}

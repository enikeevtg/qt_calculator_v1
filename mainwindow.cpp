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

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(clickedButtonOperations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(clickedButtonOperations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(clickedButtonOperations()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(clickedButtonOperations()));

//    disconnect(ui->pushButton_open_bracket, SIGNAL(clicked()), this, SLOT(brackets_buttons()));
//    disconnect(ui->pushButton_close_bracket, SIGNAL(clicked()), this, SLOT(brackets_buttons()));

    ui->doubleSpinBox->setEnabled(false);
    ui->doubleSpinBox->setMaximum(std::numeric_limits<double>::max());
    ui->doubleSpinBox->setMinimum(-std::numeric_limits<double>::max());
    ui->doubleSpinBox->setDecimals(7);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_AC_clicked() {
    ui->label_input->setText("0");
    ui->label_output->setText("");
    is_num_input = true;
    is_dot_input = false;
    is_op_input = false;
    is_math_func_input = false;
    is_calc_done = false;

    is_num_input = true;
    is_dot_input = false;
    is_op_input = false;
    is_u_minus_input = false;
    is_close_bracket_input = true;
    brackets_counter = 0;
    is_math_func_input = false;
    is_calc_done = false;
}

void MainWindow::clickedButtonDigits() {
    if (is_calc_done == true) {
        on_pushButton_AC_clicked();
        is_calc_done = false;
    }

    QPushButton* button = (QPushButton*)sender();

    if (ui->label_input->text() == "0") {
        ui->label_input->setText(button->text());
    } else {
        if (is_close_bracket_input == true) {
            ui->pushButton_mult->click();
        }
        ui->label_input->setText(ui->label_input->text() + button->text());
    }
    is_num_input = true;
    is_op_input = false;
    is_u_minus_input = false;
    is_close_bracket_input = false;
}

void MainWindow::on_pushButton_dot_clicked() {
    if (is_calc_done == true) {
        on_pushButton_AC_clicked();
        is_calc_done = false;
    }

    if (is_dot_input == false) {
        if (is_num_input == false) {
            ui->pushButton_0->click();
        }
        ui->label_input->setText(ui->label_input->text() + '.');
        is_dot_input = true;
        is_op_input = false;
    }
}

void MainWindow::clickedButtonOperations() {
    if (is_calc_done == true) {
        on_pushButton_AC_clicked();
        is_calc_done = false;
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
            ui->label_input->setText(button_text);
            is_u_minus_input = true;
        } else if (last_input_char == "(" && button_text == "-") {
            ui->label_input->setText(ui->label_input->text() + button_text);
            is_u_minus_input = true;
        } else if (last_input_char != "(") {
            ui->label_input->setText(ui->label_input->text() + " " + button_text + " ");
        }
        is_op_input = true;
    } else {
        if (ui->label_input->text() == "-" && button_text != "-") {
            on_pushButton_delete_prev_clicked();
            ui->pushButton_0->click();
        } else if (is_u_minus_input == false) {
            on_pushButton_delete_prev_clicked();
            ui->label_input->setText(ui->label_input->text() + " " + button_text + " ");
            is_op_input = true;
        }
    }
    is_num_input = false;
    is_dot_input = false;
    is_close_bracket_input = false;
    is_math_func_input = false;
}

void MainWindow::on_pushButton_open_bracket_clicked() {
    if (is_calc_done == true) {
        on_pushButton_AC_clicked();
        is_calc_done = false;
    }

    QString last_input_char = ui->label_input->text().last(1);

    if (ui->label_input->text() == "0") {
        ui->label_input->setText("(");
    } else if (is_u_minus_input == true) {
        ui->label_input->setText(ui->label_input->text() + "(");
        is_u_minus_input = false;
    } else {
        if (last_input_char != " ") {
            ui->pushButton_mult->click();
        }
        ui->label_input->setText(ui->label_input->text() + "(");
    }

    brackets_counter++;
    is_num_input = false;
    is_dot_input = false;
    is_op_input = false;
    is_u_minus_input = false;
    is_close_bracket_input = false;
    is_math_func_input = false;
    is_calc_done = false;
}

void MainWindow::on_pushButton_close_bracket_clicked() {
    if (is_calc_done == true) {
        on_pushButton_AC_clicked();
        is_calc_done = false;
    }

    QString last_input_char = ui->label_input->text().last(1);

    if (brackets_counter > 0 && ui->label_input->text() != "0" && is_u_minus_input == false && last_input_char != " ") {
        if (last_input_char == ".") {
            ui->pushButton_0->click();
        }
        ui->label_input->setText(ui->label_input->text() + ")");

        brackets_counter--;
        is_num_input = false;
        is_dot_input = false;
        is_close_bracket_input = true;
    }
}


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

void MainWindow::on_pushButton_delete_prev_clicked() {
    if (is_calc_done == true) {
        on_pushButton_AC_clicked();
    }

    QString input_label_text = ui->label_input->text();
    size_t input_text_length = input_label_text.length();

    if (input_text_length == 1) {
        ui->label_input->setText("0");
    } else {
        QString last_input_char = input_label_text.last(1);
        int reducing_size = 1;
        if (last_input_char == " ") {
            reducing_size = 3;

            if (input_label_text[input_text_length - reducing_size] != ')') {
                is_num_input = false;
            } else {
                is_num_input = true;
                is_dot_input = false;
            }
            is_op_input = false;
        } else {
            while (input_label_text[input_text_length - reducing_size] != ' ' &&
                   input_label_text[input_text_length - reducing_size] != '(' &&
                   input_label_text[input_text_length - reducing_size] != ')' &&
                   reducing_size < (int)input_text_length) {
                reducing_size++;
            }
            is_num_input = false;
            is_op_input = true;
        }

//        int reducing_size = 1;

//        if (last_input_char == ".") {
//            is_num_input = true;
//            is_dot_input = false;
//        } else if (last_input_char == " ") {
//            reducing_size = 3;
//            is_num_input = true;
//            is_op_input = false;
//        } else if (last_input_char == "(") {
//            reducing_size++;
//            while (input_label_text[input_text_length - reducing_size] != ' ' &&
//                   input_label_text[input_text_length - reducing_size] != '(' &&
//                   input_label_text[input_text_length - reducing_size] != ')') {
//                reducing_size++;
//            }
//        }

        input_label_text.resize(input_text_length - reducing_size);
        if (input_label_text == "") input_label_text = "0";
        ui->label_input->setText(input_label_text);
    }
}

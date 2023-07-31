#ifndef DEPOSITCALCWINDOW_H
#define DEPOSITCALCWINDOW_H

#include <QMainWindow>

namespace Ui {
class DepositCalcWindow;
}

class DepositCalcWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DepositCalcWindow(QWidget *parent = nullptr);
    ~DepositCalcWindow();

private:
    Ui::DepositCalcWindow *ui;
};

#endif // DEPOSITCALCWINDOW_H

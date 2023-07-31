#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow window_smart_calc;
  window_smart_calc.setFixedSize(1090, 688);
  window_smart_calc.show();
  return app.exec();
}

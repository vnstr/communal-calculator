#include <QApplication>
#include <iostream>

#include "ui/main_window.h"

int main(int argc, char **argv) {
  try {
    QApplication app(argc, argv);

    Calc::Ui::MainWindow main_window;
    main_window.show();

    return app.exec();
  } catch (...) {
    std::cout << "Error: fatal: unhandled exception" << std::endl;
  }

  return 1;
}

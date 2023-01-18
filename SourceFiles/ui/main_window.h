#ifndef SOURCEFILES_UI_MAIN_WINDOW_H_
#define SOURCEFILES_UI_MAIN_WINDOW_H_

#include <QMainWindow>

namespace Ui {
class MainWindow;
};

namespace Calc {
namespace Ui {

class MainWindow final : public QMainWindow {
 public:
  explicit MainWindow(QWidget *parent = nullptr,
                      Qt::WindowFlags flags = Qt::WindowFlags());
  ~MainWindow();

 private slots:
  void OnCalculateButtonClicked();

 private:
  ::Ui::MainWindow *ui_{nullptr};
};

};  // namespace Ui
};  // namespace Calc

#endif  // SOURCEFILES_UI_MAIN_WINDOW_H_

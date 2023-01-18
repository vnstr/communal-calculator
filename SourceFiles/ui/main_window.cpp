#include "ui/main_window.h"

#include <QPushButton>

#include "core/communal_calculator.h"
#include "ui/ui_mainwindow.h"

namespace Calc {
namespace Ui {

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags), ui_(new ::Ui::MainWindow) {
  ui_->setupUi(this);

  connect(ui_->calculateButton, &QPushButton::clicked, this,
          &MainWindow::OnCalculateButtonClicked);
}

MainWindow::~MainWindow() {
  delete ui_;
  ui_ = nullptr;
}

void MainWindow::OnCalculateButtonClicked() {
  CommunalCalculator::Communal communal;

  communal.hotWaterTariff = ui_->hotWaterTariffLineEdit->text().toFloat();
  communal.previousHotWater = ui_->hotWaterPreviousLineEdit->text().toFloat();
  communal.currentHotWater = ui_->hotWaterCurrentLineEdit->text().toFloat();

  communal.coldWaterTariff = ui_->coldWaterTariffLineEdit->text().toFloat();
  communal.previousColdWater = ui_->coldWaterPreviousLineEdit->text().toFloat();
  communal.currentColdWater = ui_->coldWaterCurrentLineEdit->text().toFloat();

  communal.waterSinkTariff = ui_->waterSinkTariffLineEdit->text().toFloat();

  communal.t1Tariff = ui_->t1TariffLineEdit->text().toFloat();
  communal.previosT1 = ui_->t1PreviousLineEdit->text().toFloat();
  communal.currentT1 = ui_->t1CurrentLineEdit->text().toFloat();

  communal.t2Tariff = ui_->t2TariffLineEdit->text().toFloat();
  communal.previosT2 = ui_->t2PreviousLineEdit->text().toFloat();
  communal.currentT2 = ui_->t2CurrentLineEdit->text().toFloat();

  communal.t3Tariff = ui_->t3TariffLineEdit->text().toFloat();
  communal.previosT3 = ui_->t3PreviousLineEdit->text().toFloat();
  communal.currentT3 = ui_->t3CurrentLineEdit->text().toFloat();

  CommunalCalculator calc(communal);
  auto result = calc.CalculateSummary();
  ui_->resultLabel->setText(QString::number(result));
}

};  // namespace Ui
};  // namespace Calc

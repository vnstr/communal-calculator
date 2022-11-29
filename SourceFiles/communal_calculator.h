#ifndef SOURCEFILES_COMMUNAL_CALCULATOR_H_
#define SOURCEFILES_COMMUNAL_CALCULATOR_H_

#include <string>
#include <filesystem>

class CommunalCalculator final {
 public:
  static void GenFile(const std::filesystem::path & = "example.communal");

  bool Init(const std::filesystem::path &);
  float CalculateSummary() const;

 private:
  float hotWaterTariff_{0};
  float coldWaterTariff_{0};
  float waterSinkTariff_{0};

  float previousHotWater_{0};
  float previousColdWater_{0};

  float currentHotWater_{0};
  float currentColdWater_{0};

  float previosT1_{0};
  float previosT2_{0};
  float previosT3_{0};

  float currentT1_{0};
  float currentT2_{0};
  float currentT3_{0};
};

#endif  // SOURCEFILES_COMMUNAL_CALCULATOR_H_


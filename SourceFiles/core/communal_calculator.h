#ifndef SOURCEFILES_CORE_COMMUNAL_CALCULATOR_H_
#define SOURCEFILES_CORE_COMMUNAL_CALCULATOR_H_

#include <filesystem>
#include <string>

class CommunalCalculator final {
 public:
  struct Communal {
    float hotWaterTariff{0};
    float coldWaterTariff{0};
    float waterSinkTariff{0};

    float t1Tariff{0};
    float t2Tariff{0};
    float t3Tariff{0};

    float previousHotWater{0};
    float previousColdWater{0};

    float currentHotWater{0};
    float currentColdWater{0};

    float previosT1{0};
    float previosT2{0};
    float previosT3{0};

    float currentT1{0};
    float currentT2{0};
    float currentT3{0};
  };

  static void GenFile(const std::filesystem::path & = "example.communal");

  explicit CommunalCalculator(const Communal &);

  bool Init(const std::filesystem::path &);
  float CalculateSummary() const;

 private:
  Communal communal_;
};

#endif  // SOURCEFILES_CORE_COMMUNAL_CALCULATOR_H_

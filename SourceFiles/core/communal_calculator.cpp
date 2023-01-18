#include "core/communal_calculator.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <optional>
#include <sstream>
#include <utility>

const char *kGenFileContent =
    "hotWaterTariff: 176.83\n"
    "coldWaterTariff: 45.88\n"
    "waterSinkTariff: 35.5\n"
    "\n"
    "T1Tariff: 1\n"
    "T2Tariff: 1\n"
    "T3Tariff: 1\n"
    "\n"
    "previousHotWater: 93.150\n"
    "previousColdWater: 170.116\n"
    "\n"
    "currentHotWater: 100.340\n"
    "currentColdWater: 179.559\n"
    "\n"
    "previosT1: 881.15\n"
    "previosT2: 477.34\n"
    "previosT3: 1035.49\n"
    "\n"
    "currentT1: 906.32\n"
    "currentT2: 492.38\n"
    "currentT3: 1080.24\n";

static std::optional<float> GetNumber(const std::string &str,
                                      const std::string &key) {
  auto pos = str.find(key);
  if (pos == std::string::npos) {
    return {};
  }

  auto first = str.cbegin();
  std::advance(first, pos + key.size());
  while (first != str.cend() && std::isspace(*first)) {
    ++first;
  }

  auto last = first;
  if (last == str.cend()) {
    return {};
  }

  while (last != str.cend() && (std::isdigit(*last) || *last == '.')) {
    ++last;
  }

  std::string number_str(first, last);

  try {
    return std::stof(number_str);
  } catch (...) {
  }

  return {};
}

static std::string ToString(float nb) {
  int integer = std::floor(nb);
  int fractional = std::round(std::fabs(nb - integer) * 1000);

  std::string str;
  str.reserve(32);

  str = std::to_string(integer);
  str += ".";
  str += std::to_string(fractional);

  return str;
}

static float CalcSummary(float a, float b, float tariff, const char *name,
                         float *out_diff = nullptr) {
  assert(name);

  std::string msg;
  msg.reserve(256);

  msg = name;
  msg += " = |";
  msg += ToString(a);
  msg += " - ";
  msg += ToString(b);
  msg += "| * ";
  msg += ToString(tariff);
  msg += " = ";

  float diff = std::fabs(a - b);
  if (out_diff) {
    *out_diff = diff;
  }

  msg += ToString(diff);
  msg += " * ";
  msg += ToString(tariff);
  msg += " = ";

  float summary = diff * tariff;
  msg += ToString(summary);

  std::cout << msg << std::endl;
  return summary;
}

void CommunalCalculator::GenFile(const std::filesystem::path &filename) {
  std::ofstream file;

  file.open(filename, std::fstream::out | std::fstream::trunc);
  if (!file.is_open()) {
    std::cout << "Error: unable to create \"";
    std::cout << filename.u8string();
    std::cout << "\"";
    std::cout << std::endl;
    return;
  }

  file << kGenFileContent << std::endl;
}

CommunalCalculator::CommunalCalculator(const Communal &communal)
    : communal_(communal) {}

bool CommunalCalculator::Init(const std::filesystem::path &filename) {
  std::ifstream file;

  file.open(filename);
  if (!file.is_open()) {
    std::cout << "Error: unable to open \"";
    std::cout << filename.u8string();
    std::cout << "\"";
    std::cout << std::endl;
    return false;
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  auto text = buffer.str();

  std::string err_msg;
  err_msg.reserve(128);

  auto get_number = [&text, &err_msg](float *out, const char *key) {
    auto opt_nb = GetNumber(text, key);
    if (!opt_nb) {
      err_msg += err_msg.empty() ? "Error: unable to find: \"" : ", \"";
      err_msg += key;
      err_msg += "\"";
      return false;
    }

    *out = opt_nb.value();
    return true;
  };

  bool result = get_number(&communal_.hotWaterTariff, "hotWaterTariff:");
  result = get_number(&communal_.coldWaterTariff, "coldWaterTariff:") && result;
  result = get_number(&communal_.waterSinkTariff, "waterSinkTariff:") && result;
  result = get_number(&communal_.t1Tariff, "T1Tariff:") && result;
  result = get_number(&communal_.t2Tariff, "T2Tariff:") && result;
  result = get_number(&communal_.t3Tariff, "T3Tariff:") && result;

  result =
      get_number(&communal_.previousHotWater, "previousHotWater:") && result;
  result =
      get_number(&communal_.previousColdWater, "previousColdWater:") && result;

  result = get_number(&communal_.currentHotWater, "currentHotWater:") && result;

  result =
      get_number(&communal_.currentColdWater, "currentColdWater:") && result;

  result = get_number(&communal_.previosT1, "previosT1:") && result;
  result = get_number(&communal_.previosT2, "previosT2:") && result;
  result = get_number(&communal_.previosT3, "previosT3:") && result;
  result = get_number(&communal_.currentT1, "currentT1:") && result;
  result = get_number(&communal_.currentT2, "currentT2:") && result;
  result = get_number(&communal_.currentT3, "currentT3:") && result;

  if (!result) {
    std::cout << err_msg << std::endl;
  }

  return result;
}

float CommunalCalculator::CalculateSummary() const {
  float hot_water_diff = 0;
  auto hot_water =
      CalcSummary(communal_.currentHotWater, communal_.previousHotWater,
                  communal_.hotWaterTariff, "HotWaterSummary", &hot_water_diff);

  float cold_water_diff = 0;
  auto cold_water = CalcSummary(
      communal_.currentColdWater, communal_.previousColdWater,
      communal_.coldWaterTariff, "ColdWaterSummary", &cold_water_diff);

  std::string msg;
  msg.reserve(128);

  msg = "WaterSinkSummary = (";
  msg += ToString(hot_water_diff);
  msg += " + ";
  msg += ToString(cold_water_diff);
  msg += ") * ";
  msg += ToString(communal_.waterSinkTariff);
  msg += " = ";

  float water_sink =
      (hot_water_diff + cold_water_diff) * communal_.waterSinkTariff;

  msg += ToString(water_sink);
  std::cout << msg << std::endl;

  auto t1_summary = CalcSummary(communal_.currentT1, communal_.previosT1,
                                communal_.t1Tariff, "T1Summary");

  auto t2_summary = CalcSummary(communal_.currentT2, communal_.previosT2,
                                communal_.t2Tariff, "T2Summary");

  auto t3_summary = CalcSummary(communal_.currentT3, communal_.previosT3,
                                communal_.t3Tariff, "T3Summary");

  float summary = hot_water + cold_water + water_sink + t1_summary +
                  t2_summary + t3_summary;

  msg = "Summary = ";
  msg += ToString(summary);
  std::cout << msg << std::endl;

  return summary;
}

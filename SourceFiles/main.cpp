#include <iostream>
#include <string>

#include "communal_calculator.h"

const char *kHelpText =
    "usage: communal_calculator [--gen] [--help] [<filepath>]\n"
    "\n"
    "only one argument by calling\n"
    "[--gen]     generates example file\n"
    "[--help]    prints help info\n"
    "<filepath>  calculates summary from file";

void PrintHelp() {
  std::cout << kHelpText << std::endl;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    PrintHelp();
    return 0;
  }

  std::string arg(argv[1]);

  if (arg == "--gen") {
    CommunalCalculator::GenFile();
    return 0;
  }

  if (arg == "--help") {
    PrintHelp();
    return 0;
  }

  CommunalCalculator calc;
  if (calc.Init(arg)) {
    calc.CalculateSummary();
  }

  return 0;
}


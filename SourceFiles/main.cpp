#include "view/guid_application.h"

inline constexpr char const *kMainQmlPath = "qrc:/qml/Main.qml";

auto main(int argc, char *argv[]) -> int {
  auto model = std::make_shared<CommunalCalculator::Core::Model>();

  auto model_view = std::make_shared<CommunalCalculator::ModelView>();
  model_view->ConnectModel(model);

  CommunalCalculator::GuidApplication application(argc, argv, model_view);
  return application.Start(kMainQmlPath);
}

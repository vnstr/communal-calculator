#include "model_view/model_view.h"

namespace CommunalCalculator {

void ModelView::ConnectModel(const std::shared_ptr<Core::Model> &model_view) {
  model_ = model_view;
}

auto ModelView::onCalculateSummary(const QMap<QString, QVariant> &values)
    -> int {
  return 0;
}

}  // namespace CommunalCalculator

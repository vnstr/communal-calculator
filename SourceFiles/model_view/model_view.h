#ifndef SOURCEFILES_MODEL_VIEW_MODEL_VIEW_H_
#define SOURCEFILES_MODEL_VIEW_MODEL_VIEW_H_

#include <QMap>
#include <QObject>
#include <QString>
#include <QVariant>
#include <memory>

#include "core/model.h"

namespace CommunalCalculator {

class ModelView : public QObject {
  Q_OBJECT

 public:
  ModelView() = default;
  ModelView(const ModelView &) = delete;
  ModelView(ModelView &&) = delete;

  auto operator=(const ModelView &) -> ModelView & = delete;
  auto operator=(ModelView &&) -> ModelView & = delete;

  ~ModelView() override = default;

  void ConnectModel(const std::shared_ptr<Core::Model> &model_view);

 public slots:
  virtual auto onCalculateSummary(const QMap<QString, QVariant> &values) -> int;

 private:
  std::shared_ptr<Core::Model> model_;
};

}  // namespace CommunalCalculator

#endif  // SOURCEFILES_MODEL_VIEW_MODEL_VIEW_H_

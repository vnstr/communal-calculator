#ifndef SOURCEFILES_UI_WINDOW_H_
#define SOURCEFILES_UI_WINDOW_H_

#include <memory>

namespace UI {

class Window {
 public:
  static std::unique_ptr<Window> Create();

  Window() = default;
  Window(const Window &) = delete;
  Window(const Window &&) = delete;
  Window &operator=(const Window &) = delete;
  Window &operator=(const Window &&) = delete;
  virtual ~Window() = default;
};

};

#endif  // SOURCEFILES_UI_WINDOW_H_


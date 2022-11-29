#include "ui/window.h"

#include <cassert>

#ifdef __APPLE__
#include "platform/macos/window_macos.h"
#endif

using Window = UI::Window;

std::unique_ptr<Window> Window::Create() {
#ifdef __APPLE__
  return std::make_unique<Platform::UI::Window>();
#endif
  return {};
}


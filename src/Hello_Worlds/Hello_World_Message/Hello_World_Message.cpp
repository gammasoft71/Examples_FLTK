#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

auto main(int argc, char *argv[]) -> int {
  auto window = Fl_Window {200, 100, 300, 300, "Hello world (message)"};
  
  auto button = Fl_Button {10, 10, 75, 25, "Click me"};
  button.callback([](Fl_Widget* sender, void* window) {
    fl_message("Hello, World!");
  });
  
  window.show(argc, argv);
  return Fl::run();
}

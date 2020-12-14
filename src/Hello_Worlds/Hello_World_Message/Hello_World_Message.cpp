#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

int main(int argc, char *argv[]) {
  Fl_Window window(200, 100, 300, 300, "Hello world (message)");
  
  Fl_Button button(10, 10, 75, 25, "Click me");
  button.callback([](Fl_Widget* sender, void* window) {
    fl_message("Hello, World!");
  });
  
  window.show(argc, argv);
  return Fl::run();
}

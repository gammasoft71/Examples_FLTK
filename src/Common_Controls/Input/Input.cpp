#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Input example") {
      input1.value("input text");
      input1.when(FL_WHEN_CHANGED);
      input1.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->input2.value(reinterpret_cast<Main_Window*>(window)->input1.value());
      }, this);
      
      input2.value("input text");
      input2.when(FL_WHEN_CHANGED);
      input2.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->input1.value(reinterpret_cast<Main_Window*>(window)->input2.value());
      }, this);
    }
    
  private:
    Fl_Input input1 {10, 10, 100, 25};
    Fl_Input input2 {10, 50, 100, 25};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

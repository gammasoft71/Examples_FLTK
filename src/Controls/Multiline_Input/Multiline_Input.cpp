#include <FL/Fl.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Multiline input example"} {
      input1.value("Line 1\nLnine 2\nLine 3\n...");
      input1.when(FL_WHEN_CHANGED);
      input1.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->input2.value(reinterpret_cast<Main_Window*>(window)->input1.value());
      }, this);
      
      input2.value("Line 1\nLnine 2\nLine 3\n...");
      input2.when(FL_WHEN_CHANGED);
      input2.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->input1.value(reinterpret_cast<Main_Window*>(window)->input2.value());
      }, this);
    }
    
  private:
    Fl_Multiline_Input input1 {10, 10, 280, 135};
    Fl_Multiline_Input input2 {10, 155, 280, 135};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

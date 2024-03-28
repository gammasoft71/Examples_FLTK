#include <FL/Fl.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <string>

using namespace std::literals;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Light button example"} {
      light_button1.when(FL_WHEN_CHANGED);
      light_button1.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Light_Button*>(sender)->value(false);
      }, this);

      light_button2.value(true);
      light_button2.when(FL_WHEN_CHANGED);
      light_button2.callback([](Fl_Widget* sender, void* window) {
        auto label = "Button 2 is "s + (reinterpret_cast<Fl_Light_Button*>(sender)->value() ? "on" : "off");
        reinterpret_cast<Main_Window*>(window)->box1.copy_label(label.c_str());
      }, this);

      light_button3.when(FL_WHEN_CHANGED);

      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    }
    
  private:
    Fl_Light_Button light_button1 {30, 30, 75, 25, "Button 1"};
    Fl_Light_Button light_button2 {30, 60, 75, 25, "Button 2"};
    Fl_Light_Button light_button3 {30, 90, 75, 25, "Button 3"};
    Fl_Box box1{30, 120, 180, 25, "Button 2 is on"};
  };
}
  
auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

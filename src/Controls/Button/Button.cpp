#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Window.H>
#include <string>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Button example"} {
      button1.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button1.callback([](Fl_Widget* sender, void* window) {
        auto result = "Button 1 clicked " + to_string(++reinterpret_cast<Main_Window*>(window)->button1_clicked) + " times";
        reinterpret_cast<Main_Window*>(window)->box1.copy_label(result.c_str());
      }, this);
      
      button2.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button2.callback([](Fl_Widget* sender, void* window) {
        auto result = "Button 2 clicked " + to_string(++reinterpret_cast<Main_Window*>(window)->button2_clicked) + " times";
        reinterpret_cast<Main_Window*>(window)->box2.copy_label(result.c_str());
      }, this);
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box2.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Button button1 {50, 50, 75, 25, "Button 1"};
    Fl_Repeat_Button button2 {50, 100, 200, 75, "Button 2"};
    Fl_Box box1 {50, 200, 200, 20, "Button 1 clicked 0 times"};
    Fl_Box box2 {50, 230, 200, 25, "Button 2 clicked 0 times"};
    int button1_clicked = 0;
    int button2_clicked = 0;
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

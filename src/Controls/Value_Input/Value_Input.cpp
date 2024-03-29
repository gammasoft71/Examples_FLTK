#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Fill_Dial.H>
#include <FL/Fl_Line_Dial.H>
#include <FL/Fl_Window.H>
#include <string>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Value input example"} {
      value_input1.bounds(0, 1);
      value_input1.value(0.5);
      value_input1.step(0.01);
      value_input1.callback(on_value_changed, &box1);
      value_input1.do_callback();
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    static void on_value_changed(Fl_Widget* sender, void* box) noexcept {
      static auto result = string(' ', 128);
      dynamic_cast<Fl_Valuator*>(sender)->format(result.data());
      reinterpret_cast<Fl_Widget*>(box)->copy_label(result.c_str());
    }

    Fl_Value_Input value_input1 {10, 10, 100, 25};
    Fl_Box box1 {FL_DOWN_BOX, 120, 10, 90, 25, ""};
  };
}

auto main(int argc, char* argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  Fl::run();
}

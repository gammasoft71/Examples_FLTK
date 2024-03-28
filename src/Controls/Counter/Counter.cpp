#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Counter.H>
#include <FL/Fl_Simple_Counter.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Counter example"} {
      counter1.bounds(0, 1);
      counter1.value(0.5);
      counter1.callback(on_value_changed, &box1);
      counter1.do_callback();
      
      simple_counter1.bounds(10, 11);
      simple_counter1.value(10);
      simple_counter1.callback(on_value_changed, &box2);
      simple_counter1.do_callback();
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box2.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    static void on_value_changed(Fl_Widget* sender, void* box) noexcept {
      static auto result = string(' ', 128);
      static_cast<Fl_Valuator*>(sender)->format(result.data());
      reinterpret_cast<Fl_Widget*>(box)->copy_label(result.c_str());
    }

    Fl_Counter counter1 {10, 10, 180, 25};
    Fl_Box box1 {FL_DOWN_BOX, 200, 10, 90, 25, ""};
    Fl_Simple_Counter simple_counter1 {10, 50, 180, 25};
    Fl_Box box2 {FL_DOWN_BOX, 200, 50, 90, 25, ""};
  };
}

auto main(int argc, char* argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  Fl::run();
}

#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Dial.H>
#include <FL/Fl_Fill_Dial.H>
#include <FL/Fl_Line_Dial.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::literals;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Dial example") {
      end();
      
      dial1.bounds(0, 1);
      dial1.value(0.5);
      dial1.callback(on_value_changed, &box1);
      dial1.do_callback();
      
      line_dial1.bounds(10, 11);
      line_dial1.value(10);
      line_dial1.callback(on_value_changed, &box2);
      line_dial1.do_callback();
      
      fill_dial1.bounds(0, 100);
      fill_dial1.value(50);
      fill_dial1.callback(on_value_changed, &box3);
      fill_dial1.do_callback();
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box2.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box3.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    static void on_value_changed(Fl_Widget* sender, void* box) {
      static string result(' ', 128);
      dynamic_cast<Fl_Valuator*>(sender)->format(result.data());
      reinterpret_cast<Fl_Widget*>(box)->copy_label(result.c_str());
    }

    Fl_Dial dial1 {10, 10, 75, 75};
    Fl_Box box1 {FL_DOWN_BOX, 95, 35, 90, 25, ""};
    Fl_Line_Dial line_dial1 {10, 95, 75, 75};
    Fl_Box box2 {FL_DOWN_BOX, 95, 120, 90, 25, ""};
    Fl_Fill_Dial fill_dial1 {10, 180, 75, 75, ""};
    Fl_Box box3 {FL_DOWN_BOX, 95, 205, 90, 25, ""};
  };
}

int main(int argc, char* argv[]) {
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}

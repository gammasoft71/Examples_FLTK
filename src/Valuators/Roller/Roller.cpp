#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Roller.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Roller example") {
      end();
      
      roller1.bounds(0, 1);
      roller1.value(0.5);
      roller1.step(0.01);
      roller1.type(FL_HORIZONTAL);
      roller1.callback(on_value_changed, &box1);
      roller1.do_callback();
      
      roller2.bounds(10, 11);
      roller2.value(10);
      roller2.step(0.01);
      roller2.callback(on_value_changed, &box2);
      roller2.do_callback();
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box2.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    static void on_value_changed(Fl_Widget* sender, void* box) {
      static string result(' ', 128);
      dynamic_cast<Fl_Valuator*>(sender)->format(result.data());
      reinterpret_cast<Fl_Widget*>(box)->copy_label(result.c_str());
    }

    Fl_Roller roller1 {10, 10, 100, 25};
    Fl_Box box1 {FL_DOWN_BOX, 120, 10, 90, 25, ""};
    Fl_Roller roller2 {45, 45, 25, 100};
    Fl_Box box2 {FL_DOWN_BOX, 120, 80, 90, 25, ""};
  };
}

int main(int argc, char* argv[]) {
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}

#include <iomanip>
#include <iostream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Spinner.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Spinner example") {
      end();
      resizable(this);
      
      spinner1.range(0, 100);
      spinner1.value(50);
      spinner1.callback([](Fl_Widget* sender, void* data) {
        reinterpret_cast<Fl_Widget*>(data)->copy_label(to_string(static_cast<int>(dynamic_cast<Fl_Spinner*>(sender)->value())).c_str());
      }, &box1);
      spinner1.do_callback();
      
      spinner2.format("%.2f");
      spinner2.minimum(10.0);
      spinner2.maximum(11.0);
      spinner2.step(0.01);
      spinner2.value(10);
      spinner2.callback([](Fl_Widget* sender, void* data) {
        cout << "value = " << fixed << setprecision(2) << dynamic_cast<Fl_Spinner*>(sender)->value() << endl;
      });
      spinner2.do_callback();
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    Fl_Spinner spinner1 {80, 50, 120, 25};
    Fl_Spinner spinner2 {80, 100, 120, 25};
    Fl_Box box1 {80, 150, 75, 25};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

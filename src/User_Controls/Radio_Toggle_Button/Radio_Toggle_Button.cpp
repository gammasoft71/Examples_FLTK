#include <sstream>
#include <FL/Fl.H>
#include "Fl_Radio_Toggle_Button.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Radio toggle button example") {
      radioButton1.auto_check(false);
      radioButton1.state(FL_CHECKED);
      radioButton1.callback([](Fl_Widget* sender, void* window) {
        // Uncomments next line to check / uncheck radio button 1 (auto_check is false...)
        //dynamic_cast<Fl_Radio_Toggle_Button*>(sender)->state(!dynamic_cast<Fl_Radio_Toggle_Button*>(sender)->state());
      }, this);

      radioButton2.state(FL_CHECKED);

      radioButton3.when(FL_WHEN_CHANGED);
      radioButton3.callback([](Fl_Widget* sender, void* window) {
        stringstream ss;
        ss << "Radio 3 checked = " << boolalpha << (dynamic_cast<Fl_Radio_Toggle_Button*>(sender)->state() == FL_CHECKED);
        reinterpret_cast<Main_Window*>(window)->box1.copy_label(ss.str().c_str());
      }, this);

      radioButton4.toggle_button(true);
      radioButton4.copy_label("Radio 4");

      radioButton5.auto_check(false);
      radioButton5.state(FL_CHECKED);
      radioButton5.toggle_button(true);
      radioButton5.callback([](Fl_Widget* sender, void* window) {
        // Uncomments next line to check / uncheck radio button 5 (auto_check is false...)
        //dynamic_cast<Fl_Radio_Toggle_Button*>(sender)->state(!dynamic_cast<Fl_Radio_Toggle_Button*>(sender)->state());
      }, this);
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    }
    
  private:
    Fl_Radio_Toggle_Button radioButton1 {30, 30, 110, 23, "Radio 1"};
    Fl_Radio_Toggle_Button radioButton2 {30, 60, 110, 23, "Radio 2"};
    Fl_Radio_Toggle_Button radioButton3 {30, 90, 110, 23, "Radio 3"};
    Fl_Radio_Toggle_Button radioButton4 {30, 120, 110, 23};
    Fl_Radio_Toggle_Button radioButton5 {30, 150, 110, 23, "Radio 5"};
    Fl_Box box1{30, 180, 180, 23, "Radio 3 checked = false"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

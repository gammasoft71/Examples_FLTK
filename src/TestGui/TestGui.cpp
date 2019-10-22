#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Device.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::literals;

int main() {
  setenv("FLTK_SCHEME", "gtk+", 1);
  Fl::get_system_colors();
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  Fl::scheme(nullptr);

  static Fl_Window form_hidden(1000, 10000, 0, 0, nullptr);
  form_hidden.show();
  Fl_Window form(200, 100, 300, 300, "TestGui");
  form.show();
  
  Fl::run();
  
  
  
}

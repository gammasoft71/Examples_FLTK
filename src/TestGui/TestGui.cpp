#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::literals;

int main() {
  //setenv("FLTK_SCHEME", "gtk+", 1);
  Fl::get_system_colors();
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  Fl::scheme(nullptr);

  Fl_Window form(200, 100, 390, 270, "TestGui");
  {
    form.label("New title"s.c_str());
  }
  Fl_Button button(10, 10, 75, 25, "Start");
  form.show();

  Fl::run();
}

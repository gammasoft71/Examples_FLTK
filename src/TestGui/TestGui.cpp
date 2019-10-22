#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <FL/Fl.H>
#include <FL/fl_ask.H>
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

  Fl_Window form(200, 100, 300, 300, "TestGui");
  
  Fl_Button button(10, 10, 75, 25, "Click me");
  button.callback([](Fl_Widget* sender, void* form) {
    //fl_message_title("My title");
    fl_message_icon()->label("X");
    fl_message_icon()->color(fl_rgb_color(255, 0, 0));
    fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
    cout << "result = " << fl_choice("Hello, World!", nullptr, fl_ok, fl_cancel) << endl;
  }, &form);

  form.show();

  Fl::run();
}

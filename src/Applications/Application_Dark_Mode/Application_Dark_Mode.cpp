#include "Fl_Scheme_Mode.h"
#include <initializer_list>
#include <map>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/fl_message.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "") {
      end();

      button1.callback([](Fl_Widget* sender, void* window) {
        fl_message_hotspot(false);
        fl_message_icon()->color(fl_rgb_color(0, 0, 255));
        fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
        fl_choice("Message with dark mode enabled...", "&OK", nullptr, nullptr);
      }, this);

      browser1.type(FL_HOLD_BROWSER);
      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"})
        browser1.add(item);
      browser1.select(1);

      radio1.value(true);

      check_button2.value(true);
      
      for (auto item : {"basic", "plastic", "gtk+", "gleam"})
        scheme_choice.add(item);
      scheme_choice.value(0);
      scheme_choice.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->update_theme_and_mode();
      }, this);

      for (auto item : {"default", "light", "dark"})
        scheme_mode_choice.add(item);
      scheme_mode_choice.value(2);
      scheme_mode_choice.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->update_theme_and_mode();
      }, this);
    }
    
  private:
    void update_theme_and_mode() {
      if (scheme_choice.value() == 1) fl_scheme_mode(Fl_Scheme_Mode::default_mode); // Workaround : with scheme "plastic", window background was not correctly refresh...
      Fl::scheme(scheme_choice.text(scheme_choice.value()));
      static map<string, Fl_Scheme_Mode> scheme_modes = {{"default", Fl_Scheme_Mode::default_mode}, {"light", Fl_Scheme_Mode::light}, {"dark", Fl_Scheme_Mode::dark}};
      fl_scheme_mode(scheme_modes[scheme_mode_choice.text(scheme_mode_choice.value())]);
      Fl::redraw();
    }

    Fl_Box box1 {10, 10, 90, 25, "Show mode"};
    Fl_Button button1 {110, 10, 75, 25, "Message"};
    Fl_Browser browser1 {10, 50, 120, 100};
    Fl_Radio_Round_Button radio1 {10, 170, 90, 25, "Raddio 1"};
    Fl_Radio_Round_Button radio2 {110, 170, 90, 25, "Raddio 2"};
    Fl_Check_Button check_button1 {10, 200, 90, 25, "Raddio 1"};
    Fl_Check_Button check_button2 {110, 200, 90, 25, "Raddio 2"};
    Fl_Box mode_box {10, 265, 30, 25, "Mode"};
    Fl_Choice scheme_mode_choice {50, 265, 80, 25};
    Fl_Box scheme_box {150, 265, 40, 25, "Scheme"};
    Fl_Choice scheme_choice {210, 265, 80, 25};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  fl_scheme_mode(Fl_Scheme_Mode::dark); // Must be call first after window.show, because show(...) method reset selection color to 0xf.
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

#include <initializer_list>
#include <map>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/fl_draw.H>
#include <FL/fl_message.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 330, 300, "") {
      end();

      button1.callback([](Fl_Widget* sender, void* window) {
        fl_message_hotspot(false);
        fl_message_icon()->color(fl_rgb_color(0, 0, 255));
        fl_message_icon()->label("i");
        fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
        fl_choice("Message with dark mode enabled...", "&OK", nullptr, nullptr);
      }, this);

      browser1.type(FL_HOLD_BROWSER);
      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"})
        browser1.add(item);
      browser1.select(1);

      radio1.value(true);

      check_button2.value(true);
    }

  private:
    Fl_Box box1 {10, 10, 90, 25, "Dark mode"};
    Fl_Button button1 {110, 10, 75, 25, "Message"};
    Fl_Browser browser1 {10, 50, 120, 100};
    Fl_Radio_Round_Button radio1 {10, 170, 90, 25, "Raddio 1"};
    Fl_Radio_Round_Button radio2 {110, 170, 90, 25, "Raddio 2"};
    Fl_Check_Button check_button1 {10, 200, 90, 25, "Raddio 1"};
    Fl_Check_Button check_button2 {110, 200, 90, 25, "Raddio 2"};
  };
  
  void enable_dark_mode() {
    Fl::background(50, 50, 50);
    Fl::background2(23, 23, 23);
    Fl::foreground(223, 223, 223);
    Fl::set_color(FL_SELECTION_COLOR, 0, 87, 207);
  }
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Examples::enable_dark_mode(); // Must be call after window.show, because show(...) method init system colors and reset selection color to 0xf.
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

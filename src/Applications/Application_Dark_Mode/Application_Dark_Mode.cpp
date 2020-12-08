#include <initializer_list>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Group.H>
#include <FL/fl_message.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Window.H>

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

      listBoxLeft.type(FL_HOLD_BROWSER);
      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"})
        listBoxLeft.add(item);
      listBoxLeft.select(1);
      
      radio1.value(true);
    }
    
  private:
    Fl_Box box1 {10, 10, 90, 25, "Dark mode"};
    Fl_Button button1 {110, 10, 75, 25, "Message"};
    Fl_Browser listBoxLeft {10, 50, 120, 100};
    Fl_Radio_Round_Button radio1 {10, 170, 90, 25, "Raddio 1"};
    Fl_Radio_Round_Button radio2 {110, 170, 90, 25, "Raddio 2"};
    Fl_Check_Button check_button1 {10, 200, 90, 25, "Raddio 1"};
    Fl_Check_Button check_button2 {110, 200, 90, 25, "Raddio 2"};
  };
  
  static void set_dark_mode() {
    Fl::get_system_colors();
#if _WIN32
    Fl::background(25, 25, 25);
    Fl::background2(32, 32, 32);
    Fl::foreground(255, 255, 255);
    Fl::set_color(FL_SELECTION_COLOR, 0, 160, 250);
#elif __APPLE__
    Fl::background(50, 50, 50);
    Fl::background2(23, 23, 23);
    Fl::foreground(223, 223, 223);
    Fl::set_color(FL_SELECTION_COLOR, 3, 88, 208);
#else
    Fl::background(51, 51, 51);
    Fl::background2(45, 45, 45);
    Fl::foreground(255, 255, 255);
    Fl::set_color(FL_SELECTION_COLOR, 21, 83, 158);
#endif
    Fl::redraw();
  }
}

int main(int argc, char *argv[]) {
  Fl::scheme("gtk+");
  Examples::Main_Window window;
  window.show(argc, argv);
  Examples::set_dark_mode();
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

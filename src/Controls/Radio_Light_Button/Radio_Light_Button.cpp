#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Radio_Light_Button.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Radio light button example"} {
      radio_round_button1.when(FL_WHEN_CHANGED);
      radio_round_button1.callback(on_radio_round_button_clock, this);

      radio_round_button2.value(true);
      radio_round_button2.when(FL_WHEN_CHANGED);
      radio_round_button2.callback(on_radio_round_button_clock, this);

      radio_round_button3.when(FL_WHEN_CHANGED);
      radio_round_button3.callback(on_radio_round_button_clock, this);

      radio_round_button4.copy_label("Radio 4");
      radio_round_button4.callback(on_radio_round_button_clock, this);

      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    }
    
  private:
    static void on_radio_round_button_clock(Fl_Widget* sender, void* data) noexcept {
      auto window = reinterpret_cast<Main_Window*>(data);
      if (sender == &window->radio_round_button1) window->box1.label("Radio 1 is checked");
      else if (sender == &window->radio_round_button2) window->box1.label("Radio 2 is checked");
      else if (sender == &window->radio_round_button3) window->box1.label("Radio 3 is checked");
      else if (sender == &window->radio_round_button4) window->box1.label("Radio 4 is checked");
      else window->box1.label("(unknown)");
    }
    
    Fl_Radio_Light_Button radio_round_button1 {30, 30, 75, 25, "Radio 1"};
    Fl_Radio_Light_Button radio_round_button2 {30, 60, 75, 25, "Radio 2"};
    Fl_Radio_Light_Button radio_round_button3 {30, 90, 75, 25, "Radio 3"};
    Fl_Radio_Light_Button radio_round_button4 {30, 120, 75, 25};
    Fl_Box box1{30, 150, 180, 25, "Radio 2 is checked"};
  };
}
  
auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

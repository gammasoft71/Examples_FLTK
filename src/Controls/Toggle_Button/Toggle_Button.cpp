#include <FL/Fl.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Toggle button example"} {
      toggleButton1.value(false);
      toggleButton1.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Fl_Toggle_Button*>(sender)->value(0);
        on_toggle_button_click(sender, window);
      }, this);
      
      toggleButton2.value(true);
      toggleButton2.callback(on_toggle_button_click, this);
      
      toggleButton3.callback(on_toggle_button_click, this);
    }
    
  private:
    static void on_toggle_button_click(Fl_Widget* sender, void* window) noexcept {
      reinterpret_cast<Fl_Toggle_Button*>(sender)->label(reinterpret_cast<Fl_Toggle_Button*>(sender)->value() ? "Checked" : "Unchecked");
    }
    
    Fl_Toggle_Button toggleButton1 {30, 30, 110, 23, "Unchecked"};
    Fl_Toggle_Button toggleButton2 {30, 60, 110, 23, "Checked"};
    Fl_Toggle_Button toggleButton3 {30, 90, 110, 23, "Unchecked"};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

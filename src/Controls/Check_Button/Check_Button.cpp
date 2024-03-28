#include <FL/Fl_Check_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Check button example"} {
      check_button1.value(false);
      check_button1.callback([](Fl_Widget* sender, void* data) {
        dynamic_cast<Fl_Check_Button*>(sender)->value(0);
        update_label_from_value(static_cast<Fl_Check_Button&>(*sender));
      }, nullptr);
      
      check_button2.value(true);
      check_button2.callback([](Fl_Widget* sender, void* data) {
        update_label_from_value(static_cast<Fl_Check_Button&>(*sender));
      }, nullptr);
      
      check_button3.callback([](Fl_Widget* sender, void* data) {
        update_label_from_value(static_cast<Fl_Check_Button&>(*sender));
      }, nullptr);
    }
    
  private:
    static void update_label_from_value(Fl_Check_Button& check_button) noexcept {check_button.label(check_button.value() ? "Checked" : "Unchecked");}

    Fl_Check_Button check_button1 {30, 30, 110, 23, "Unchecked"};
    Fl_Check_Button check_button2 {30, 60, 110, 23, "Checked"};
    Fl_Check_Button check_button3 {30, 90, 110, 23, "Unchecked"};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

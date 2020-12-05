#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

class Window : public Fl_Window {
public:
  Window() : Fl_Window(200, 100, 300, 300, "ToggleButton example") {
    resizable(this);
    
    toggleButton1.value(false);
    toggleButton1.callback([](Fl_Widget* sender, void* window) {
      reinterpret_cast<Fl_Toggle_Button*>(sender)->value(0);
    }, this);

    toggleButton2.value(true);
    toggleButton2.callback([](Fl_Widget* sender, void* window) {
      reinterpret_cast<Fl_Toggle_Button*>(sender)->label(reinterpret_cast<Fl_Toggle_Button*>(sender)->value() ? "Checked" : "Unchecked");
    }, this);

  }
  
private:
  Fl_Toggle_Button toggleButton1 {30, 30, 110, 23, "Unchecked"};
  Fl_Toggle_Button toggleButton2 {30, 60, 110, 23, "Checked"};
};

int main(int argc, char *argv[]) {
  Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

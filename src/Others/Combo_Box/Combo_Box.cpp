#include <initializer_list>
#include <FL/Fl.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Combo box example") {
      end();
      resizable(this);
      
      for (auto item : {"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"})
        combo_box1.add(item);
      combo_box1.callback([](Fl_Widget* sender, void* window) {
        auto index  = reinterpret_cast<Fl_Input_Choice*>(sender)->menubutton()->find_index(reinterpret_cast<Fl_Input_Choice*>(sender)->value());
        if (index != -1) reinterpret_cast<Main_Window*>(window)->on_combo_box_click(index);
      }, this);
      
      for (auto item : {"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"})
        combo_box2.add(item);
      combo_box2.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->on_combo_box_click(reinterpret_cast<Fl_Choice*>(sender)->value());
      }, this);
      
      for (auto item : {"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"})
        combo_box3.add(item);
      combo_box3.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->on_combo_box_click(reinterpret_cast<Fl_Menu_Button*>(sender)->value());
      }, this);
      
      on_combo_box_click(0);
    }
    
  private:
    void on_combo_box_click(int value) {
      combo_box1.value(value);
      combo_box2.value(value);
      combo_box3.value(value);
      combo_box3.label(combo_box3.text());
    }
    
    Fl_Input_Choice combo_box1 {10, 10, 120, 25};
    Fl_Choice combo_box2 {10, 50, 120, 25};
    Fl_Menu_Button combo_box3 {10, 90, 120, 25};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

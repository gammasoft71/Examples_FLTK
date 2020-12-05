#include <initializer_list>
#include <FL/Fl.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class MainWindow : public Fl_Window {
  public:
    MainWindow() : Fl_Window(200, 100, 300, 300, "ComboBox example") {
      resizable(this);
      
      for (auto item : {"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"})
        comboBox1.add(item);
      comboBox1.callback([](Fl_Widget* sender, void* window) {
        auto index  = reinterpret_cast<Fl_Input_Choice*>(sender)->menubutton()->find_index(reinterpret_cast<Fl_Input_Choice*>(sender)->value());
        if (index != -1) reinterpret_cast<MainWindow*>(window)->OnComboBoxClick(index);
      }, this);
      
      for (auto item : {"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"})
        comboBox2.add(item);
      comboBox2.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<MainWindow*>(window)->OnComboBoxClick(reinterpret_cast<Fl_Choice*>(sender)->value());
      }, this);
      
      for (auto item : {"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"})
        comboBox3.add(item);
      comboBox3.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<MainWindow*>(window)->OnComboBoxClick(reinterpret_cast<Fl_Menu_Button*>(sender)->value());
      }, this);
      
      OnComboBoxClick(0);
    }
    
  private:
    void OnComboBoxClick(int value) {
      comboBox1.value(value);
      comboBox2.value(value);
      comboBox3.value(value);
      comboBox3.label(comboBox3.text());
    }
    
    Fl_Input_Choice comboBox1 {10, 10, 120, 25};
    Fl_Choice comboBox2 {10, 50, 120, 25};
    Fl_Menu_Button comboBox3 {10, 90, 120, 25};
  };
}

int main(int argc, char *argv[]) {
  Examples::MainWindow form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

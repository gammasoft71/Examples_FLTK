#include <initializer_list>
#include <FL/Fl.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "ComboBox example") {
    this->resizable(this);
    
    for (const char* item : {"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"})
      comboBox1.add(item);
    this->comboBox1.value(0);
    
    for (const char* item : {"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"})
      comboBox2.add(item);
    this->comboBox2.value(1);
  }
  
private:
  Fl_Input_Choice comboBox1 {10, 10, 75, 25};
  Fl_Choice comboBox2 {10, 50, 75, 25};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

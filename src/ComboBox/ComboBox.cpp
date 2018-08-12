#include <FL/Fl.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "ComboBox example") {
    this->resizable(this);
    
    this->comboBox1.add("item1");
    this->comboBox1.add("item2");
    this->comboBox1.add("item3");
    this->comboBox1.value(1);
  }
  
private:
  Fl_Input_Choice comboBox1 {10, 10, 75, 25};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

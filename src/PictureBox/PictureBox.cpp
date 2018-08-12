#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "Picture example") {
    this->pictureBox1.image(&this->picture);
    
    this->resizable(this);

  }
  
private:
  Fl_Box pictureBox1 {10, 10, 280, 280, ""};
  Fl_PNG_Image picture {"Resources/Logo.png"};

};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

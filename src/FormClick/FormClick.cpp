#include <FL/Fl.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "Click anywhere on the form") {
    this->resizable(this);
  }
  
  int handle(int event) override {
    if (event == FL_RELEASE && Fl::event_button() == FL_LEFT_MOUSE) {
      fl_message_title("FormClick");
      fl_message("The form is clicked");
    }
    return Fl_Window::handle(event);
  }
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  fl_message_hotspot(0);
  return Fl::run();
}

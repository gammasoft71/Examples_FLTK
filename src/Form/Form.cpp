#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 640, 480, "Form example") {
    this->resizable(this);

    this->button.align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->button.callback([](Fl_Widget* sender, void* form) {
      ((Form*)form)->hide();
    }, this);
  }

  void hide() override {
    fl_message_icon()->label("?");
    fl_message_title("Close Form");
    if (fl_choice("Are you sure you want exit?", "No", "Yes", nullptr) == 1)
      this->Fl_Window::hide();
  }
  
private:
  Fl_Button button {10, 10, 75, 25, "Close"};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

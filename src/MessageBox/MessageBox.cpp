#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_message.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "MessageBox example") {
    resizable(this);
    
    buttonShowMessage.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    buttonShowMessage.callback([](Fl_Widget* sender, void* form) {
      fl_message_icon()->label("!");
      fl_message_icon()->color(fl_rgb_color(0, 0, 255));
      fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
      fl_message_title("Message");
      if (fl_choice("Hello, World!", fl_cancel, fl_ok, nullptr) == 1)
        ((Form*)form)->labelDialogResult.copy_label("DialogResult = Ok");
      else
        ((Form*)form)->labelDialogResult.copy_label("DialogResult = Cancel");
    }, this);

    labelDialogResult.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  }
  
private:
  Fl_Button buttonShowMessage {10, 10, 100, 25, "MessageBox"};
  Fl_Box labelDialogResult {10, 45, 200, 20};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  fl_message_hotspot(0);
  return Fl::run();
}

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 320, 600, "Beep example") {
      resizable(this);
      
      button_default.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button_default.callback([](Fl_Widget* sender, void* data) {
        fl_beep(FL_BEEP_DEFAULT);
      }, this);
      
      button_message.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button_message.callback([](Fl_Widget* sender, void* data) {
        fl_beep(FL_BEEP_MESSAGE);
      }, this);
      
      button_error.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button_error.callback([](Fl_Widget* sender, void* data) {
        fl_beep(FL_BEEP_ERROR);
      }, this);
      
      button_question.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button_question.callback([](Fl_Widget* sender, void* data) {
        fl_beep(FL_BEEP_QUESTION);
      }, this);
      
      button_password.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button_password.callback([](Fl_Widget* sender, void* data) {
        fl_beep(FL_BEEP_PASSWORD);
      }, this);
      
      button_notification.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      button_notification.callback([](Fl_Widget* sender, void* data) {
        fl_beep(FL_BEEP_NOTIFICATION);
      }, this);
    }
    
  private:
    Fl_Button button_default {0, 0, 320, 100, "Default"};
    Fl_Button button_message {0, 100, 320, 100, "Message"};
    Fl_Button button_error {0, 200, 320, 100, "Error"};
    Fl_Button button_question {0, 300, 320, 100, "Question"};
    Fl_Button button_password {0, 400, 320, 100, "Password"};
    Fl_Button button_notification {0, 500, 320, 100, "Notification"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

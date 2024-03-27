#include "fl_message_box.h"
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::literals;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 185, "Message box example") {
      end();
      caption_Box.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      caption_Input.value("FLTK");
      text_Box.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      text_Input.value("It's fantastic !");
      buttons_Box.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      for (auto item : initializer_list<string> {"Ok", "Ok_Cancel", "Abort_Retry_Ignore", "Yes_No_Cancel", "Yes_No", "Retry_Cancel"})
        buttons_choice.add(item.c_str());
      buttons_choice.value(0);
      icon_Box.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      for (auto item : initializer_list<string> {"None", "Hand", "Stop", "Error", "Question", "Exclamation", "Warning", "Asterisk", "Information"})
        icon_choice.add(item.c_str());
      icon_choice.value(0);
      button_show_message.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        window->result_Box.label("Result = ");
        window->result_Box.copy_label(("Result = " + to_string(fl_message_box(window->text_Input.value(), window->caption_Input.value(), static_cast<Message_Box_Buttons>(window->buttons_choice.value()), to_icon(window->icon_choice.text(window->icon_choice.value()))))).c_str());
      }, this);
      result_Box.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    static string to_string(Dialog_Result result) {
      static map<Dialog_Result, string> results {{Dialog_Result::None, "None"}, {Dialog_Result::Ok, "Ok"}, {Dialog_Result::Cancel, "Cancel"}, {Dialog_Result::Abort, "Abort"}, {Dialog_Result::Retry, "Retry"}, {Dialog_Result::Ignore, "Ignore"}, {Dialog_Result::Yes, "Yes"}, {Dialog_Result::No, "No"}};
      auto it = results.find(result);
      return it != results.end() ? it->second : "(unknown)";
    }
    
    static Message_Box_Icon to_icon(const string& icon) {
      static map<string, Message_Box_Icon> icons {{"None", Message_Box_Icon::None}, {"Hand", Message_Box_Icon::Hand}, {"Stop", Message_Box_Icon::Stop}, {"Error", Message_Box_Icon::Error}, {"Question", Message_Box_Icon::Question}, {"Exclamation", Message_Box_Icon::Exclamation}, {"Warning", Message_Box_Icon::Warning}, {"Asterisk", Message_Box_Icon::Asterisk}, {"Information", Message_Box_Icon::Information}};
      auto it = icons.find(icon);
      return it != icons.end() ? it->second : Message_Box_Icon::None;
    }
    
    Fl_Box caption_Box {10, 13, 70, 20, "Caption :"};
    Fl_Input caption_Input {90, 10, 200, 25};
    Fl_Box text_Box {10, 43, 70, 20, "Message :"};
    Fl_Input text_Input {90, 40, 200, 25};
    Fl_Box buttons_Box {10, 83, 70, 20, "Butttons :"};
    Fl_Choice buttons_choice {90, 80, 200, 25};
    Fl_Box icon_Box {10, 118, 70, 20, "Icon :"};
    Fl_Choice icon_choice {90, 115, 200, 25};
    Fl_Button button_show_message {10, 150, 75, 25, "Try it"};
    Fl_Box result_Box {90, 153, 200, 20, "Result = "};
  };
}

int main(int argc, char *argv[]) {
  fl_message_hotspot(false);
  fl_message_icon()->labelfont(FL_HELVETICA_BOLD);
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

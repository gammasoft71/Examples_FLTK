#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 160, "Group and radio round button example") {
      group1.align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group1.box(FL_FRAME_BOX);
      
      radio1.value(1);

      group2.align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group2.box(FL_FRAME_BOX);

      radio5.value(1);
    }
    
  private:
    Fl_Group group1 {10, 10, 135, 140, "Group 1"};
    Fl_Radio_Round_Button radio1 {20, 40, 104, 24, "radio 1"};
    Fl_Radio_Round_Button radio2 {20, 70, 104, 24, "radio 2"};
    Fl_Radio_Round_Button radio3 {20, 100, 104, 24, "radio 3"};
    Fl_End end_group1;
    Fl_Group group2 {155, 10, 135, 140, "Group 2"};
    Fl_Radio_Round_Button radio4 {165, 40, 104, 24, "radio 4"};
    Fl_Radio_Round_Button radio5 {165, 70, 104, 24, "radio 5"};
    Fl_Radio_Round_Button radio6 {165, 100, 104, 24, "radio 6"};
    Fl_End end_group2;
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

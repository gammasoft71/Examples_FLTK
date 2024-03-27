#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 160, "Group and Check button example") {
      group1.align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group1.box(FL_BORDER_BOX);
      
      check2.value(1);

      group2.align(FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group2.box(FL_BORDER_BOX);

      check6.value(1);
    }
    
  private:
    Fl_Group group1 {10, 25, 135, 125, "Group 1"};
    Fl_Check_Button check1 {20, 40, 104, 24, "check 1"};
    Fl_Check_Button check2 {20, 70, 104, 24, "check 2"};
    Fl_Check_Button check3 {20, 100, 104, 24, "check 3"};
    Fl_End end_group1;
    Fl_Group group2 {155, 25, 135, 125, "Group 2"};
    Fl_Check_Button check4 {165, 40, 104, 24, "check 4"};
    Fl_Check_Button check5 {165, 70, 104, 24, "check 5"};
    Fl_Check_Button check6 {165, 100, 104, 24, "check 6"};
    Fl_End end_group2;
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

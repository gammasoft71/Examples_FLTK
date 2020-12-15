#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 160, "Group and Check button example") {
      group1 = make_unique<Fl_Group>(10, 10, 135, 140, "Group 1");
      group1->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group1->box(FL_BORDER_BOX);
      
      check1 = make_unique<Fl_Check_Button>(20, 40, 104, 24, "check 1");
      check2 = make_unique<Fl_Check_Button>(20, 70, 104, 24, "check 2");
      check2->value(1);
      check3 = make_unique<Fl_Check_Button>(20, 100, 104, 24, "check 3");
      group1->end();

      group2 = make_unique<Fl_Group>(155, 10, 135, 140, "Group 2");
      group2->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group2->box(FL_BORDER_BOX);
      check4 = make_unique<Fl_Check_Button>(165, 40, 104, 24, "check 4");
      check5 = make_unique<Fl_Check_Button>(165, 70, 104, 24, "check 5");
      check6 = make_unique<Fl_Check_Button>(165, 100, 104, 24, "check 6");
      check6->value(1);
      group2->end();
    }
    
  private:
    unique_ptr<Fl_Group> group1;
    unique_ptr<Fl_Group> group2;
    unique_ptr<Fl_Check_Button> check1;
    unique_ptr<Fl_Check_Button> check2;
    unique_ptr<Fl_Check_Button> check3;
    unique_ptr<Fl_Check_Button> check4;
    unique_ptr<Fl_Check_Button> check5;
    unique_ptr<Fl_Check_Button> check6;
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

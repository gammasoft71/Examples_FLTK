#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 160, "Group and radio round button example") {
      
      group1 = make_unique<Fl_Group>(10, 10, 135, 140, "Group 1");
      group1->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group1->box(FL_BORDER_BOX);
      
      radio1 = make_unique<Fl_Radio_Round_Button>(20, 40, 104, 24, "radio 1");
      radio1->value(1);
      radio2 = make_unique<Fl_Radio_Round_Button>(20, 70, 104, 24, "radio 2");
      radio3 = make_unique<Fl_Radio_Round_Button>(20, 100, 104, 24, "radio 3");
      group1->end();

      group2 = make_unique<Fl_Group>(155, 10, 135, 140, "Group 2");
      group2->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
      group2->box(FL_BORDER_BOX);
      radio4 = make_unique<Fl_Radio_Round_Button>(165, 40, 104, 24, "radio 4");
      radio5 = make_unique<Fl_Radio_Round_Button>(165, 70, 104, 24, "radio 5");
      radio5->value(1);
      radio6 = make_unique<Fl_Radio_Round_Button>(165, 100, 104, 24, "radio 6");
      group2->end();

      end();
      resizable(this);
    }
    
  private:
    unique_ptr<Fl_Group> group1;
    unique_ptr<Fl_Group> group2;
    unique_ptr<Fl_Radio_Round_Button> radio1;
    unique_ptr<Fl_Radio_Round_Button> radio2;
    unique_ptr<Fl_Radio_Round_Button> radio3;
    unique_ptr<Fl_Radio_Round_Button> radio4;
    unique_ptr<Fl_Radio_Round_Button> radio5;
    unique_ptr<Fl_Radio_Round_Button> radio6;
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

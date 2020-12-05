#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 160, "GroupBox and ChackBox example") {
    resizable(this);
    
    groupBox1 = make_shared<Fl_Group>(10, 10, 135, 140, "Group 1");
    groupBox1->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
    groupBox1->box(FL_BORDER_BOX);
    
    radio1 = make_shared<Fl_Radio_Round_Button>(20, 40, 104, 24, "check 1");
    radio1->value(1);
    radio2 = make_shared<Fl_Radio_Round_Button>(20, 70, 104, 24, "check 2");
    radio3 = make_shared<Fl_Radio_Round_Button>(20, 100, 104, 24, "check 3");
    groupBox1->end();

    groupBox2 = make_shared<Fl_Group>(155, 10, 135, 140, "Group 2");
    groupBox2->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
    groupBox2->box(FL_BORDER_BOX);
    radio4 = make_shared<Fl_Radio_Round_Button>(165, 40, 104, 24, "check 4");
    radio5 = make_shared<Fl_Radio_Round_Button>(165, 70, 104, 24, "check 5");
    radio5->value(1);
    radio6 = make_shared<Fl_Radio_Round_Button>(165, 100, 104, 24, "check 6");
    groupBox2->end();
  }
  
private:
  shared_ptr<Fl_Group> groupBox1;
  shared_ptr<Fl_Group> groupBox2;
  shared_ptr<Fl_Radio_Round_Button> radio1;
  shared_ptr<Fl_Radio_Round_Button> radio2;
  shared_ptr<Fl_Radio_Round_Button> radio3;
  shared_ptr<Fl_Radio_Round_Button> radio4;
  shared_ptr<Fl_Radio_Round_Button> radio5;
  shared_ptr<Fl_Radio_Round_Button> radio6;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

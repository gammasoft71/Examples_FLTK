#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 160, "GroupBox and ChackBox example") {
    this->resizable(this);
    
    this->groupBox1 = std::make_shared<Fl_Group>(10, 10, 135, 140, "Group 1");
    this->groupBox1->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
    this->groupBox1->box(FL_BORDER_BOX);
    
    this->check1 = std::make_shared<Fl_Check_Button>(20, 40, 104, 24, "check 1");
    this->check2 = std::make_shared<Fl_Check_Button>(20, 70, 104, 24, "check 2");
    this->check2->value(1);
    this->check3 = std::make_shared<Fl_Check_Button>(20, 100, 104, 24, "check 3");
    this->groupBox1->end();

    this->groupBox2 = std::make_shared<Fl_Group>(155, 10, 135, 140, "Group 2");
    this->groupBox2->align(FL_ALIGN_INSIDE | FL_ALIGN_TOP | FL_ALIGN_LEFT);
    this->groupBox2->box(FL_BORDER_BOX);
    this->check4 = std::make_shared<Fl_Check_Button>(165, 40, 104, 24, "check 4");
    this->check5 = std::make_shared<Fl_Check_Button>(165, 70, 104, 24, "check 5");
    this->check6 = std::make_shared<Fl_Check_Button>(165, 100, 104, 24, "check 6");
    this->check6->value(1);
    this->groupBox2->end();
  }
  
private:
  std::shared_ptr<Fl_Group> groupBox1;
  std::shared_ptr<Fl_Group> groupBox2;
  std::shared_ptr<Fl_Check_Button> check1;
  std::shared_ptr<Fl_Check_Button> check2;
  std::shared_ptr<Fl_Check_Button> check3;
  std::shared_ptr<Fl_Check_Button> check4;
  std::shared_ptr<Fl_Check_Button> check5;
  std::shared_ptr<Fl_Check_Button> check6;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

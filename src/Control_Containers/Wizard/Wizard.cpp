#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Wizard.H>
#include <FL/Fl_Window.H>

using namespace std;

class Main_Window : public Fl_Window {
public:
  Main_Window() : Fl_Window(200, 100, 390, 315, "Wizard example") {
    wizard = make_unique<Fl_Wizard>(10, 10, 370, 250);

    page1 = make_unique<Fl_Group>(10, 10, 370, 250);
    box1 = make_unique<Fl_Box>(20, 20, 150, 25, "Page 1");
    box1->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    page1->end();
    
    page2 = make_unique<Fl_Group>(10, 10, 370, 250);
    box2 = make_unique<Fl_Box>(20, 20, 150, 25, "Page 2");
    box2->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    page2->end();
    
    page3 = make_unique<Fl_Group>(10, 10, 370, 250);
    box3 = make_unique<Fl_Box>(20, 20, 150, 25, "Page 3");
    box3->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    page3->end();
    
    page4 = make_unique<Fl_Group>(10, 10, 370, 250);
    box4 = make_unique<Fl_Box>(20, 20, 150, 25, "Page 4");
    box4->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    page4->end();

    wizard->end();

    previoous_button = make_unique<Fl_Button>(10, 270, 75, 25, "<");
    previoous_button->deactivate();
    previoous_button->callback([](Fl_Widget* sender, void* data) {
      auto window = reinterpret_cast<Main_Window*>(data);
      window->wizard->prev();
      window->update_buttons();
    }, this);

    next_button = make_unique<Fl_Button>(100, 270, 75, 25, ">");
    next_button->callback([](Fl_Widget* sender, void* data) {
      auto window = reinterpret_cast<Main_Window*>(data);
      window->wizard->next();
      window->update_buttons();
    }, this);
  }
  
private:
  void update_buttons() {
    if (wizard->value() != page1.get()) previoous_button->activate();
    else previoous_button->deactivate();
    
    if (wizard->value() != page4.get()) next_button->activate();
    else  next_button->deactivate();
  }
  
  unique_ptr<Fl_Wizard> wizard;
  unique_ptr<Fl_Group> page1;
  unique_ptr<Fl_Box> box1;
  unique_ptr<Fl_Group> page2;
  unique_ptr<Fl_Box> box2;
  unique_ptr<Fl_Group> page3;
  unique_ptr<Fl_Box> box3;
  unique_ptr<Fl_Group> page4;
  unique_ptr<Fl_Box> box4;
  unique_ptr<Fl_Button> previoous_button;
  unique_ptr<Fl_Button> next_button;
};

int main(int argc, char *argv[]) {
  Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

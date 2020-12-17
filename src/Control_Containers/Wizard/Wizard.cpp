#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Wizard.H>
#include <FL/Fl_Window.H>

class Main_Window : public Fl_Window {
public:
  Main_Window() : Fl_Window(200, 100, 390, 315, "Wizard example") {
    box1.align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    box2.align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    box3.align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    box4.align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);

    previous_button.deactivate();
    previous_button.callback([](Fl_Widget* sender, void* data) {
      auto window = reinterpret_cast<Main_Window*>(data);
      window->wizard.prev();
      window->update_buttons();
    }, this);

    next_button.callback([](Fl_Widget* sender, void* data) {
      auto window = reinterpret_cast<Main_Window*>(data);
      window->wizard.next();
      window->update_buttons();
    }, this);
  }
  
private:
  void update_buttons() {
    if (wizard.value() != &page1) previous_button.activate();
    else previous_button.deactivate();
    
    if (wizard.value() != &page4) next_button.activate();
    else  next_button.deactivate();
  }
  
  Fl_Wizard wizard {10, 10, 370, 250};
  Fl_Group page1 {10, 10, 370, 250};
  Fl_Box box1 {20, 20, 150, 25, "Page 1"};
  Fl_End end_page1;
  Fl_Group page2 {10, 10, 370, 250};
  Fl_Box box2 {20, 20, 150, 25, "Page 2"};
  Fl_End end_page2;
  Fl_Group page3 {10, 10, 370, 250};
  Fl_Box box3 {20, 20, 150, 25, "Page 3"};
  Fl_End end_page3;
  Fl_Group page4 {10, 10, 370, 250};
  Fl_Box box4 {20, 20, 150, 25, "Page 4"};
  Fl_End end_page4;
  Fl_End end_wizard;
  Fl_Button previous_button {10, 270, 75, 25, "<"};
  Fl_Button next_button {100, 270, 75, 25, ">"};
};

int main(int argc, char *argv[]) {
  Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

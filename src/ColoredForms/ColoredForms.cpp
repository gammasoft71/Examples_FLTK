#include <map>
#include <memory>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "Main Form") {
    this->resizable(this);
    int screen_x = 0, screen_y = 0, screen_w = 0, screen_h = 0;
    Fl::screen_xywh(screen_x, screen_y, screen_w, screen_h);
    this->position(screen_w - 320, 40);
    
    this->button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->button.callback([](Fl_Widget* sender, void* form) {
      shared_ptr<Fl_Window> coloredForm = make_shared<Fl_Window>(((Form*)form)->x, ((Form*)form)->y, 300, 300);
      coloredForm->color(((Form*)form)->iterator->first);
      coloredForm->copy_label(((Form*)form)->iterator->second.c_str());

      ((Form*)form)->colored_forms.push_back(coloredForm);
      
      ((Form*)form)->x = ((Form*)form)->y = ((Form*)form)->x < 180 ? ((Form*)form)->x + 20 : 40;
      ((Form*)form)->iterator++;
      if (((Form*)form)->iterator == ((Form*)form)->colors.end())
        ((Form*)form)->iterator = ((Form*)form)->colors.begin();

      coloredForm->show();
      while (coloredForm->visible())
        Fl::wait();
      
    }, this);
  }
  
  void hide() override {
    this->Fl_Window::hide();
    exit(0);
  }

private:
  Fl_Button button {10, 10, 75, 25, "Create"};
  map<Fl_Color, string> colors {{FL_BLACK, "FL_BLACK"}, {FL_RED, "FL_RED"}, {FL_GREEN, "FL_GREEN"}, {FL_YELLOW, "FL_YELLOW"}, {FL_BLUE, "FL_BLUE"}, {FL_MAGENTA, "FL_MAGENTA"}, {FL_CYAN, "FL_CYAN"}, {FL_DARK_RED, "FL_DARK_RED"}, {FL_DARK_GREEN, "FL_DARK_GREEN"}, {FL_DARK_YELLOW, "FL_DARK_YELLOW"}, {FL_DARK_BLUE, "FL_DARK_BLUE"}, {FL_DARK_MAGENTA, "FL_DARK_MAGENTA"}, {FL_DARK_CYAN, "FL_DARK_CYAN"}, {FL_WHITE, "FL_WHITE"}};
  map<Fl_Color, string>::iterator iterator = colors.begin();
  vector<shared_ptr<Fl_Window>> colored_forms;
  int x = 40;
  int y = 40;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

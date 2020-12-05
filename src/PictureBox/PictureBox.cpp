#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Window.H>
#include "logo.xpm"

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "Picture example") {
    pictureBox1.box(FL_BORDER_BOX);
    pictureBox1.image(&picture);
    pictureBox1.redraw();
    
    resizable(this);
  }
  
private:
  Fl_Box pictureBox1 {20, 20, 260, 260};
  Fl_Pixmap picture {logo_xpm};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

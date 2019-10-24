#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

#if defined(__APPLE__)
float points_to_native_font_graphics_untit(float size) {
  return size / 72.0f * 96.0f;  // font is in pixels and not in points
}
#else
float points_to_native_font_graphics_untit(float size) {
  return size;  // font is in points
}
#endif

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "My first application") {
    this->label1.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->label1.labelfont(FL_HELVETICA_BOLD_ITALIC);
    this->label1.labelsize(points_to_native_font_graphics_untit(32));
    this->label1.labelcolor(fl_rgb_color(0x00, 0x80, 0x00));

    this->resizable(this);
    this->position((Fl::w() - this->w())/2, (Fl::h() - this->h())/2);
  }
  
private:
  Fl_Box label1 {5, 100, 290, 100, "Hello, World!"};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

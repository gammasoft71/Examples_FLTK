#include "Fl_font_chooser.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 400, 400, "Font Example") {
    this->resizable(this);
    this->end();
    this->button.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    this->button.callback([](Fl_Widget* sender, void* form) {
      Fl_Font font = ((Form*)form)->label.labelfont();
      int size = ((Form*)form)->label.labelsize();
      Fl_Color color = ((Form*)form)->label.labelcolor();
      if (fl_font_chooser("Font", font, size, color) == 1) {
        ((Form*)form)->label.labelfont(font);
        ((Form*)form)->label.labelsize(size);
        ((Form*)form)->label.labelcolor(color);
        ((Form*)form)->label.redraw();
      }
    }, this);

    this->label.box(FL_FLAT_BOX);
    this->label.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  }
  
private:
  Fl_Button button {10, 10, 75, 25, "Font..."};
  Fl_Box label {10, 50, 380, 340,
    "The quick brown fox jumps over the lazy dog.\n"
    "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
    "0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
    "àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
    "\u0400\u0401\u0402\u0403\u0404\u0405\u0406\u0407\u0408\u0409\u040a\u040b\u040c\u040d\u040e\u040f\n"
    "\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041a\u041b\u041c\u041d\u041e\u041f\n"
    "\u4ea0\u4ea1\u4ea2\u4ea3\u4ea4\u4ea5\u4ea6\u4ea7\u4ea8\u4ea9\u4eaa\u4eab\u4eac\u4ead\u4eae\u4eaf\n"
    "\u4eb0\u4eb1\u4eb2\u4eb3\u4eb4\u4eb5\u4eb6\u4eb7\u4eb8\u4eb9\u4eba\u4ebb\u4ebc\u4ebd\u4ebe\u4ebf\n"
    "\U0001F428"};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

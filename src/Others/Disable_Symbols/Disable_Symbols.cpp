#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Window.H>

namespace Examples {

  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Disable symbols examples") {
      Fl::set_labeltype(FL_NORMAL_LABEL, owner_draw, owner_measure);

      box1.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box2.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);

      use_symbols_button.value(use_symbols);
      use_symbols_button.callback([](Fl_Widget* sender, void* data) {
        use_symbols = dynamic_cast<Fl_Toggle_Button*>(sender)->value();
        reinterpret_cast<Main_Window*>(data)->redraw();
      }, this);
    }
    
  private:
    static void owner_draw(const Fl_Label* label, int x, int y, int width, int height, Fl_Align align) {
      fl_font(label->font, label->size);
      fl_color(label->color);
      fl_draw(label->value, x, y, width, height, align, label->image, use_symbols);
    }
    
    static void owner_measure(const Fl_Label* label, int &width, int &height) {
      fl_font(label->font, label->size);
      fl_measure(label->value, width, height, use_symbols);
    }
    
    static bool use_symbols;
    Fl_Box box1 {10, 10, 200, 25, "gammasoft71@gmail.com"};
    Fl_Box box2 {10, 40, 200, 25, "@filesaveas"};
    Fl_Toggle_Button use_symbols_button {10, 70, 120, 25, "Use symbols"};
  };
  
  bool Main_Window::use_symbols = true;
}

int main(int argc, char* argv[]) {
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}

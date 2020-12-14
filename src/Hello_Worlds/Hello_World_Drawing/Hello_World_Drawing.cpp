#include <string>
#include <tuple>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Hello world (drawing)") {
      resizable(this);
    }

  protected:
    auto get_text_location(const string& text, Fl_Font font = FL_HELVETICA, Fl_Fontsize font_size = FL_NORMAL_SIZE) const {
      auto text_width = 0;
      auto text_height = 0;
      fl_font(font, font_size);
      fl_measure(text.c_str(), text_width, text_height);
      return make_tuple(const_cast<Main_Window*>(this)->decorated_w() - w() + (w() - text_width) / 2, const_cast<Main_Window*>(this)->decorated_h() - h() + (h() - text_height) / 2);
    }

    void draw_text(const string& text, int x, int y, Fl_Color color = FL_FOREGROUND_COLOR, Fl_Font font = FL_HELVETICA, Fl_Fontsize font_size = FL_NORMAL_SIZE) const {
      fl_font(font, font_size);
      fl_color(color);
      fl_draw(text.c_str(), x, y);
    }

    void draw() override {
      Fl_Window::draw();
      auto text = "Hello, World!";
      auto font = FL_HELVETICA_BOLD_ITALIC;
      auto font_size = Fl_Fontsize(42);
      auto [text_x, text_y] = get_text_location(text, font, font_size);
      fl_draw_box(FL_FLAT_BOX, 0, 0, w(), h(), fl_rgb_color(0x0, 0x20, 0x10));
      draw_text(text, text_x + 2, text_y + 2, fl_rgb_color(0x00, 0x55, 0x29), font, font_size);
      draw_text(text, text_x - 2, text_y - 2, fl_rgb_color(0x00, 0xFF, 0x7F), font, font_size);
    }
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

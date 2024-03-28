#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Preferences.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {100, 50, "Preferences example"} {
      resizable(this);
      back_color_button.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        uchar r = 0, g = 0, b = 0;
        Fl::get_color(window->color(), r, g, b);
        if (fl_color_chooser("Color", r, g, b) != 0) {
          window->color(fl_rgb_color(r, g, b));
          window->redraw();
        }
      }, this);
      
      save_button.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        window->preferences.set("width", window->w());
        window->preferences.set("height", window->h());
        window->preferences.set("left", window->x());
        window->preferences.set("top", window->y());
        window->preferences.set("color", static_cast<int>(window->color()));
        window->preferences.flush();
      }, this);
      
      reload_button.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        auto width = 0, height = 0, left = 0, top = 0, color = 0;
        window->preferences.get("width", width, 335);
        window->preferences.get("height", height, 45);
        window->preferences.get("left", left, 200);
        window->preferences.get("top", top, 100);
        window->preferences.get("color", color, FL_BACKGROUND_COLOR);
        window->resize(left, top, width, height);
        window->color(static_cast<Fl_Color>(color));
        window->redraw();
      }, this);
      
      reset_button.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        window->preferences.clear();
        window->reload_button.do_callback();
      }, this);
      
      reload_button.do_callback();
    }
    
  private:
    void resize(int x, int y, int w, int h) noexcept override {
      Fl_Window::resize(x, y, w, h);
      back_color_button.resize(10, 10, 75, 25);
      save_button.resize(90, 10, 75, 25);
      reload_button.resize(170, 10, 75, 25);
      reset_button.resize(250, 10, 75, 25);
    }
    
    Fl_Button back_color_button {10, 10, 75, 25, "Color"};
    Fl_Button save_button {90, 10, 75, 25, "&Save"};
    Fl_Button reload_button {170, 10, 75, 25, "&Reload"};
    Fl_Button reset_button {250, 10, 75, 25, "R&eset"};
    Fl_Preferences preferences {Fl_Preferences::USER, "gammasoft71", "fltk_preferences_example"};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

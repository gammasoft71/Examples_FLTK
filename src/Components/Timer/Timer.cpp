#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <iomanip>
#include <sstream>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 230, 130, "Timer example"} {
      button.callback([](Fl_Widget* sender, void* data) {
        auto window = reinterpret_cast<Main_Window*>(data);
        window->enable_timer = !window->enable_timer;
        window->button.copy_label(window->enable_timer ? "Stop" : "Start");
        if (window->enable_timer) Fl::add_timeout(0.1, on_timer_tick, data);
        else Fl::remove_timeout(on_timer_tick, data);
      }, this);
      
      box.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box.labelfont(FL_HELVETICA_ITALIC);
      box.labelsize(64);
      box.labelcolor(fl_rgb_color(30, 144, 255));
    }
    
  private:
    static void on_timer_tick(void* data) noexcept {
      auto window = reinterpret_cast<Main_Window*>(data);
      stringstream stream;
      stream << fixed << setprecision(1) << static_cast<double>(++window->timer) / 10;
      window->box.copy_label(stream.str().c_str());
      if (window->enable_timer) Fl::repeat_timeout(0.1, on_timer_tick, data);
    }

    Fl_Box box {10, 10, 210, 70, "0.0"};
    Fl_Button button {10, 90, 75, 25, "Start"};
    bool enable_timer = false;
    int timer = 0;
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

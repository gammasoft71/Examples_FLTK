#include <FL/Fl_Progress.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Progress example") {
      progress_bar2.value(50);
      
      progress_bar3.value(100);
      
      progress_bar4.maximum(140);
      Fl::add_timeout(0.05, on_timer_tick, this);
    }

  private:
    static void on_timer_tick(void* data) {
      auto window = reinterpret_cast<Main_Window*>(data);
      window->progress_bar4.value(window->progress_bar4.value() < window->progress_bar4.maximum() ? window->progress_bar4.value() + 1 : window->progress_bar4.minimum());
      Fl::repeat_timeout(0.05, on_timer_tick, data);
    }
    
    Fl_Progress progress_bar1 {50, 50, 200, 25};
    Fl_Progress progress_bar2 {50, 80, 200, 25};
    Fl_Progress progress_bar3 {50, 110, 200, 25};
    Fl_Progress progress_bar4 {50, 140, 200, 25};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

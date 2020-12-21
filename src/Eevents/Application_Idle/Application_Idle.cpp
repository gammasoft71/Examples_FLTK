#include <chrono>
#include <functional>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "") {
      Fl::add_idle([](void* window) {
        static auto last_idle_time = high_resolution_clock::now();;
        auto elapsed_time = high_resolution_clock::now() - last_idle_time;
        if (elapsed_time >= 100ms) {
          reinterpret_cast<Main_Window*>(window)->on_application_idle();
          last_idle_time = high_resolution_clock::now();
        }
      }, this);
    }
    
  private:
    void on_application_idle() {
      copy_label(to_string(++counter).c_str());
    }
    
    int counter = 0;
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

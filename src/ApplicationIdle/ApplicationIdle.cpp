#include <chrono>
#include <functional>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

namespace Examples {
  class MainWindow : public Fl_Window {
  public:
    MainWindow() : Fl_Window(200, 100, 300, 300, "") {
      resizable(this);
      
      Fl::add_idle([](void* window) {
        static auto lastIdleTime = high_resolution_clock::now();;
        auto elapsedTime = high_resolution_clock::now() - lastIdleTime;
        if (elapsedTime >= 100ms) {
          reinterpret_cast<MainWindow*>(window)->OnApplicationIdle();
          lastIdleTime = high_resolution_clock::now();
        }
      }, this);
    }
    
  private:
    void OnApplicationIdle() {
      copy_label(to_string(++counter).c_str());
    }
    
    int counter = 0;
  };
}

int main(int argc, char *argv[]) {
  Examples::MainWindow window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

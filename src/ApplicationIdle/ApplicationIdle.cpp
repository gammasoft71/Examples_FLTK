#include <chrono>
#include <functional>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

using namespace std::chrono_literals;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 300, 300, "") {
    this->resizable(this);

    Fl::add_idle([](void* form) {
      static std::chrono::high_resolution_clock::time_point lastIdleTime;
      std::chrono::milliseconds elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - lastIdleTime);
      if (elapsedTime >= 100ms) {
        ((Form*)form)->OnApplicationIdle();
        lastIdleTime = std::chrono::high_resolution_clock::now();
      }
    }, this);
  }
  
private:
  void OnApplicationIdle() {
    this->copy_label(std::to_string(++this->counter).c_str());
  }

  int counter = 0;
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

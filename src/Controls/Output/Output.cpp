#include <FL/Fl.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Output example") {
      output1.value("Output text");
    }
    
  private:
    Fl_Output output1 {10, 10, 100, 25};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

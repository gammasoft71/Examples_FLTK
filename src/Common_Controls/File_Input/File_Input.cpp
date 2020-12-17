#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_File_Input.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "File input example") {
#if defined(_WIN32)
      file_input.value((string(getenv("HOMEPATH")) + "\\Desktop\\FLTK_Test.cpp").c_str());
#else
      file_input.value((string(getenv("HOME")) + "/Desktop/FLTK_Test.cpp").c_str());
#endif
      file_input.when(FL_WHEN_CHANGED);
      file_input.callback([](Fl_Widget* sender, void* data) {
        reinterpret_cast<Fl_Widget*>(data)->label(dynamic_cast<Fl_File_Input*>(sender)->value());
      }, &box);
      
      box.align(FL_ALIGN_LEFT|FL_ALIGN_CLIP|FL_ALIGN_INSIDE);
      box.label(file_input.value());
    }
    
  private:
    Fl_File_Input file_input {10, 10, 280, 35};
    Fl_Box box {10, 55, 280, 25, ""};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

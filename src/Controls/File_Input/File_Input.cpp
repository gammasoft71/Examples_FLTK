#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_File_Input.H>
#include <FL/Fl_Window.H>
#include <filesystem>

using namespace std::filesystem;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "File input example"} {
      file_input.value((home_path / "Desktop" / "FLTK_Test.cpp").c_str());
      file_input.when(FL_WHEN_CHANGED);
      file_input.callback([](Fl_Widget* sender, void* data) {
        reinterpret_cast<Fl_Widget*>(data)->label(dynamic_cast<Fl_File_Input*>(sender)->value());
      }, &box);
      
      box.align(FL_ALIGN_LEFT|FL_ALIGN_CLIP|FL_ALIGN_INSIDE);
      box.label(file_input.value());
    }
    
  private:
#if defined(_WIN32)
    path home_path = getenv("HOMEPATH");
#else
    path home_path = getenv("HOME");
#endif
    Fl_File_Input file_input {10, 10, 280, 35};
    Fl_Box box {10, 55, 280, 25, ""};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

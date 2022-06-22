#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

#ifdef _WIN32
#  define popen _popen
#endif

using namespace std;
using namespace std::filesystem;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Hello world (say)") {
      std::ofstream file(temp_directory_path()/"say.cmd");
#if _WIN32
      file << "@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say.vbs\n@echo Speaker.Speak %* >> %TEMP%\\say.vbs\n@%TEMP%\\say.vbs";
#elif __APPLE__
      file << "say $*";
#else
      file << "spd-say $*";
#endif
      permissions(temp_directory_path()/"say.cmd", perms::owner_all);

      button1.callback([](Fl_Widget* sender, void* window) {
        popen(((temp_directory_path()/"say.cmd").string() + " \"Hello, World!\"").c_str(), "r");
      }, this);
    }
    
  private:
    Fl_Button button1 {10, 10, 75, 25, "Say..."};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

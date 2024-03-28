#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_File_Browser.H>
#include <FL/Fl_Window.H>
#include <cstdlib>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 500, 255, "File browser example"} {
      file_browser.type(FL_HOLD_BROWSER);
      file_browser.filetype(Fl_File_Browser::FILES);
      file_browser.filter("*.*");
      file_browser.load(current_path.c_str());
      file_browser.callback(on_file_brawser_click, this);
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    
  private:
    static void on_file_brawser_click(Fl_Widget* sender, void* data) noexcept {
      auto file_browser = static_cast<Fl_File_Browser*>(sender);
      auto window = reinterpret_cast<Main_Window*>(data);
      if (file_browser->value() < 1 || string {file_browser->text(file_browser->value())} == ".Trash/") return;
      
      auto item = path {file_browser->text(file_browser->value())};
      if (!is_directory(window->current_path / item)) window->box1.copy_label((window->current_path / item).lexically_normal().c_str());
      else {
        if ((status(window->current_path / item).permissions() & perms::owner_exec) != perms::owner_exec) return;
        window->current_path = window->current_path / item;
        file_browser->load(window->current_path.c_str());
      }
    }
    
#if defined(_WIN32)
    path current_path = getenv("HOMEPATH");
#else
    path current_path = getenv("HOME");
#endif
    Fl_File_Browser file_browser {10, 10, 480, 200};
    Fl_Box box1 {10, 220, 480, 25, "(none)"};
  };
}

auto main(int argc, char *argv[]) -> int {
  Fl_File_Icon::load_system_icons();
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

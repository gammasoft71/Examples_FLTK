#include <filesystem>
#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::filesystem;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Box with picture 2 example"} {
      resizable(box1);

      box1.align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      box1.box(FL_GTK_DOWN_BOX);
    }
    
    void show(int argc, char** argv) {
#if __APPLE__
      picture = make_unique<Fl_PNG_Image>((path {argv[0]}.remove_filename()/".."/"Resources"/"Logo.png").string().c_str());
#else
      picture = make_unique<Fl_PNG_Image>((path {argv[0]}.remove_filename()/"Resources"/"Logo.png").string().c_str());
#endif
      box1.image(picture.get());
      Fl_Window::show(argc, argv);
    }
    
  private:
    Fl_Box box1 {20, 20, 260, 260};
    unique_ptr<Fl_PNG_Image> picture;
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Tree example"} {
      tree.showroot(false);
      auto root_item = tree.add("Root");
      auto first_item = tree.add("Root/First");
      tree.add("Root/First/Second");
      tree.add("Root/First/Third");
      auto fourth_item = tree.add("Root/Fourth");
      tree.add("Root/Fourth/Fifth");
      tree.add("Root/Fourth/Sixth");
      tree.add("Root/Fourth/Seventh");
      tree.select(root_item);
      tree.callback([](Fl_Widget* sender, void* data) {
        reinterpret_cast<Fl_Widget*>(data)->copy_label(dynamic_cast<Fl_Tree*>(sender)->callback_item()->label());
      }, &box);
      
      box.align(FL_ALIGN_LEFT | FL_ALIGN_CLIP | FL_ALIGN_INSIDE);
    }
    
  private:
    Fl_Tree tree {10, 10, 150, 200};
    Fl_Box box {10, 220, 150, 25, "Root"};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

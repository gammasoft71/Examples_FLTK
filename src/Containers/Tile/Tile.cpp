#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 200, "Tile example"} {
      size_range(300, 200);
      resizable(tile);
      
      box_red.color(fl_color_average(FL_RED, FL_WHITE, 0.5));
      box_red.box(FL_FLAT_BOX);
      
      box_green.color(fl_color_average(FL_DARK_GREEN, FL_WHITE, 0.5));
      box_green.box(FL_FLAT_BOX);
      
      box_blue.color(fl_color_average(FL_BLUE, FL_WHITE, 0.5));
      box_blue.box(FL_FLAT_BOX);
      
      box_yellow.color(fl_color_average(FL_YELLOW, FL_WHITE, 0.5));
      box_yellow.box(FL_FLAT_BOX);
    }
    
  private:
    Fl_Tile tile {0, 0, 300, 200};
    Fl_Box box_red {0, 0, 200, 100};
    Fl_Box box_green {0, 100, 100, 100};
    Fl_Box box_blue {100, 100, 100, 100};
    Fl_Box box_yellow {200, 0, 100, 200};
    Fl_End end_tile;
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

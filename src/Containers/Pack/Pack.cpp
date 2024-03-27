#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 860, 450, "Pack example"} {
      pack1.spacing(10);
      box_red1.color(fl_color_average(FL_RED, FL_WHITE, 0.5));
      box_red1.box(FL_FLAT_BOX);
      
      box_green1.color(fl_color_average(FL_DARK_GREEN, FL_WHITE, 0.5));
      box_green1.box(FL_FLAT_BOX);
      
      box_blue1.color(fl_color_average(FL_BLUE, FL_WHITE, 0.5));
      box_blue1.box(FL_FLAT_BOX);
      
      box_yellow1.color(fl_color_average(FL_YELLOW, FL_WHITE, 0.5));
      box_yellow1.box(FL_FLAT_BOX);

      pack2.type(Fl_Pack::HORIZONTAL);
      pack2.spacing(10);

      box_red2.color(fl_color_average(FL_RED, FL_WHITE, 0.5));
      box_red2.box(FL_FLAT_BOX);
      
      box_green2.color(fl_color_average(FL_DARK_GREEN, FL_WHITE, 0.5));
      box_green2.box(FL_FLAT_BOX);
      
      box_blue2.color(fl_color_average(FL_BLUE, FL_WHITE, 0.5));
      box_blue2.box(FL_FLAT_BOX);
      
      box_yellow2.color(fl_color_average(FL_YELLOW, FL_WHITE, 0.5));
      box_yellow2.box(FL_FLAT_BOX);
    }
    
  private:
    Fl_Pack pack1 {10, 10, 400, 0};
    Fl_Box box_red1 {0, 0, 0, 100};
    Fl_Box box_green1 {0, 0, 0, 100};
    Fl_Box box_blue1 {0, 0, 0, 100};
    Fl_Box box_yellow1 {0, 0, 0, 100};
    Fl_End end_pack1;
    Fl_Pack pack2 {420, 10, 0, 430};
    Fl_Box box_red2 {0, 0, 100, 0};
    Fl_Box box_green2 {0, 0, 100, 0};
    Fl_Box box_blue2 {0, 0, 100, 0};
    Fl_Box box_yellow2 {0, 0, 100, 0};
    Fl_End end_pack2;
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

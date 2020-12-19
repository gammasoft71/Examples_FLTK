#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Table.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Start_Trek_Character_Table : public Fl_Table {
  public:
    Start_Trek_Character_Table(int x, int y, int width, int height) : Fl_Table(x, y, width, height) {
      rows(datas.size());
      cols(datas[0].size());
      col_header(true);
      col_width(0, 130);
      col_width(1, 80);
      col_width(2, 90);
      col_width(3, 310);
      col_width(4, 160);
    }

  private:
    static void draw_header(const std::string& value, int x, int y, int width, int height) {
      fl_push_clip(x, y, width, height);
      fl_draw_box(FL_THIN_UP_BOX, x, y, width, height, FL_BACKGROUND_COLOR);
      fl_color(FL_FOREGROUND_COLOR);
      fl_font(FL_HELVETICA_BOLD, FL_NORMAL_SIZE);
      fl_draw(value.c_str(), x, y, width, height, FL_ALIGN_CENTER);
      fl_pop_clip();
    }

    static void draw_data(const std::string& value, int x, int y, int width, int height) {
      fl_push_clip(x, y, width, height);
      fl_color(FL_BACKGROUND2_COLOR);
      fl_rectf(x, y, width, height);
      fl_color(FL_FOREGROUND_COLOR);
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      fl_draw(value.c_str(), x + 2, y, width, height, FL_ALIGN_LEFT);
      fl_color(FL_BACKGROUND_COLOR);
      fl_rect(x, y, width, height);
      fl_pop_clip();
    }

    void draw_cell(TableContext context, int row = 0, int col = 0, int x = 0, int y = 0, int width = 0, int height = 0) override {
      switch (context) {
        case CONTEXT_COL_HEADER: draw_header(col_header_datas[col], x, y, width, height);  return;
        case CONTEXT_CELL: draw_data(datas[row][col], x, y, width, height); return;
        default: return;
      }
    }

    std::vector<std::string> col_header_datas {"Name", "Gender", "Species", "Affiliation", "Rank"};
    std::vector<std::vector<std::string>> datas {
      {"James T. Kirk", "Male", "Human", "Federation Starfleet", "Captain"},
      {"Worf", "Male", "Klingon", "Federation Starfleet / House of Martok", "Lieutenant Commander"},
      {"T'Pol", "Female", "Vulcan", "Vulcan High Command / United Earth Starfleet", "Commander"},
      {"Kira Nerys", "Female", "Bajoran", "Bajoran Militia / Federation Starfleet", "Colonel / Commander"},
      {"Phlox", "Male", "Denobulan", "Interspecies Medical Exchange", "Doctor"},
      {"Jean-Luc Picard", "Male", "Human", "Federation Starfleet", "Amiral"},
      {"The Doctor (EMH)", "Hologram", "Male", "\"USS Voyager\"", "Chief Medical Officer"},
    };
  };
  
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 792, 215, "Table example") {
      resizable(table);
    }
    
  private:
    Start_Trek_Character_Table table {10, 10, 772, 195};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

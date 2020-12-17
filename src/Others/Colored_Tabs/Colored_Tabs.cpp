#include <FL/Fl.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Window.H>

class Main_Window : public Fl_Window {
public:
  Main_Window() : Fl_Window(200, 100, 390, 305, "Colored tabs example") {
    page_red.color(FL_RED);
    page_green.color(FL_DARK_GREEN);
    page_blue.color(FL_BLUE);
    page_yellow.color(FL_YELLOW);
    
    color_tabs_check_button.callback([](Fl_Widget* sender, void* data) {
      auto window = reinterpret_cast<Main_Window*>(data);
      auto color_tabs = dynamic_cast<Fl_Check_Button*>(sender)->value();
      
      window->page_red.color2(color_tabs ? FL_RED : FL_BACKGROUND_COLOR);
      window->page_red.labelcolor(color_tabs ? FL_WHITE : FL_FOREGROUND_COLOR);
      window->page_green.color2(color_tabs ? FL_DARK_GREEN : FL_BACKGROUND_COLOR);
      window->page_green.labelcolor(color_tabs ? FL_WHITE : FL_FOREGROUND_COLOR);
      window->page_blue.color2(color_tabs ? FL_BLUE : FL_BACKGROUND_COLOR);
      window->page_blue.labelcolor(color_tabs ? FL_WHITE : FL_FOREGROUND_COLOR);
      window->page_yellow.color2(color_tabs ? FL_YELLOW : FL_BACKGROUND_COLOR);

      window->tabs.color2(color_tabs ? FL_SELECTION_COLOR : FL_BACKGROUND_COLOR);
      window->tabs.labelcolor(color_tabs ? FL_WHITE : FL_FOREGROUND_COLOR);

      window->tabs.redraw();
    }, this);
  }
  
private:
  Fl_Tabs tabs {10, 10, 370, 250};
  Fl_Group page_red {10, 10, 370, 230, "Red"};
  Fl_End end_page_red;
  Fl_Group page_green {10, 10, 370, 230, "Green"};
  Fl_End end_page_green;
  Fl_Group page_blue {10, 10, 370, 230, "Blue"};
  Fl_End end_page_blue;
  Fl_Group page_yellow {10, 10, 370, 230, "Yellow"};
  Fl_End end_page_yellow;
  Fl_End end_tabs;
  Fl_Check_Button color_tabs_check_button {10, 270, 100, 25, "Color tabs"};
};

int main(int argc, char *argv[]) {
  Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

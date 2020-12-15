#include "Fl_Scheme_Mode.h"
#include <initializer_list>
#include <limits>
#include <map>
#include <memory>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Hor_Nice_Slider.H>
#include <FL/fl_message.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 800, 450, "Schemes and scheme modes example") {
      resizable(this);

      tabs = make_unique<Fl_Tabs>(10, 10, w() - 20,h() - 70);
      buttons_page = make_unique<Fl_Group>(tabs->x(), tabs->y() + 20, tabs->w(), tabs->h() - 20, "Buttons");
      buttons_scroll = make_unique<Fl_Scroll>(tabs->x() + 1, tabs->y() + 21, tabs->w() - 2, tabs->h() - 22);
      button1 = make_unique<Fl_Button>(20, 40, 75, 25, "Message");
      toggle_button1 = make_unique<Fl_Toggle_Button>(120, 40, 75, 25, "Toggle");
      light_button1 = make_unique<Fl_Light_Button>(20, 70, 75, 25, "Light");
      return_button1 = make_unique<Fl_Return_Button>(120, 70, 75, 25, "Return");
      radio1 = make_unique<Fl_Radio_Round_Button>(20, 100, 90, 25, "Raddio 1");
      radio2 = make_unique<Fl_Radio_Round_Button>(120, 100, 90, 25, "Raddio 2");
      check_button1 = make_unique<Fl_Check_Button>(20, 130, 90, 25, "Raddio 1");
      check_button2 = make_unique<Fl_Check_Button>(120, 130, 90, 25, "Raddio 2");
      box1 = make_unique<Fl_Box>(20, 160, 90, 25, "Show mode");
      input1 = make_unique<Fl_Input>(120, 160, 180, 25);
      buttons_scroll->end();
      buttons_page->end();

      browsers_page = make_unique<Fl_Group>(tabs->x(), tabs->y() + 20, tabs->w(), tabs->h() - 20, "Browsers");
      browsers_scroll = make_unique<Fl_Scroll>(tabs->x() + 1, tabs->y() + 21, tabs->w() - 2, tabs->h() - 22);
      browser1 = make_unique<Fl_Browser>(20, 40, 120, 100);
      check_browser1 = make_unique<Fl_Check_Browser>(150, 40, 120, 100);
      browsers_scroll->end();
      browsers_page->end();

      slider_page = make_unique<Fl_Group>(tabs->x(), tabs->y() + 20, tabs->w(), tabs->h() - 20, "Slider");
      slider_scroll = make_unique<Fl_Scroll>(tabs->x() + 1, tabs->y() + 21, tabs->w() - 2, tabs->h() - 22);
      slider1 = make_unique<Fl_Hor_Nice_Slider>(20, 40, 290, 25);
      progress1 = make_unique<Fl_Progress>(20, 80, 290, 25);
      slider_scroll->end();
      slider_page->end();
      
      tabs->end();
      
      scheme_choice = make_unique<Fl_Choice>(70, h() - 35, 80, 25, "Scheme");
      scheme_mode_choice = make_unique<Fl_Choice>(210, h() - 35, 80, 25, "Mode");

      end();

      button1->callback([](Fl_Widget* sender, void* window) {
        fl_message_hotspot(false);
        fl_message_icon()->color(fl_rgb_color(0, 0, 255));
        fl_message_icon()->label("i");
        fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
        fl_choice("Message with dark mode enabled...", "&OK", nullptr, nullptr);
      }, this);

      browser1->type(FL_HOLD_BROWSER);
      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"}) {
        browser1->add(item);
        check_browser1->add(item);
      }
      browser1->select(1);

      radio1->value(true);

      check_button2->value(true);

      input1->value("Input text");
      
      slider1->type(FL_HOR_NICE_SLIDER);
      slider1->maximum(100);
      slider1->value(50);
      slider1->color2(FL_SELECTION_COLOR);
      slider1->callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->progress1->value(dynamic_cast<Fl_Slider*>(sender)->value());
        reinterpret_cast<Main_Window*>(window)->progress1->copy_label((to_string((static_cast<int>(dynamic_cast<Fl_Slider*>(sender)->value()))) + "%").c_str());
      }, this);

      progress1->value(slider1->value());
      progress1->copy_label((to_string((static_cast<int>(slider1->value()))) + "%").c_str());
      progress1->color2(FL_SELECTION_COLOR);
      
      for (auto item : {"basic", "plastic", "gtk+", "gleam"})
        scheme_choice->add(item);
      scheme_choice->value(0);
      scheme_choice->callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->update_theme_and_mode();
      }, this);

      for (auto item : {"default", "light", "dark", "white", "black", "red", "green", "blue"})
        scheme_mode_choice->add(item);
      scheme_mode_choice->value(0);
      scheme_mode_choice->callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->update_theme_and_mode();
      }, this);
    }

  protected:
    void resize(int x, int y, int w, int h) override {
      Fl_Window::resize(x, y, w, h);
      tabs->resize(10, 10, w - 20, h - 65);
      buttons_page->resize(10, 30, w - 20, h - 85);
      browsers_page->resize(10, 30, w - 20, h - 85);
      slider_page->resize(10, 30, w - 20, h - 85);
      scheme_choice->resize(70, h - 35, 80, 25);
      scheme_mode_choice->resize(210, h - 35, 80, 25);
    }
    
    void draw() override {
      Fl_Window::draw();
      draw_box(Fl_Boxtype::FL_FLAT_BOX, 10, h() - 45, w() - 20, 1, fl_darker(color()));
      draw_box(Fl_Boxtype::FL_FLAT_BOX, 11, h() - 44, w() - 20, 1, fl_lighter(color()));
    }
    
  private:
    void update_theme_and_mode() {
      if (scheme_choice->value() == 1) fl_scheme_mode(Fl_Scheme_Mode::default_mode); // Workaround : with scheme "plastic", window background was not correctly refresh...
      Fl::scheme(scheme_choice->text(scheme_choice->value()));
      static map<string, Fl_Scheme_Mode> scheme_modes = {{"default", Fl_Scheme_Mode::default_mode}, {"light", Fl_Scheme_Mode::light}, {"dark", Fl_Scheme_Mode::dark}, {"white", Fl_Scheme_Mode::white}, {"black", Fl_Scheme_Mode::black}, {"red", Fl_Scheme_Mode::red}, {"green", Fl_Scheme_Mode::green}, {"blue", Fl_Scheme_Mode::blue}};
      fl_scheme_mode(scheme_modes[scheme_mode_choice->text(scheme_mode_choice->value())]);
    }
    
    unique_ptr<Fl_Tabs> tabs;
    unique_ptr<Fl_Group> buttons_page;
    unique_ptr<Fl_Group> browsers_page;
    unique_ptr<Fl_Group> slider_page;
    unique_ptr<Fl_Scroll> buttons_scroll;
    unique_ptr<Fl_Scroll> browsers_scroll;
    unique_ptr<Fl_Scroll> slider_scroll;
    unique_ptr<Fl_Box> box1;
    unique_ptr<Fl_Button> button1;
    unique_ptr<Fl_Toggle_Button> toggle_button1;
    unique_ptr<Fl_Light_Button> light_button1;
    unique_ptr<Fl_Return_Button> return_button1;
    unique_ptr<Fl_Radio_Round_Button> radio1;
    unique_ptr<Fl_Radio_Round_Button> radio2;
    unique_ptr<Fl_Check_Button> check_button1;
    unique_ptr<Fl_Check_Button> check_button2;
    unique_ptr<Fl_Browser> browser1;
    unique_ptr<Fl_Check_Browser> check_browser1;
    unique_ptr<Fl_Input> input1;
    unique_ptr<Fl_Hor_Nice_Slider> slider1;
    unique_ptr<Fl_Progress> progress1;
    unique_ptr<Fl_Choice> scheme_mode_choice;
    unique_ptr<Fl_Choice> scheme_choice;
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

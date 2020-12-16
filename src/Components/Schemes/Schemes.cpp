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
#include <FL/Fl_Dial.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Hor_Nice_Slider.H>
#include <FL/fl_message.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Roller.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 450, 350, "Scheme example") {
      resizable(this);

      tabs = make_unique<Fl_Tabs>(10, 10, w() - 20,h() - 70);
      buttons_page = make_unique<Fl_Group>(tabs->x(), tabs->y() + 20, tabs->w(), tabs->h() - 20, "Buttons");
      buttons_scroll = make_unique<Fl_Scroll>(tabs->x() + 1, tabs->y() + 21, tabs->w() - 2, tabs->h() - 22);
      button1 = make_unique<Fl_Button>(20, 40, 75, 25, "Message");
      toggle_button1 = make_unique<Fl_Toggle_Button>(120, 40, 75, 25, "Toggle");
      light_button1 = make_unique<Fl_Light_Button>(20, 80, 75, 25, "Light");
      return_button1 = make_unique<Fl_Return_Button>(120, 80, 75, 25, "Return");
      radio1 = make_unique<Fl_Radio_Round_Button>(20, 120, 90, 25, "Raddio 1");
      radio2 = make_unique<Fl_Radio_Round_Button>(120, 120, 90, 25, "Raddio 2");
      check_button1 = make_unique<Fl_Check_Button>(20, 150, 90, 25, "Raddio 1");
      check_button2 = make_unique<Fl_Check_Button>(120, 150, 90, 25, "Raddio 2");
      buttons_scroll->end();
      buttons_page->end();

      texts_page = make_unique<Fl_Group>(tabs->x(), tabs->y() + 20, tabs->w(), tabs->h() - 20, "Texts");
      texts_scroll = make_unique<Fl_Scroll>(tabs->x() + 1, tabs->y() + 21, tabs->w() - 2, tabs->h() - 22);
      box1 = make_unique<Fl_Box>(20, 40, 300, 25, "The quick brown fox jumps over the lazy dog.");
      multiline_input1 = make_unique<Fl_Multiline_Input>(20, 70, 400, 200);
      texts_scroll->end();
      texts_page->end();
      
      browsers_page = make_unique<Fl_Group>(tabs->x(), tabs->y() + 20, tabs->w(), tabs->h() - 20, "Browsers");
      browsers_scroll = make_unique<Fl_Scroll>(tabs->x() + 1, tabs->y() + 21, tabs->w() - 2, tabs->h() - 22);
      browser1 = make_unique<Fl_Browser>(20, 40, 200, 100);
      check_browser1 = make_unique<Fl_Check_Browser>(20, 160, 200, 100);
      browsers_scroll->end();
      browsers_page->end();

      slider_page = make_unique<Fl_Group>(tabs->x(), tabs->y() + 20, tabs->w(), tabs->h() - 20, "Slider");
      slider_scroll = make_unique<Fl_Scroll>(tabs->x() + 1, tabs->y() + 21, tabs->w() - 2, tabs->h() - 22);
      slider1 = make_unique<Fl_Hor_Nice_Slider>(20, 40, 290, 25);
      progress1 = make_unique<Fl_Progress>(20, 80, 290, 25);
      slider_scroll->end();
      slider_page->end();

      valuators_page = make_unique<Fl_Group>(tabs->x(), tabs->y() + 20, tabs->w(), tabs->h() - 20, "Valuators");
      valuators_scroll = make_unique<Fl_Scroll>(tabs->x() + 1, tabs->y() + 21, tabs->w() - 2, tabs->h() - 22);
      dial1 = make_unique<Fl_Dial>(20, 40, 75, 75);
      roller1 = make_unique<Fl_Roller>(45, 130, 25, 100);
      slider_scroll->end();
      slider_page->end();

      tabs->end();
      
      scheme_choice = make_unique<Fl_Choice>(70, h() - 35, 80, 25, "Scheme");

      end();

      button1->callback([](Fl_Widget* sender, void* window) {
        fl_message_hotspot(false);
        fl_message_icon()->color(fl_rgb_color(0, 0, 255));
        fl_message_icon()->label("i");
        fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
        fl_choice("Message with dark mode enabled...", "&OK", nullptr, nullptr);
      }, this);

      toggle_button1->value(true);
      light_button1->value(true);
      radio1->value(true);
      check_button2->value(true);

      box1->align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_CLIP | FL_ALIGN_INSIDE);
      box1->box(Fl_Boxtype::FL_FLAT_BOX);
      multiline_input1->value("The quick brown fox jumps over the lazy dog.\n"
                              "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
                              "0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
                              "àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
                              "\u0400\u0401\u0402\u0403\u0404\u0405\u0406\u0407\u0408\u0409\u040a\u040b\u040c\u040d\u040e\u040f\n"
                              "\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041a\u041b\u041c\u041d\u041e\u041f\n"
                              "\u4ea0\u4ea1\u4ea2\u4ea3\u4ea4\u4ea5\u4ea6\u4ea7\u4ea8\u4ea9\u4eaa\u4eab\u4eac\u4ead\u4eae\u4eaf\n"
                              "\u4eb0\u4eb1\u4eb2\u4eb3\u4eb4\u4eb5\u4eb6\u4eb7\u4eb8\u4eb9\u4eba\u4ebb\u4ebc\u4ebd\u4ebe\u4ebf\n"
                              "\U0001F428");

      browser1->type(FL_HOLD_BROWSER);
      for (auto item : {"Light red", "Light green", "Light blue", "Yellow", "White", "Dark gray", "Light cyan", "Light magenta", "Red", "Green", "Blue", "Brown", "Light gray", "Black", "Cyan", "Magenta"}) {
        browser1->add(item);
        check_browser1->add(item);
      }
      browser1->select(1);
      check_browser1->checked(1, true);
      check_browser1->checked(4, true);

      slider1->type(FL_HOR_NICE_SLIDER);
      slider1->maximum(100);
      slider1->value(50);
      slider1->callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->progress1->value(dynamic_cast<Fl_Slider*>(sender)->value());
        reinterpret_cast<Main_Window*>(window)->progress1->copy_label((to_string((static_cast<int>(dynamic_cast<Fl_Slider*>(sender)->value()))) + "%").c_str());
      }, this);
      progress1->value(slider1->value());
      progress1->copy_label((to_string((static_cast<int>(slider1->value()))) + "%").c_str());
      
      for (auto item : {"basic", "plastic", "gtk+", "gleam"})
        scheme_choice->add(item);
      scheme_choice->value(0);
      scheme_choice->callback([](Fl_Widget* sender, void* window) {
        auto scheme_choice = dynamic_cast<Fl_Choice*>(sender);
        Fl::scheme(scheme_choice->text(scheme_choice->value()));
      }, this);
    }

  protected:
    void resize(int x, int y, int w, int h) override {
      Fl_Window::resize(x, y, w, h);
      tabs->resize(10, 10, w - 20, h - 65);
      buttons_page->resize(10, 30, w - 20, h - 85);
      texts_page->resize(10, 30, w - 20, h - 85);
      browsers_page->resize(10, 30, w - 20, h - 85);
      slider_page->resize(10, 30, w - 20, h - 85);
      scheme_choice->resize(70, h - 35, 80, 25);
    }
    
    void draw() override {
      Fl_Window::draw();
      draw_box(Fl_Boxtype::FL_FLAT_BOX, 10, h() - 45, w() - 20, 1, fl_darker(color()));
      draw_box(Fl_Boxtype::FL_FLAT_BOX, 11, h() - 44, w() - 20, 1, fl_lighter(color()));
    }
    
  private:
    unique_ptr<Fl_Tabs> tabs;

    unique_ptr<Fl_Group> buttons_page;
    unique_ptr<Fl_Scroll> buttons_scroll;
    unique_ptr<Fl_Button> button1;
    unique_ptr<Fl_Toggle_Button> toggle_button1;
    unique_ptr<Fl_Light_Button> light_button1;
    unique_ptr<Fl_Return_Button> return_button1;
    unique_ptr<Fl_Radio_Round_Button> radio1;
    unique_ptr<Fl_Radio_Round_Button> radio2;
    unique_ptr<Fl_Check_Button> check_button1;
    unique_ptr<Fl_Check_Button> check_button2;

    unique_ptr<Fl_Group> texts_page;
    unique_ptr<Fl_Scroll> texts_scroll;
    unique_ptr<Fl_Box> box1;
    unique_ptr<Fl_Multiline_Input> multiline_input1;

    unique_ptr<Fl_Group> browsers_page;
    unique_ptr<Fl_Scroll> browsers_scroll;
    unique_ptr<Fl_Browser> browser1;
    unique_ptr<Fl_Check_Browser> check_browser1;

    unique_ptr<Fl_Group> slider_page;
    unique_ptr<Fl_Scroll> slider_scroll;
    unique_ptr<Fl_Hor_Nice_Slider> slider1;
    unique_ptr<Fl_Progress> progress1;

    unique_ptr<Fl_Group> valuators_page;
    unique_ptr<Fl_Scroll> valuators_scroll;
    unique_ptr<Fl_Dial> dial1;
    unique_ptr<Fl_Roller> roller1;

    unique_ptr<Fl_Choice> scheme_choice;
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

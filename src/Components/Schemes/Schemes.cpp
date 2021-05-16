#include <initializer_list>
#include <map>
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
    Main_Window() : Fl_Window(200, 100, 450, 350, "Schemes example") {
      resizable(this);
      
      button1.callback([](Fl_Widget* sender, void* window) {
        fl_message_icon()->box(FL_ROUND_UP_BOX);
        fl_message_icon()->color(fl_rgb_color(0, 0, 255));
        fl_message_icon()->label("i");
        fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
        fl_message_title("Message");
        fl_choice("This is an example of message...", nullptr, fl_ok, nullptr);
      }, this);
      
      toggle_button1.value(true);
      light_button1.value(true);
      radio1.value(true);
      check_button2.value(true);
      
      box1.align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_CLIP | FL_ALIGN_INSIDE);
      box1.box(Fl_Boxtype::FL_FLAT_BOX);
      multiline_input1.value("The quick brown fox jumps over the lazy dog.\n"
                             "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
                             "0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
                             "àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
                             "\u0400\u0401\u0402\u0403\u0404\u0405\u0406\u0407\u0408\u0409\u040a\u040b\u040c\u040d\u040e\u040f\n"
                             "\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041a\u041b\u041c\u041d\u041e\u041f\n"
                             "\u4ea0\u4ea1\u4ea2\u4ea3\u4ea4\u4ea5\u4ea6\u4ea7\u4ea8\u4ea9\u4eaa\u4eab\u4eac\u4ead\u4eae\u4eaf\n"
                             "\u4eb0\u4eb1\u4eb2\u4eb3\u4eb4\u4eb5\u4eb6\u4eb7\u4eb8\u4eb9\u4eba\u4ebb\u4ebc\u4ebd\u4ebe\u4ebf\n"
                             "\U0001F428");
      
      browser1.type(FL_HOLD_BROWSER);
      for (auto item : {"Light red", "Light green", "Light blue", "Yellow", "White", "Dark gray", "Light cyan", "Light magenta", "Red", "Green", "Blue", "Brown", "Light gray", "Black", "Cyan", "Magenta"}) {
        browser1.add(item);
        check_browser1.add(item);
      }
      browser1.select(1);
      check_browser1.checked(1, true);
      check_browser1.checked(4, true);
      
      slider1.type(FL_HOR_NICE_SLIDER);
      slider1.maximum(100);
      slider1.value(50);
      slider1.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->progress1.value(dynamic_cast<Fl_Slider*>(sender)->value());
        reinterpret_cast<Main_Window*>(window)->progress1.copy_label((to_string((static_cast<int>(dynamic_cast<Fl_Slider*>(sender)->value()))) + "%").c_str());
      }, this);
      progress1.value(slider1.value());
      progress1.copy_label((to_string((static_cast<int>(slider1.value()))) + "%").c_str());
      
      for (auto item : {"basic", "plastic", "gtk+", "gleam"})
        scheme_choice.add(item);
      scheme_choice.value(0);
      scheme_choice.callback([](Fl_Widget* sender, void* window) {
        Fl::scheme(reinterpret_cast<Main_Window*>(window)->scheme_choice.text(reinterpret_cast<Main_Window*>(window)->scheme_choice.value()));
      }, this);
      
    }
    
  protected:
    void resize(int x, int y, int w, int h) override {
      Fl_Window::resize(x, y, w, h);
      tabs.resize(10, 10, w - 20, h - 65);
      buttons_page.resize(10, 30, w - 20, h - 85);
      texts_page.resize(10, 30, w - 20, h - 85);
      browsers_page.resize(10, 30, w - 20, h - 85);
      slider_page.resize(10, 30, w - 20, h - 85);
      scheme_choice.resize(70, h - 35, 80, 25);
    }
    
    void draw() override {
      Fl_Window::draw();
      draw_box(Fl_Boxtype::FL_FLAT_BOX, 10, h() - 45, w() - 20, 1, fl_darker(color()));
      draw_box(Fl_Boxtype::FL_FLAT_BOX, 11, h() - 44, w() - 20, 1, fl_lighter(color()));
    }
    
  private:
    Fl_Tabs tabs {10, 10, w() - 20,h() - 70};
    
    Fl_Group buttons_page {tabs.x(), tabs.y() + 20, tabs.w(), tabs.h() - 20, "Buttons"};
    Fl_Scroll buttons_scroll {tabs.x() + 1, tabs.y() + 21, tabs.w() - 2, tabs.h() - 22};
    Fl_Button button1 {20, 40, 75, 25, "Message"};
    Fl_Toggle_Button toggle_button1 {120, 40, 75, 25, "Toggle"};
    Fl_Light_Button light_button1 {20, 80, 75, 25, "Light"};
    Fl_Return_Button return_button1 {120, 80, 75, 25, "Return"};
    Fl_Radio_Round_Button radio1 {20, 120, 90, 25, "Raddio 1"};
    Fl_Radio_Round_Button radio2 {120, 120, 90, 25, "Raddio 2"};
    Fl_Check_Button check_button1 {20, 150, 90, 25, "Raddio 1"};
    Fl_Check_Button check_button2 {120, 150, 90, 25, "Raddio 2"};
    Fl_End end_buttons_scroll;
    Fl_End end_buttons_page;
    
    Fl_Group texts_page {tabs.x(), tabs.y() + 20, tabs.w(), tabs.h() - 20, "Texts"};
    Fl_Scroll texts_scroll {tabs.x() + 1, tabs.y() + 21, tabs.w() - 2, tabs.h() - 22};
    Fl_Box box1 {20, 40, 300, 25, "The quick brown fox jumps over the lazy dog."};
    Fl_Multiline_Input multiline_input1 {20, 70, 400, 200};
    Fl_End end_texts_scroll;
    Fl_End end_texts_page;
    
    Fl_Group browsers_page {tabs.x(), tabs.y() + 20, tabs.w(), tabs.h() - 20, "Browsers"};
    Fl_Scroll browsers_scroll {tabs.x() + 1, tabs.y() + 21, tabs.w() - 2, tabs.h() - 22};
    Fl_Browser browser1 {20, 40, 200, 100};
    Fl_Check_Browser check_browser1 {20, 160, 200, 100};
    Fl_End end_browser_scroll;
    Fl_End end_browser_page;
    
    Fl_Group slider_page {tabs.x(), tabs.y() + 20, tabs.w(), tabs.h() - 20, "Slider and progress"};
    Fl_Scroll slider_scroll {tabs.x() + 1, tabs.y() + 21, tabs.w() - 2, tabs.h() - 22};
    Fl_Hor_Nice_Slider slider1 {20, 40, 290, 25};
    Fl_Progress progress1 {20, 80, 290, 25};
    Fl_End end_slider_scroll;
    Fl_End end_slider_page;
    
    Fl_Group valuators_page {tabs.x(), tabs.y() + 20, tabs.w(), tabs.h() - 20, "Valuators"};
    Fl_Scroll valuators_scroll {tabs.x() + 1, tabs.y() + 21, tabs.w() - 2, tabs.h() - 22};
    Fl_Dial dial1 {20, 40, 75, 75};
    Fl_Roller roller1 {45, 130, 25, 100};
    Fl_End end_valuators_scroll;
    Fl_End end_valuators_page;
    
    Fl_End end_tabs;
    
    Fl_Choice scheme_choice {70, h() - 35, 80, 25, "Scheme"};
  };
}

int main(int argc, char *argv[]) {
  fl_message_hotspot(false);
  fl_message_icon()->labelfont(FL_HELVETICA_BOLD);
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

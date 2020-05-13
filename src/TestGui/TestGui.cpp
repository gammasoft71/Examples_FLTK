#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

using namespace std;
using namespace std::literals;

int main() {
  //setenv("FLTK_SCHEME", "gtk+", 1);
  Fl::get_system_colors();
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  Fl::scheme(nullptr);

  printf("color = 0x%X\n", fl_lighter(fl_lighter(fl_lighter(fl_rgb_color(128, 128, 128)))));
  printf("color = 0x%X\n", fl_lighter(fl_lighter(fl_rgb_color(128, 128, 128))));
  printf("color = 0x%X\n", fl_lighter(fl_rgb_color(128, 128, 128)));
  printf("color = 0x%X\n", fl_rgb_color(128, 128, 128));
  printf("color = 0x%X\n", fl_darker(fl_rgb_color(128, 128, 128)));
  printf("color = 0x%X\n", fl_darker(fl_darker(fl_rgb_color(128, 128, 128))));

  Fl_Window form(200, 100, 100, 300, "TestGui");
  
  Fl_Button button1(10, 10, 75, 25, "Click me");
  button1.color(fl_lighter(fl_lighter(fl_lighter(fl_lighter(button1.color())))));
  button1.selection_color(fl_lighter(fl_lighter(fl_lighter(fl_lighter(button1.selection_color())))));
  Fl_Button button2(10, 40, 75, 25, "Click me");
  button2.color(fl_lighter(fl_lighter(fl_lighter(button2.color()))));
  button2.selection_color(fl_lighter(fl_lighter(fl_lighter(button2.selection_color()))));
  Fl_Button button3(10, 70, 75, 25, "Click me");
  button3.color(fl_lighter(fl_lighter(button3.color())));
  button3.selection_color(fl_lighter(fl_lighter(button3.selection_color())));
  Fl_Button button4(10, 100, 75, 25, "Click me");
  button4.color(fl_lighter(button4.color()));
  button4.selection_color(fl_lighter(button4.selection_color()));
  Fl_Button button5(10, 130, 75, 25, "Click me");
  button5.color(button5.color());
  button5.selection_color(button5.selection_color());
  button5.labelcolor(button5.labelcolor());
  Fl_Button button6(10, 160, 75, 25, "Click me");
  button6.color(fl_darker(button6.color()));
  button6.selection_color(fl_darker(button6.selection_color()));
  button6.labelcolor(fl_rgb_color(255, 255, 255));
  Fl_Button button7(10, 190, 75, 25, "Click me");
  button7.color(fl_darker(fl_darker(button7.color())));
  button7.selection_color(fl_darker(fl_darker(button7.selection_color())));
  button7.labelcolor(fl_rgb_color(255, 255, 255));
  Fl_Button button8(10, 220, 75, 25, "Click me");
  button8.color(fl_darker(fl_darker(fl_darker(button8.color()))));
  button8.selection_color(fl_darker(fl_darker(fl_darker(button8.selection_color()))));
  button8.labelcolor(fl_rgb_color(255, 255, 255));
  Fl_Button button9(10, 250, 75, 25, "Click me");
  button9.color(fl_darker(fl_darker(fl_darker(fl_darker(button9.color())))));
  button9.selection_color(fl_darker(fl_darker(fl_darker(fl_darker(button9.selection_color())))));
  button9.labelcolor(fl_rgb_color(255, 255, 255));

  form.show();

  Fl::run();
}

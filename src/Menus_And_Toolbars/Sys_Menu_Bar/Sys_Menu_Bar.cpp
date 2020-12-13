#include <limits>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Sys menu bar example") {
      end();
      resizable(text_display);

      text_display.buffer(&text_buffer);

      sys_menu_bar.add("&File/&New", FL_COMMAND + 'n', Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&File/&Open", FL_COMMAND + 'o', Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&File/Open &recent/File 1", nullptr, Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&File/Open &recent/File 2", nullptr, Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&File/Open &recent/File 3", nullptr, Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&File/Open &recent/File 4", nullptr, Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&File/Open &recent/File 5", nullptr, Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&File/&Close", FL_COMMAND + 'w', Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER);
      sys_menu_bar.add("&File/&Save", FL_COMMAND + 's', Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&File/Save &as", nullptr, Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER);
      sys_menu_bar.add("&File/Page setup...", FL_COMMAND + FL_SHIFT + 'p', Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&File/&Print", FL_COMMAND + 'p', Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER);
#if !__APPLE__
      sys_menu_bar.add("&File/&Quit", FL_COMMAND + 'q', Main_Window::on_menu_item_click, this);
#endif
      sys_menu_bar.add("&Edit/&Undo", FL_COMMAND + 'z', Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&Edit/&Redo", FL_COMMAND + FL_SHIFT + 'z', Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER);
      sys_menu_bar.add("&Edit/C&ut", FL_COMMAND + 'x', Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&Edit/&Copy", FL_COMMAND + 'c', Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&Edit/&Paste", FL_COMMAND + 'v', Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER);
      sys_menu_bar.add("&Edit/Select &all", FL_COMMAND + 'a', Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&View/&Back", nullptr, Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&View/&Forward", nullptr, Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER);
      sys_menu_bar.add("&View/&Show", nullptr, Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&View/&Hide", nullptr, Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&Options/Option &A", FL_ALT + '1', Main_Window::on_menu_item_click, this, FL_MENU_TOGGLE + FL_MENU_CHECK);
      sys_menu_bar.add("&Options/Option &B", FL_ALT + '2', Main_Window::on_menu_item_click, this, FL_MENU_TOGGLE);
      sys_menu_bar.add("&Options/Option &C", FL_ALT + '3', Main_Window::on_menu_item_click, this, FL_MENU_TOGGLE + FL_MENU_CHECK + FL_MENU_DIVIDER);
      sys_menu_bar.add("&Options/Option &D", FL_ALT + '4', Main_Window::on_menu_item_click, this, FL_MENU_RADIO);
      sys_menu_bar.add("&Options/Option &E", FL_ALT + '5', Main_Window::on_menu_item_click, this, FL_MENU_RADIO + FL_MENU_CHECK);
      sys_menu_bar.add("&Options/Option &F", FL_ALT + '6', Main_Window::on_menu_item_click, this, FL_MENU_RADIO + FL_MENU_DIVIDER);
      sys_menu_bar.add("&Options/Option &G", FL_ALT + '7', Main_Window::on_menu_item_click, this, FL_MENU_RADIO);
      sys_menu_bar.add("&Options/Option &H", FL_ALT + '8', Main_Window::on_menu_item_click, this, FL_MENU_RADIO);
      sys_menu_bar.add("&Options/Option &I", FL_ALT + '9', Main_Window::on_menu_item_click, this, FL_MENU_RADIO + FL_MENU_CHECK);
      sys_menu_bar.add("&Help/Context",nullptr, Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&Help/Index",nullptr, Main_Window::on_menu_item_click, this);
      sys_menu_bar.add("&Help/Search",nullptr, Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER);
#if !__APPLE__
      sys_menu_bar.add("&Help/About",nullptr, Main_Window::on_menu_item_click, this);
#endif
    }
    
  private:
    static void on_menu_item_click(Fl_Widget* sender, void* window) {reinterpret_cast<Main_Window*>(window)->on_menu_item_click(dynamic_cast<Fl_Sys_Menu_Bar&>(*sender));}
    void on_menu_item_click(Fl_Sys_Menu_Bar& menu) {
      text_buffer.append(menu.mvalue()->label());
      text_buffer.append("\n");
      text_display.scroll(std::numeric_limits<int>::max(), 0);
      menu.value(0);
    }
    Fl_Text_Buffer text_buffer;
    Fl_Sys_Menu_Bar sys_menu_bar {0, 0, 300, 30, nullptr};
#if __APPLE__
    Fl_Text_Display text_display {0, 0, 300, 300};
#else
    Fl_Text_Display text_display {0, 30, 300, 270};
#endif
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}

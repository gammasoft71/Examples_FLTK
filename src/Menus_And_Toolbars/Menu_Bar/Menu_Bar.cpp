#include <FL/Fl.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Window.H>
#undef max
#include <limits>
#include <vector>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 300, 300, "Menu bar example"} {
      resizable(text_display);
      
      text_display.buffer(&text_buffer);
      
      menu_bar.menu(items.data());
      menu_bar.parent(this);
    }
    
  private:
    static void on_menu_item_click(Fl_Widget* sender, void* data) {
      auto menu = dynamic_cast<Fl_Menu_Bar*>(sender);
      auto window = reinterpret_cast<Main_Window*>(data);
      window->text_buffer.append(menu->mvalue()->label());
      window->text_buffer.append("\n");
      window->text_display.scroll(numeric_limits<int>::max(), 0);
      menu->value(0);
    }
    
    vector<Fl_Menu_Item> items = {
      {"&File", 0, nullptr, nullptr, FL_SUBMENU},
        {"&New", FL_COMMAND + 'n', &Main_Window::on_menu_item_click, this},
        {"&Open", FL_COMMAND + 'o', &Main_Window::on_menu_item_click, this},
        {"Open &recent", 0, nullptr, nullptr, FL_SUBMENU},
          {"File 1", 0, &Main_Window::on_menu_item_click, this},
          {"File 2", 0, &Main_Window::on_menu_item_click, this},
          {"File 3", 0, &Main_Window::on_menu_item_click, this},
          {"File 4", 0, &Main_Window::on_menu_item_click, this},
          {"File 5", 0, &Main_Window::on_menu_item_click, this},
          {0},
        {"&Close", FL_COMMAND + 'w', &Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER},
        {"&Save", FL_COMMAND + 's', &Main_Window::on_menu_item_click, this},
        {"Save &as...", 0, &Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER},
        {"Page setup...", FL_COMMAND + FL_SHIFT + 'p', &Main_Window::on_menu_item_click, this},
        {"&Print", FL_COMMAND + 'p', &Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER},
        {"&Quit", FL_COMMAND + 'q', &Main_Window::on_menu_item_click, this},
        {0},
      {"&Edit", 0, nullptr, nullptr, FL_SUBMENU},
        {"&Undo", FL_COMMAND + 'z', &Main_Window::on_menu_item_click, this},
        {"&Redo", FL_COMMAND + FL_SHIFT + 'z', &Main_Window::on_menu_item_click, this},
        {"C&ut", FL_COMMAND + 'x', Main_Window::on_menu_item_click, this},
        {"&Copy", FL_COMMAND + 'c', Main_Window::on_menu_item_click, this},
        {"&Paste", FL_COMMAND + 'v', Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER},
        {"Select &all", FL_COMMAND + 'a', Main_Window::on_menu_item_click, this},
      {0},
      {"&View", 0, nullptr, nullptr, FL_SUBMENU},
        {"&Back", 0, Main_Window::on_menu_item_click, this},
        {"&Forward", 0, Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER},
        {"&Show", 0, Main_Window::on_menu_item_click, this},
        {"&Hide", 0, Main_Window::on_menu_item_click, this},
        {0},
      {"&Options", 0, nullptr, nullptr, FL_SUBMENU},
        {"Option &A", FL_ALT + '1', Main_Window::on_menu_item_click, this, FL_MENU_TOGGLE + FL_MENU_CHECK},
        {"Option &B", FL_ALT + '2', Main_Window::on_menu_item_click, this, FL_MENU_TOGGLE},
        {"Option &C", FL_ALT + '3', Main_Window::on_menu_item_click, this, FL_MENU_TOGGLE + FL_MENU_CHECK + FL_MENU_DIVIDER},
        {"Option &D", FL_ALT + '4', Main_Window::on_menu_item_click, this, FL_MENU_RADIO},
        {"Option &E", FL_ALT + '5', Main_Window::on_menu_item_click, this, FL_MENU_RADIO + FL_MENU_CHECK},
        {"Option &F", FL_ALT + '6', Main_Window::on_menu_item_click, this, FL_MENU_RADIO + FL_MENU_DIVIDER},
        {"Option &G", FL_ALT + '7', Main_Window::on_menu_item_click, this, FL_MENU_RADIO},
        {"Option &H", FL_ALT + '8', Main_Window::on_menu_item_click, this, FL_MENU_RADIO},
        {"Option &I", FL_ALT + '9', Main_Window::on_menu_item_click, this, FL_MENU_RADIO + FL_MENU_CHECK},
        {0},
      {"&Help", 0, nullptr, nullptr, FL_SUBMENU},
        {"Context", 0, Main_Window::on_menu_item_click, this},
        {"Index", 0, Main_Window::on_menu_item_click, this},
        {"Search", 0, Main_Window::on_menu_item_click, this, FL_MENU_DIVIDER},
        {"About", 0, Main_Window::on_menu_item_click, this},
        {0},
      {0}
    };
    
    Fl_Text_Buffer text_buffer;
    Fl_Menu_Bar menu_bar {0, 0, 300, 30, nullptr};
    Fl_Text_Display text_display {0, 30, 300, 270};
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}

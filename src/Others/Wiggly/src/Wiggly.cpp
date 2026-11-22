#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/fl_draw.H>
#include <string>
#include <array>
#include <cmath>

[[nodiscard]] auto fl_hsv_color(double hue, double saturation, double value) noexcept -> Fl_Color {
  if (saturation == 0.0) return fl_rgb_color(static_cast<std::uint8_t>(value * 255), static_cast<std::uint8_t>(value * 255), static_cast<std::uint8_t>(value * 255));
  
  hue = hue >= 360 ? 0 : hue / 60;
  
  auto f = hue - std::trunc(hue);
  auto p = value * (1.0f - saturation);
  auto q = value * (1.0f - (saturation * f));
  auto t = value * (1.0f - (saturation * (1.0f - f)));
  
  switch (static_cast<std::int32_t>(std::trunc(hue))) {
    case 0: return fl_rgb_color(static_cast<std::uint8_t>(value * 255), static_cast<std::uint8_t>(t * 255), static_cast<std::uint8_t>(p * 255));
    case 1: return fl_rgb_color(static_cast<std::uint8_t>(q * 255), static_cast<std::uint8_t>(value * 255), static_cast<std::uint8_t>(p * 255));
    case 2: return fl_rgb_color(static_cast<std::uint8_t>(p * 255), static_cast<std::uint8_t>(value * 255), static_cast<std::uint8_t>(t * 255));
    case 3: return fl_rgb_color(static_cast<std::uint8_t>(p * 255), static_cast<std::uint8_t>(q * 255), static_cast<std::uint8_t>(value * 255));
    case 4: return fl_rgb_color(static_cast<std::uint8_t>(t * 255), static_cast<std::uint8_t>(p * 255), static_cast<std::uint8_t>(value * 255));
    default: return fl_rgb_color(static_cast<std::uint8_t>(value * 255), static_cast<std::uint8_t>(p * 255), static_cast<std::uint8_t>(q * 255));
  }
}

namespace Wiggly_Example {
  class Wiggly : public Fl_Widget {
  public:
    Wiggly(int x, int y, int width, int height) : Fl_Widget(x, y, width, height) {
      Fl::add_timeout(0.06, timer_callback, this);
    }
    
    void set_text(const std::string& text) {
      this->text = text;
      redraw();
    }
    
  private:
    auto draw() -> void override {
      static constexpr auto sins = std::array {0, 38, 71, 92, 100, 92, 71, 38, 0, -38, -71, -92, -100, -92, -71, -38};
      
      fl_color(color());
      fl_rectf(x(), y(), w(), h());
      
      fl_font(fl_font(), 24);
      
      auto text_wdth = 0, text_heigt = 0;
      fl_measure(text.c_str(), text_wdth, text_heigt, false);
      
      auto pos_x = x() + (w() - text_wdth) / 2;
      auto pos_y = y() + (h() + text_heigt / 2) / 2;
      
      for (auto index = 0z; const auto& c : text) {
        auto sins_index = (step + index++) % sins.size();
        fl_color(fl_hsv_color(360.0 / sins.size() * sins_index, 1.0, 0.75));
        auto char_width = 0, char_height = 0;
        fl_measure(std::array {c, '\0'}.data(), char_width, char_height, false);
        fl_draw(std::array {c, '\0'}.data(), pos_x, pos_y - (sins[sins_index] * char_height) / 400);
        pos_x += char_width;
      }
    }
    
    static auto timer_callback(void* widget) -> void {
      static_cast<Wiggly*>(widget)->step++;
      static_cast<Wiggly*>(widget)->redraw();
      Fl::repeat_timeout(0.06, timer_callback, widget);
    }
    
    std::string text;
    int step = 0;
  };
  
  class MainWindow : public Fl_Window {
  public:
    MainWindow() : Fl_Window(330, 130, "Wiggly") {
      input.when(FL_WHEN_CHANGED);
      input.callback([](Fl_Widget* sender, void* window) {
        static_cast<MainWindow*>(window)->wiggly.set_text(static_cast<Fl_Input*>(sender)->value());
      }, this);
      input.value("Habemus papam");
      input.do_callback(&input, this, FL_REASON_CHANGED);
      end();
      resizable(this);
    }
    
  private:
    Wiggly wiggly {20, 20, 290, 60};
    Fl_Input input {20, 90, 290, 25};
  };
}

auto main() -> int {
  auto win = Wiggly_Example::MainWindow {};
  win.show();
  return Fl::run();
}

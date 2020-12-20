#include <memory>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Hor_Value_Slider.H>
#include <FL/Fl_Window.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 420, 480, "Symbols example") {
      resizable(this);
      for (auto index = 0; index < symbols.size(); ++index) {
        auto symbol = make_shared<Fl_Box>(10 + (70*(index%6)), 10 + (70*(index/6)), 50, 50);
        symbol->align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
        symbol->box(FL_BORDER_BOX);
        symbol->labelcolor(fl_color_average(FL_FOREGROUND_COLOR, FL_WHITE, 0.5));
        boxes.push_back(symbol);
        
        auto label = make_shared<Fl_Box>(0 + (70*(index%6)), 60 + (70*(index/6)), 70, 14);
        label->align(FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
        label->box(FL_FLAT_BOX);
        label->labelsize(11);
        boxes.push_back(label);
      }
      
      orienttation_slider.box(FL_FLAT_BOX);
      orienttation_slider.type(FL_HOR_NICE_SLIDER);
      orienttation_slider.range(0, 9);
      orienttation_slider.step(1);
      orienttation_slider.callback(on_slider_value_changed, this);
      
      size_slider.box(FL_FLAT_BOX);
      size_slider.type(FL_HOR_NICE_SLIDER);
      size_slider.range(-9, 9);
      size_slider.step(1);
      size_slider.callback(on_slider_value_changed, this);
      
      size_slider.do_callback();
    }

  private:
    static void on_slider_value_changed(Fl_Widget* sender, void* data) {
      auto window = reinterpret_cast<Main_Window*>(data);
      for (auto index = 0; index < window->boxes.size(); index += 2) {
        window->boxes[index]->copy_label(window->make_label(window->symbols[index / 2]).c_str());
        window->boxes[index + 1]->copy_label(("@" + window->make_label(window->symbols[index / 2])).c_str());
      }
    }
    
    string make_label(const string& base_label) {
      string label = string(1, base_label[0]);
      if (size_slider.value() > 0) label += "+" + to_string(static_cast<int>(size_slider.value()));
      if (size_slider.value() < 0) label += to_string(static_cast<int>(size_slider.value()));
      if (orienttation_slider.value() > 0) label += to_string(static_cast<int>(orienttation_slider.value()));
      label += &base_label[1];
      return label;
    }
    
    vector<string> symbols {"@->", "@>", "@>>", "@>|", "@>[]", "@|>", "@<-", "@<", "@<<", "@|<", "@[]<", "@<|", "@<->", "@-->", "@+", "@->|", "@||", "@arrow", "@returnarrow", "@square", "@circle", "@line", "@menu", "@UpArrow", "@DnArrow", "@search", "@FLTK", "@filenew", "@fileopen", "@filesave", "@filesaveas", "@fileprint", "@refresh", "@reload", "@undo", "@redo"};
    vector<shared_ptr<Fl_Box>> boxes;
    Fl_Hor_Value_Slider orienttation_slider {10, 430, 190, 25, "Orientation"};
    Fl_Hor_Value_Slider size_slider {220, 430, 190, 25, "Size"};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}

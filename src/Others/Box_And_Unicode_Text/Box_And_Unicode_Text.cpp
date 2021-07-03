#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

using namespace std;

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 420, 350, "Box and unicode text example") {
      color(FL_DARK_CYAN);
      labelcolor(FL_BLACK);
      for (auto index = 0U; index < languages.size(); ++index) {
        items[index].first = make_shared<Fl_Box>(10, 10 + index * 30, 150, 25, languages[index].first.c_str());
        items[index].first->align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
        items[index].first->labelcolor(FL_BLACK);
        items[index].second = make_shared<Fl_Box>(160, 10 + index * 30, 240, 25, languages[index].second.c_str());
        items[index].second->align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
        items[index].second->labelcolor(FL_BLACK);
      }
    }
    
  private:
    vector<pair<string, string>> languages {
      {"Arabic", "\u0627\u0644\u0643\u0644\u0645\u0629 \u0627\u0644\u0639\u0631\u0628\u064A\u0629"},
      {"Trad. Chinese", "\u4E2D\u570B\u7684\u6F22\u5B57"},
      {"Simpl. Chinese:", "\u6C49\u8BED"},
      {"French", "Langue fran\u00E7aise"},
      {"Greek", "\u0395\u03BB\u03BB\u03B7\u03BD\u03B9\u03BA\u03AE \u03B3\u03BB\u03CE\u03C3\u03C3\u03B1"},
      {"Hebrew", "\u05DB\u05EA\u05D1 \u05E2\u05D1\u05E8\u05D9\u05EA"},
      {"Hindi", "\u0939\u093f\u0928\u094d\u0926\u0940 \u092d\u093e\u0937\u093e"},
      {"Icelandic", "\u00CDslenska"},
      {"Japanese", "\u65E5\u672C\u8A9E\u306E\u3072\u3089\u304C\u306A, \u6F22\u5B57\u3068\u30AB\u30BF\u30AB\u30CA"},
      {"Korean", "\uB300\uD55C\uBBFC\uAD6D\uC758 \uD55C\uAE00"},
      {"Russian", "\u0420\u0443\u0441\u0441\u043A\u0438\u0439 \u044F\u0437\u044B\u043A"}
    };
    vector<pair<shared_ptr<Fl_Box>, shared_ptr<Fl_Box>>> items {languages.size()};
  };
}

int main(int argc, char* argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  Fl::run();
}

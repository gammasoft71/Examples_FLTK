#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window {200, 100, 390, 360, "Box example"} {
      resizable(group);

      box1.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);

      auto w = 0, h = 0;
      fl_measure(box2.label(), w, h, 1);
      box2.size(w, h);
      box2.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);

      box3.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      
      box4.align(FL_ALIGN_CENTER | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    }
    
  private:
    Fl_Group group {0, 0, 390, 360};
    Fl_Box box1 {10, 50, 100, 25, "Lorem ipsum"};
    Fl_Box box2 {10, 100, 100, 25, "Lorem ipsum dolor sit amet, consectetur adipiscing elit."};
    Fl_Box box3 {10, 150, 100, 25, "Lorem ipsum dolor sit amet, consectetur adipiscing elit."};
    Fl_Box box4 {10, 200, 350, 150, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus.Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim.Pellentesque congue. Ut in risus volutpat libero pharetra tempor.Cras vestibulum bibendum augue. Praesent egestas leo in pede.Praesent blandit odio eu enim.Pellentesque sed dui ut augue blandit sodales.Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum.Maecenas adipiscing ante non diam sodales hendrerit.\n\nUt velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar.Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula.Pellentesque rhoncus nunc et augue.Integer id felis.Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas.Lorem ipsum dolor sit amet, consectetuer adipiscing elit.Morbi vel erat non mauris convallis vehicula.Nulla et sapien.Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat.Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.\n\nAliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus.Fusce vulputate sem at sapien.Vivamus leo. Aliquam euismod libero eu enim.Nulla nec felis sed leo placerat imperdiet.Aenean suscipit nulla in justo.Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus.Curabitur eu amet.\n"};
    Fl_End group_end;
  };
}

auto main(int argc, char *argv[]) -> int {
  auto window = Examples::Main_Window {};
  window.show(argc, argv);
  return Fl::run();
}


# Fltk Examples

Shows how to use Fltk controls only by programming code (c++17).

## Hello World

["Hello World"](src/HelloWorld) The classic first application HelloWorld with Fl_Box.

## Application and messages

[Application](src/Application) Shows how to create a simple Fltk application with Gtk::Application.

## Common Controls

[Button](src/Button) Shows how to create a Fltk Button and Event Click with Fl_Button.

[CheckBox](src/CheckBox) Shows how to create a Fltk CheckBox with Fl_Check_Button.

[Label](src/Label) Shows how to create a Fltk Label with Fl_Box.

[ProgressBar](src/ProgressBar) Shows how to create a Fltk ProgressBar with Fl_Progress.

[RadioButton](src/RadioButton) Shows how to create a Fltk RadioButton with Fl_Round_Button.

[TextBox](src/TextBox) Shows how to create a Fltk TextBox with Fl_Input.

[TrackBar](src/TrackBar) Shows how to create a Fltk TrackBar with Fl_Slider.

## Containers

[Form](src/Form) Shows how to create a simple Fltk Form with Fl_Window.

[GroupBox](src/GroupBox) Shows how to create a simple Fltk GroupBox with Fl_Group.

[Panel](src/Panel) Shows how to create a simple Fltk Panel with Fl_Frame.

[TabControl](src/TabControl) Shows how to create a simple Fltk TabControl with TabPages with NSTabView and Gtk::Notebook.

## Menus and toolbars

[MainMenu](src/MainMenu) Shows how to create a Fltk MainMenu with Gtk::MenuBar, Gtk::Menu and Gtk::MenuItem.

## Components

[Timer](src/Timer) Shows how to create a simple Fltk Timer with TimerGtk.

## Dialogs

[ColorDialog](src/ColorDialog) Shows how to create a ColorDialog with Gtk::ColorChooserDialog.

[FolderBrowserDialog](src/FolderBrowserDialog) Shows how to create a FolderBrowserDialog with Gtk::FileChooserDialog.

[FontDialog](src/FontDialog) Shows how to create a FontDialog with Gtk::FontChooserDialog.

[OpenFileDialog](src/OpenFileDialog) Shows how to create an OpenFileDialog with Gtk::FileChooserDialog.

[MessageBox](src/MessageBox) Shows how to create a MessageBox with Gtk::MessageDialog.

[SaveFileDialog](src/SaveFileDialog) Shows how to create an SaveFileDialog with Gtk::FileChooserDialog.

## Download

``` shell
git clone https://github.com/gammasoft71/FltkExamples FltkExamples
```

## Generate and build

To build this project, open "Terminal" and type following lines:

### macOS :

``` cmake
mkdir build
cd build
cmake .. -G "Xcode"
open ./CocoaExamples.xcodeproj
```


### Linux :

``` cmake
mkdir build
cd build
cmake .. 
cmake --build . --config Debug
```

## Remarks

This project run with [Fltk 3](https://www.Fltk.org) and [CMake](https://cmake.org).

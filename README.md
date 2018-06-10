
# Gtkmm Examples

Shows how to use Gtkmm controls (c++14).

## Hello World

["Hello World"](src/HelloWorld) The classic first application HelloWorld with Gtk::Label.

## Application and messages

[Application](src/Application) Shows how to create a simple Gtkmm application with Gtk::Application.

## Common Controls

[Button](src/Button) Shows how to create a Gtkmm Button and Event Click with Gtl::Button.

[CheckBox](src/CheckBox) Shows how to create a Gtkmm CheckBox with Gtk::CheckButton.

[Label](src/Label) Shows how to create a Gtkmm Label with Gtk::Label.

[ProgressBar](src/ProgressBar) Shows how to create a Gtkmm ProgressBar with Gtk::ProgressBar.

[RadioButton](src/RadioButton) Shows how to create a Gtkmm RadioButton with Gtk::RadioButton.

[TextBox](src/TextBox) Shows how to create a Gtkmm TextBox with Gtk::Entry.

[TrackBar](src/TrackBar) Shows how to create a Gtkmm TrackBar with Gtk::Scale.

## Containers

[Form](src/Form) Shows how to create a simple Gtkmm Form with Gtk::Window.

[GroupBox](src/GroupBox) Shows how to create a simple Gtkmm GroupBox with Gtk::Frame.

[Panel](src/Panel) Shows how to create a simple Gtkmm Panel with Gtk::Frame.

[TabControl](src/TabControl) Shows how to create a simple Gtkmm TabControl with TabPages with NSTabView and Gtk::Notebook.

## Menus and toolbars

[MainMenu](src/MainMenu) Shows how to create a Gtkmm MainMenu with Gtk::MenuBar, Gtk::Menu and Gtk::MenuItem.

## Components

[Timer](src/Timer) Shows how to create a simple Gtkmm Timer with TimerGtk.

## Dialogs

[ColorDialog](src/ColorDialog) Shows how to create a ColorDialog with Gtk::ColorChooserDialog.

[FolderBrowserDialog](src/FolderBrowserDialog) Shows how to create a FolderBrowserDialog with Gtk::FileChooserDialog.

[FontDialog](src/FontDialog) Shows how to create a FontDialog with Gtk::FontChooserDialog.

[OpenFileDialog](src/OpenFileDialog) Shows how to create an OpenFileDialog with Gtk::FileChooserDialog.

[MessageBox](src/MessageBox) Shows how to create a MessageBox with Gtk::MessageDialog.

[SaveFileDialog](src/SaveFileDialog) Shows how to create an SaveFileDialog with Gtk::FileChooserDialog.

## Download

``` shell
git clone https://github.com/gammasoft71/GtkmmExamples GtkmmExamples
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

This project run with [Gtkmm 3](https://www.gtkmm.org) and [CMake](https://cmake.org).

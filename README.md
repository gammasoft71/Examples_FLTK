
# Fltk Examples

Shows how to use Fltk controls only by programming code (c++17).

## Hello World

* [Hello_World_Box](src/Hello_Worlds/Hello_World_Box) The classic first application "Hello, World!" with Fl_Box.
* [Hello_World_Drawing](src/Hello_Worlds/Hello_World_Drawing) The classic first application "Hello, World!" with GDI+ drawing objects.
* [Hello_World_Emoticons](src/Hello_Worlds/Hello_World_Emoticons) The classic first application "Hello, World!" with Fl_Box and emoticons.
* [Hello_World_Fltk](src/Hello_Worlds/Hello_World_Fltk) The classic first application "Hello, World!" by FLTK.
* [Hello_World_Message](src/Hello_Worlds/Hello_World_Message) The classic first application "Hello, World!" with Fl_Message.
* [Hello_World_Message2](src/Hello_Worlds/Hello_World_Message2) The classic first application "Hello, World!" with Fl_Message.
* [Hello_World_Say](src/Hello_Worlds/Hello_World_Say) The classic first application "Hello, World!" with say.

## Application and messages

* [Application](src/Applications/Application) Shows how to create a simple Fltk application.
* [Application_And_Exception](src/Applications/Application_And_Exception) Shows how to create a simple Fltk application and how to manage exception.
* [Application_Dark_Mode](src/Applications/Application_Dark_Mode) Shows how to create a simple Fltk application with dark mode.

## Common Controls

* [Button](src/Button) Shows how to create a Fltk Button and Event Click with Fl_Button.
* [CheckBox](src/CheckBox) Shows how to create a Fltk CheckBox with Fl_Check_Button.
* [CheckButton](src/CheckButton) Shows how to create a Fltk CheckButton with Fl_Check_Button.
* [CheckedListBox](src/CheckedListBox) Shows how to create a Fltk CheckedListBox with Fl_Checked_list_box.
* [ComboBox](src/ComboBox) Shows how to create a Fltk ComboBox with Fl_Input_Choice.
* [Label](src/Label) Shows how to create a Fltk Label with Fl_Box.
* [PictureBox](src/PictureBox) Shows how to create a Fltk PictureBox with Fl_Box.
* [ProgressBar](src/ProgressBar) Shows how to create a Fltk ProgressBar with Fl_Progress.
* [RadioButton](src/RadioButton) Shows how to create a Fltk RadioButton with Fl_Round_Button.
* [TextBox](src/TextBox) Shows how to create a Fltk TextBox with Fl_Input.
* [ToggleButton](src/ToggleButton) Shows how to create a Fltk ToggleButton with Fl_Toggle_Button.
* [TrackBar](src/TrackBar) Shows how to create a Fltk TrackBar with Fl_Slider.

## Containers

* [Form](src/Form) Shows how to create a simple Fltk Form with Fl_Window.
* [GroupBox](src/GroupBox) Shows how to create a simple Fltk GroupBox with Fl_Group.
* [Panel](src/Panel) Shows how to create a simple Fltk Panel with Fl_Frame.
* [TabControl](src/TabControl) Shows how to create a simple Fltk TabControl with TabPages with NSTabView and Gtk::Notebook.

## Menus and toolbars

* [MainMenu](src/MainMenu) Shows how to create a Fltk MainMenu with Gtk::MenuBar, Gtk::Menu and Gtk::MenuItem.

## Components

* [Timer](src/Timer) Shows how to create a simple Fltk Timer with TimerGtk.

## Dialogs

* [ColorDialog](src/ColorDialog) Shows how to create a ColorDialog with Gtk::ColorChooserDialog.
* [FolderBrowserDialog](src/FolderBrowserDialog) Shows how to create a FolderBrowserDialog with Gtk::FileChooserDialog.
* [FontDialog](src/FontDialog) Shows how to create a FontDialog with Gtk::FontChooserDialog.
* [OpenFileDialog](src/OpenFileDialog) Shows how to create an OpenFileDialog with Gtk::FileChooserDialog.
* [MessageBox](src/MessageBox) Shows how to create a MessageBox with Gtk::MessageDialog.
* [SaveFileDialog](src/SaveFileDialog) Shows how to create an SaveFileDialog with Gtk::FileChooserDialog.

## Download

``` shell
git clone https://github.com/gammasoft71/FltkExamples FltkExamples
```

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` cmake
mkdir build
cd build
cmake .. 
start Fltk_Examples.sln
```

### macOS :

``` cmake
mkdir build
cd build
cmake .. -G "Xcode"
open ./Fltk_Examples.xcodeproj
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

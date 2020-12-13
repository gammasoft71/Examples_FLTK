
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

* [Box](src/Common_Controls/Box) Shows how to show a text with Fl_Box.
* [Box_Picture](src/Common_Controls/Box_Picture) Shows how to show an image with Fl_Box.
* [Browser](src/Common_Controls/Browser) Shows how to create a text list with Fl_Browser.
* [Button](src/Common_Controls/Button) Shows how to create a button with Fl_Button.
* [Check_Browser](src/Common_Controls/Check_Browser) Shows how to create a check button list with Fl_Check_Browser.
* [Check_Button](src/Common_Controls/Check_Button) Shows how to create a check button with Fl_Check_Button.
* [Input](src/Common_Controls/Input) Shows how to create an input text with Fl_Input.
* [Nice_Slider](src/Common_Controls/Nice_Slider) Shows how to create a slider with Fl_Nice_Slider.
* [Progress](src/Common_Controls/Progress) Shows how to create a progress with Fl_Progress.
* [Radio_Round_Button](src/Common_Controls/Radio_Round_Button) Shows how to create a radio round button with Fl_Radio_Round_Button.
* [Spinner](src/Common_Controls/Spinner) Shows how to create a spinner with Fl_Spinner.
* [Toggle_Button](src/Common_Controls/Toggle_Button) Shows how to create a toggle button with Fl_Toggle_Button.

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

## Others

* [ComboBox](src/Others/ComboBox) Shows how to create a Fltk ComboBox with Fl_Input_Choice.

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

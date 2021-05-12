# Window_Click

Shows how to use mouse click event with override handle method and use Fl::event_button, Fl::event_x() and Fl::event_y() methods on FL_RELEASE event.

## Source

[Window_Click.cpp](Window_Click.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Window_Click.sln
```

Select Window_Click project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Window_Click.xcodeproj
```

Select Window_Click project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Window_Click
```

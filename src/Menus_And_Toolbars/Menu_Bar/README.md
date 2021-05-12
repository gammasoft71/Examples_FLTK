# Menu_Bar

Shows how to create a menu bar with Fl_Menu_Bar widget.

## Source

[Button.cpp](Button.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Button.sln
```

Select Button project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Button.xcodeproj
```

Select Button project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Button
```

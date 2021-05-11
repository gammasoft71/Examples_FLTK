# Input

Shows how to create a text input with Fl_Input widget.

## Source

[Input.cpp](Input.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Input.sln
```

Select Input project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Input.xcodeproj
```

Select Input project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Input
```

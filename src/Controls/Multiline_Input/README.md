# Multiline_Input

Shows how to create a multiline text input with [Fl_Multiline_Input](https://www.fltk.org/doc-1.3/classFl__Multiline__Input.html) widget.

## Source

[Multiline_Input.cpp](Multiline_Input.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Multiline_Input.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Multiline_Input.sln
```

Select Multiline_Input project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Multiline_Input.xcodeproj
```

Select Multiline_Input project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Multiline_Input
```

# Light_Button

Shows how to create a radio light button with [Fl_Light_Button](https://www.fltk.org/doc-1.3/classFl__Light__Button.html) widget.

## Source

[Light_Button.cpp](Light_Button.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Light_Button.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Light_Button.sln
```

Select Light_Button project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Light_Button.xcodeproj
```

Select Light_Button project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Light_Button
```

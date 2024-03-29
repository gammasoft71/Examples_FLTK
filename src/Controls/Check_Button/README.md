# Check_Button

Shows how to create a check button with [Fl_Check_Button](https://www.fltk.org/doc-1.3/classFl__Check__Button.html) widget.

## Source

[Check_Button.cpp](Check_Button.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Check_Button.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Check_Button.sln
```

Select Check_Button project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Check_Button.xcodeproj
```

Select Check_Button project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Check_Button
```

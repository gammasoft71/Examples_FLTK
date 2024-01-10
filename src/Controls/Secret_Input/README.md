# Secret_Input

Shows how to create a secret text input with [Fl_Secret_Input](https://www.fltk.org/doc-1.3/classFl__Secret__Input.html) widget.

## Source

[Secret_Input.cpp](Secret_Input.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Secret_Input.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Secret_Input.sln
```

Select Secret_Input project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Secret_Input.xcodeproj
```

Select Secret_Input project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Secret_Input
```

# Clock

Shows how to create a clock with [Fl_Clock](https://www.fltk.org/doc-1.3/classFl__Clock.html) widget.

## Source

[Clock.cpp](Clock.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Clock.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Clock.sln
```

Select Clock project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Clock.xcodeproj
```

Select Clock project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Clock
```

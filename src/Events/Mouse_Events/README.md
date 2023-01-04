# Mouse_Events

Demonstrates the use of mouse events.

## Source

[Mouse_Events.cpp](Mouse_Events.cpp)

[Fl_Trace_Window.h](Fl_Trace_Window.h)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Mouse_Events.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Mouse_Events.sln
```

Select Mouse_Events project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Mouse_Events.xcodeproj
```

Select Mouse_Events project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Mouse_Events
```

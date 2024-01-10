# Output

Shows how to create a text output with [Fl_Output](https://www.fltk.org/doc-1.3/classFl__Output.html) widget.

## Source

[Output.cpp](Output.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Output.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Output.sln
```

Select Output project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Output.xcodeproj
```

Select Output project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Output
```

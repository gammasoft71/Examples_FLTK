# Float_Input

Shows how to create a float input with [Fl_Float_Input](https://www.fltk.org/doc-1.3/classFl__Float__Input.html) widget.

## Source

[Float_Input.cpp](Float_Input.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Float_Input.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Float_Input.sln
```

Select Float_Input project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Float_Input.xcodeproj
```

Select Float_Input project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Float_Input
```

# Box_Picture2

Shows how to use an image with [Fl_Box](https://www.fltk.org/doc-1.3/classFl__Box.html) widget.

## Source

[Box_Picture2.cpp](Box_Picture2.cpp)

[CMakeLists.txt](CMakeLists.txt)

[Resources/Logo.png](Resources/Logo.png)

## Output

![output](../../../docs/Pictures/Examples/Box_Picture2.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Box_Picture2.sln
```

Select Box_Picture2 project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Box_Picture2.xcodeproj
```

Select Box_Picture2 project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Box_Picture2
```

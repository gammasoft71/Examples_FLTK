# Check_Browser

Shows how to create a check button list with [Fl_Check_Browser](https://www.fltk.org/doc-1.3/classFl__Check__Browser.html) widget.

## Source

[Check_Browser.cpp](Check_Browser.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Check_Browser.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Check_Browser.sln
```

Select Check_Browser project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Check_Browser.xcodeproj
```

Select Check_Browser project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Check_Browser
```

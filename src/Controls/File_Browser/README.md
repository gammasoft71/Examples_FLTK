# File_Browser

Shows how to create a file browser with [Fl_File_Browser](https://www.fltk.org/doc-1.3/classFl__File__Browser.html) widget.

## Source

[File_Browser.cpp](File_Browser.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/File_Browser.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start File_Browser.sln
```

Select File_Browser project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./File_Browser.xcodeproj
```

Select File_Browser project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./File_Browser
```

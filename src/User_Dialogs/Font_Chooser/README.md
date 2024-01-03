# Font_Chooser

Shows how to use a Font chooser dialog with own [fl_font_chooser](fl_font_chooser.h) method.

## Source

[Font_Chooser.cpp](Font_Chooser.cpp)

[fl_font_chooser.h](fl_font_chooser.h)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Font_Chooser.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Font_Chooser.sln
```

Select Font_Chooser project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Font_Chooser.xcodeproj
```

Select Font_Chooser project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Font_Chooser
```

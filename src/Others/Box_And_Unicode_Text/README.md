# Box_And_Unicode_Text

Demonstrates the use of Fl_Box with unicode text.

## Source

[Box_And_Unicode_Text.cpp](Box_And_Unicode_Text.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Box_And_Unicode_Text.sln
```

Select Box_And_Unicode_Text project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Box_And_Unicode_Text.xcodeproj
```

Select Box_And_Unicode_Text project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Box_And_Unicode_Text
```

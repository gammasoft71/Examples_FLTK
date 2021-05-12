# Disable_Symbols

Shows how to disable / enable label symbols.

## Source

[Disable_Symbols.cpp](Disable_Symbols.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Disable_Symbols.sln
```

Select Disable_Symbols project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Disable_Symbols.xcodeproj
```

Select Disable_Symbols project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Disable_Symbols
```

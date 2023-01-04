# Wizard

Shows how to create a wizard and pages with Fl_Wizard and Fl_Group.

## Source

[Wizard.cpp](Wizard.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/Examples/Wizard.png)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Wizard.sln
```

Select Wizard project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Wizard.xcodeproj
```

Select Wizard project and type Cmd+R to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Wizard
```

cmake_minimum_required(VERSION 3.0)

# Solution
project(Combo_Box)
find_package(FLTK REQUIRED)

# Options
if (MSVC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif ()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Application
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE Combo_Box.cpp Fl_Combo_Box.h Fl_Combo_Box_Style.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "User_Controls")

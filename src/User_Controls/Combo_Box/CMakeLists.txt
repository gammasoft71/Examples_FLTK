cmake_minimum_required(VERSION 3.0)
project(Combo_Box)

find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
link_libraries(${FLTK_LIBRARIES})

if (MSVC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif ()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE Combo_Box.cpp Fl_Combo_Box.h Fl_Combo_Box_Style.h)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "User_Controls")

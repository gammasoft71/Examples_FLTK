cmake_minimum_required(VERSION 3.5)

project(FontDialog VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  set(GUI_OPTION WIN32)
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
elseif(UNIX)
  set(GUI_OPTION )
endif ()

find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})

add_executable(FontDialog ${GUI_OPTION} FontDialog.cpp Fl_font_chooser.h)
target_link_libraries(FontDialog ${FLTK_LIBRARIES})

cmake_minimum_required(VERSION 3.5)

project(TrackBar VERSION 1.0.0)

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

add_executable(TrackBar ${GUI_OPTION} TrackBar.cpp)
target_link_libraries(TrackBar ${FLTK_LIBRARIES})

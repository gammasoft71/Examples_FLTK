cmake_minimum_required(VERSION 3.0)
project(Multiline_Output)

find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
link_libraries(${FLTK_LIBRARIES})

if (MSVC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif ()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE Multiline_Output.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Common_Controls")

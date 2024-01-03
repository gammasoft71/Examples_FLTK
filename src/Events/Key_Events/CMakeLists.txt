cmake_minimum_required(VERSION 3.20)

# Solution
project(Key_Events)
find_package(FLTK REQUIRED)

# Options
if (MSVC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif ()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Application
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE Key_Events.cpp Fl_Trace_Window.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})
if (APPLE)
  # Workaround: fltk.framework does not exist, so we have to replace it by libfltk.dylib
  string(REPLACE "libfltk_images" "libfltk" FLTK_LIBRARY_NAME "${FLTK_IMAGES_LIBRARY_RELEASE}")
  string(REPLACE "/usr/local/fltk.framework" "${FLTK_LIBRARY_NAME}" FLTK_LIBRARIES "${FLTK_LIBRARIES}")
endif()
target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Events")

cmake_minimum_required(VERSION 3.0)

# Solution
project(Box_Picture2)
find_package(FLTK REQUIRED)

# Options
if (MSVC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
elseif (APPLE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa")
endif ()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Resources
configure_file(Resources/Logo.png ${CMAKE_CURRENT_BINARY_DIR}/Resources/Logo.png COPYONLY)
configure_file(Resources/Logo.png ${CMAKE_CURRENT_BINARY_DIR}/Debug/Resources/Logo.png COPYONLY)
configure_file(Resources/Logo.png ${CMAKE_CURRENT_BINARY_DIR}/Release/Resources/Logo.png COPYONLY)
set_source_files_properties(Resources/Logo.png PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

# Application
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE Box_Picture2.cpp Resources/Logo.png)
target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})
if (APPLE)
  # Workaround: fltk.framework does not exist, so we have to replace it by libfltk.dylib
  string(REPLACE "libfltk_images" "libfltk" FLTK_LIBRARY_NAME "${FLTK_IMAGES_LIBRARY_RELEASE}")
  string(REPLACE "/usr/local/fltk.framework" "${FLTK_LIBRARY_NAME}" FLTK_LIBRARIES "${FLTK_LIBRARIES}")
endif()
target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Controls")

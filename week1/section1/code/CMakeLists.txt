cmake_minimum_required(VERSION 3.17.0)

PROJECT(ImageBasics)

set(CMAKE_CXX_STANDARD 14)

SET(OpenCV_DIR /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/cmake/opencv4/)

message(STATUS \({OpenCV_DIR}) #Displays variable. Helpful for debug

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

MACRO(add_example name)
  ADD_EXECUTABLE(${name} ${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )
ENDMACRO()

add_example(color_images)
add_example(image_basics)
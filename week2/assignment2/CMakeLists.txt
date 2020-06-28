cmake_minimum_required(VERSION 2.8.12)

PROJECT(Face_Annotation_Tool_Assignment)

SET(CMAKE_CXX_STANDARD 11)

SET(OpenCV_DIR /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/cmake/opencv4/)

###################   ***DO NOT EDIT***  #####################

#############  Common Instructions for all Users  ############
if(MSVC)
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
endif()

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

MACRO(add_example name)
  ADD_EXECUTABLE(${name} ${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )
ENDMACRO()

add_example(submission)

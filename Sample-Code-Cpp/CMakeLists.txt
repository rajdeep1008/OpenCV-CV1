cmake_minimum_required(VERSION 2.8.12)

PROJECT(sampleCode)

######################## EDIT IF REQUIRED ####################
###Uncomment the line below and specify the path to OpenCV directory i.e. the path to the OpenCVConfig.cmake file. Check the examples given below.

SET(OpenCV_DIR /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/cmake/opencv4/)

################### OpenCV_DIR Examples  #####################

### MACOS : /usr/local/Cellar/opencv/4.1.0/share/OpenCV/

### UBUNTU : /usr/local/share/OpenCV/

### WINDOWS : C:\Users\yourname\Documents\opencv-4.1.0\build\install

##############################################################

###################   ***DO NOT EDIT***  #####################

#############  Common Instructions for all Users  ############
find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

MACRO(add_example name)
  ADD_EXECUTABLE(${name} ${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )
ENDMACRO()

add_example(sampleCode)

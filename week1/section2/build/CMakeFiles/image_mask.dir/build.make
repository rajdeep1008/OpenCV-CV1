# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/build

# Include any dependencies generated for this target.
include CMakeFiles/image_mask.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/image_mask.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image_mask.dir/flags.make

CMakeFiles/image_mask.dir/image_mask.cpp.o: CMakeFiles/image_mask.dir/flags.make
CMakeFiles/image_mask.dir/image_mask.cpp.o: /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/code/image_mask.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image_mask.dir/image_mask.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image_mask.dir/image_mask.cpp.o -c /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/code/image_mask.cpp

CMakeFiles/image_mask.dir/image_mask.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_mask.dir/image_mask.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/code/image_mask.cpp > CMakeFiles/image_mask.dir/image_mask.cpp.i

CMakeFiles/image_mask.dir/image_mask.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_mask.dir/image_mask.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/code/image_mask.cpp -o CMakeFiles/image_mask.dir/image_mask.cpp.s

# Object files for target image_mask
image_mask_OBJECTS = \
"CMakeFiles/image_mask.dir/image_mask.cpp.o"

# External object files for target image_mask
image_mask_EXTERNAL_OBJECTS =

image_mask: CMakeFiles/image_mask.dir/image_mask.cpp.o
image_mask: CMakeFiles/image_mask.dir/build.make
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_gapi.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_stitching.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_aruco.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_bgsegm.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_bioinspired.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_ccalib.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_cvv.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_dnn_objdetect.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_dpm.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_face.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_freetype.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_fuzzy.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_hdf.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_hfs.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_img_hash.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_line_descriptor.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_quality.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_reg.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_rgbd.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_saliency.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_stereo.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_structured_light.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_superres.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_surface_matching.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_tracking.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_videostab.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_xfeatures2d.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_xobjdetect.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_xphoto.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_shape.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_datasets.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_plot.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_text.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_dnn.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_ml.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_phase_unwrapping.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_optflow.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_ximgproc.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_video.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_objdetect.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_calib3d.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_features2d.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_flann.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_highgui.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_videoio.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_imgcodecs.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_photo.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_imgproc.4.1.0.dylib
image_mask: /Users/rajdeep1008/Desktop/opencv-cv1/installation/OpenCV-4.1.0/lib/libopencv_core.4.1.0.dylib
image_mask: CMakeFiles/image_mask.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable image_mask"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image_mask.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image_mask.dir/build: image_mask

.PHONY : CMakeFiles/image_mask.dir/build

CMakeFiles/image_mask.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image_mask.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image_mask.dir/clean

CMakeFiles/image_mask.dir/depend:
	cd /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/code /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/code /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/build /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/build /Users/rajdeep1008/Desktop/opencv-cv1/week1/section2/build/CMakeFiles/image_mask.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/image_mask.dir/depend


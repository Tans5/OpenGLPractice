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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pengcheng.tan/CLionProjects/OpenGLPractice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pengcheng.tan/CLionProjects/OpenGLPractice/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenGLPractice.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGLPractice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGLPractice.dir/flags.make

CMakeFiles/OpenGLPractice.dir/main.cpp.o: CMakeFiles/OpenGLPractice.dir/flags.make
CMakeFiles/OpenGLPractice.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pengcheng.tan/CLionProjects/OpenGLPractice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGLPractice.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLPractice.dir/main.cpp.o -c /Users/pengcheng.tan/CLionProjects/OpenGLPractice/main.cpp

CMakeFiles/OpenGLPractice.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLPractice.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pengcheng.tan/CLionProjects/OpenGLPractice/main.cpp > CMakeFiles/OpenGLPractice.dir/main.cpp.i

CMakeFiles/OpenGLPractice.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLPractice.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pengcheng.tan/CLionProjects/OpenGLPractice/main.cpp -o CMakeFiles/OpenGLPractice.dir/main.cpp.s

CMakeFiles/OpenGLPractice.dir/src/glad.c.o: CMakeFiles/OpenGLPractice.dir/flags.make
CMakeFiles/OpenGLPractice.dir/src/glad.c.o: ../src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pengcheng.tan/CLionProjects/OpenGLPractice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/OpenGLPractice.dir/src/glad.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OpenGLPractice.dir/src/glad.c.o   -c /Users/pengcheng.tan/CLionProjects/OpenGLPractice/src/glad.c

CMakeFiles/OpenGLPractice.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGLPractice.dir/src/glad.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/pengcheng.tan/CLionProjects/OpenGLPractice/src/glad.c > CMakeFiles/OpenGLPractice.dir/src/glad.c.i

CMakeFiles/OpenGLPractice.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGLPractice.dir/src/glad.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/pengcheng.tan/CLionProjects/OpenGLPractice/src/glad.c -o CMakeFiles/OpenGLPractice.dir/src/glad.c.s

CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.o: CMakeFiles/OpenGLPractice.dir/flags.make
CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.o: ../src/triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pengcheng.tan/CLionProjects/OpenGLPractice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.o -c /Users/pengcheng.tan/CLionProjects/OpenGLPractice/src/triangle.cpp

CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pengcheng.tan/CLionProjects/OpenGLPractice/src/triangle.cpp > CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.i

CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pengcheng.tan/CLionProjects/OpenGLPractice/src/triangle.cpp -o CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.s

# Object files for target OpenGLPractice
OpenGLPractice_OBJECTS = \
"CMakeFiles/OpenGLPractice.dir/main.cpp.o" \
"CMakeFiles/OpenGLPractice.dir/src/glad.c.o" \
"CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.o"

# External object files for target OpenGLPractice
OpenGLPractice_EXTERNAL_OBJECTS =

OpenGLPractice: CMakeFiles/OpenGLPractice.dir/main.cpp.o
OpenGLPractice: CMakeFiles/OpenGLPractice.dir/src/glad.c.o
OpenGLPractice: CMakeFiles/OpenGLPractice.dir/src/triangle.cpp.o
OpenGLPractice: CMakeFiles/OpenGLPractice.dir/build.make
OpenGLPractice: /Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
OpenGLPractice: ../libs/lib-arm64/libglfw.3.dylib
OpenGLPractice: ../libs/lib-arm64/libglfw3.a
OpenGLPractice: CMakeFiles/OpenGLPractice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pengcheng.tan/CLionProjects/OpenGLPractice/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable OpenGLPractice"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGLPractice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGLPractice.dir/build: OpenGLPractice

.PHONY : CMakeFiles/OpenGLPractice.dir/build

CMakeFiles/OpenGLPractice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGLPractice.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGLPractice.dir/clean

CMakeFiles/OpenGLPractice.dir/depend:
	cd /Users/pengcheng.tan/CLionProjects/OpenGLPractice/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pengcheng.tan/CLionProjects/OpenGLPractice /Users/pengcheng.tan/CLionProjects/OpenGLPractice /Users/pengcheng.tan/CLionProjects/OpenGLPractice/cmake-build-debug /Users/pengcheng.tan/CLionProjects/OpenGLPractice/cmake-build-debug /Users/pengcheng.tan/CLionProjects/OpenGLPractice/cmake-build-debug/CMakeFiles/OpenGLPractice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGLPractice.dir/depend


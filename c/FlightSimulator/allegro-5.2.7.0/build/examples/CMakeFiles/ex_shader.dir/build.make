# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/ex_shader.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/ex_shader.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/ex_shader.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/ex_shader.dir/flags.make

examples/CMakeFiles/ex_shader.dir/ex_shader.cpp.o: examples/CMakeFiles/ex_shader.dir/flags.make
examples/CMakeFiles/ex_shader.dir/ex_shader.cpp.o: ../examples/ex_shader.cpp
examples/CMakeFiles/ex_shader.dir/ex_shader.cpp.o: examples/CMakeFiles/ex_shader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/ex_shader.dir/ex_shader.cpp.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/CMakeFiles/ex_shader.dir/ex_shader.cpp.o -MF CMakeFiles/ex_shader.dir/ex_shader.cpp.o.d -o CMakeFiles/ex_shader.dir/ex_shader.cpp.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/examples/ex_shader.cpp

examples/CMakeFiles/ex_shader.dir/ex_shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex_shader.dir/ex_shader.cpp.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/examples/ex_shader.cpp > CMakeFiles/ex_shader.dir/ex_shader.cpp.i

examples/CMakeFiles/ex_shader.dir/ex_shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex_shader.dir/ex_shader.cpp.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/examples/ex_shader.cpp -o CMakeFiles/ex_shader.dir/ex_shader.cpp.s

# Object files for target ex_shader
ex_shader_OBJECTS = \
"CMakeFiles/ex_shader.dir/ex_shader.cpp.o"

# External object files for target ex_shader
ex_shader_EXTERNAL_OBJECTS =

examples/ex_shader: examples/CMakeFiles/ex_shader.dir/ex_shader.cpp.o
examples/ex_shader: examples/CMakeFiles/ex_shader.dir/build.make
examples/ex_shader: lib/liballegro_main.5.2.7.dylib
examples/ex_shader: lib/liballegro_image.5.2.7.dylib
examples/ex_shader: lib/liballegro_dialog.5.2.7.dylib
examples/ex_shader: /usr/local/Cellar/webp/1.2.1/lib/libwebp.dylib
examples/ex_shader: lib/liballegro.5.2.7.dylib
examples/ex_shader: examples/CMakeFiles/ex_shader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex_shader"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex_shader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/ex_shader.dir/build: examples/ex_shader
.PHONY : examples/CMakeFiles/ex_shader.dir/build

examples/CMakeFiles/ex_shader.dir/clean:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/ex_shader.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/ex_shader.dir/clean

examples/CMakeFiles/ex_shader.dir/depend:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0 /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/examples /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples/CMakeFiles/ex_shader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/ex_shader.dir/depend


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
include examples/CMakeFiles/ex_projection2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/ex_projection2.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/ex_projection2.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/ex_projection2.dir/flags.make

examples/CMakeFiles/ex_projection2.dir/ex_projection2.c.o: examples/CMakeFiles/ex_projection2.dir/flags.make
examples/CMakeFiles/ex_projection2.dir/ex_projection2.c.o: ../examples/ex_projection2.c
examples/CMakeFiles/ex_projection2.dir/ex_projection2.c.o: examples/CMakeFiles/ex_projection2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/ex_projection2.dir/ex_projection2.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/ex_projection2.dir/ex_projection2.c.o -MF CMakeFiles/ex_projection2.dir/ex_projection2.c.o.d -o CMakeFiles/ex_projection2.dir/ex_projection2.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/examples/ex_projection2.c

examples/CMakeFiles/ex_projection2.dir/ex_projection2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ex_projection2.dir/ex_projection2.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/examples/ex_projection2.c > CMakeFiles/ex_projection2.dir/ex_projection2.c.i

examples/CMakeFiles/ex_projection2.dir/ex_projection2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ex_projection2.dir/ex_projection2.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/examples/ex_projection2.c -o CMakeFiles/ex_projection2.dir/ex_projection2.c.s

# Object files for target ex_projection2
ex_projection2_OBJECTS = \
"CMakeFiles/ex_projection2.dir/ex_projection2.c.o"

# External object files for target ex_projection2
ex_projection2_EXTERNAL_OBJECTS =

examples/ex_projection2: examples/CMakeFiles/ex_projection2.dir/ex_projection2.c.o
examples/ex_projection2: examples/CMakeFiles/ex_projection2.dir/build.make
examples/ex_projection2: lib/liballegro_main.5.2.7.dylib
examples/ex_projection2: lib/liballegro_primitives.5.2.7.dylib
examples/ex_projection2: lib/liballegro_font.5.2.7.dylib
examples/ex_projection2: lib/liballegro_image.5.2.7.dylib
examples/ex_projection2: lib/liballegro_dialog.5.2.7.dylib
examples/ex_projection2: /usr/local/Cellar/webp/1.2.1/lib/libwebp.dylib
examples/ex_projection2: lib/liballegro.5.2.7.dylib
examples/ex_projection2: examples/CMakeFiles/ex_projection2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ex_projection2"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex_projection2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/ex_projection2.dir/build: examples/ex_projection2
.PHONY : examples/CMakeFiles/ex_projection2.dir/build

examples/CMakeFiles/ex_projection2.dir/clean:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/ex_projection2.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/ex_projection2.dir/clean

examples/CMakeFiles/ex_projection2.dir/depend:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0 /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/examples /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/examples/CMakeFiles/ex_projection2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/ex_projection2.dir/depend


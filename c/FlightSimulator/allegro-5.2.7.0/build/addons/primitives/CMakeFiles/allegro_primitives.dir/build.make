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
include addons/primitives/CMakeFiles/allegro_primitives.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.make

# Include the progress variables for this target.
include addons/primitives/CMakeFiles/allegro_primitives.dir/progress.make

# Include the compile flags for this target's objects.
include addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make

addons/primitives/CMakeFiles/allegro_primitives.dir/high_primitives.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/high_primitives.c.o: ../addons/primitives/high_primitives.c
addons/primitives/CMakeFiles/allegro_primitives.dir/high_primitives.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object addons/primitives/CMakeFiles/allegro_primitives.dir/high_primitives.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/high_primitives.c.o -MF CMakeFiles/allegro_primitives.dir/high_primitives.c.o.d -o CMakeFiles/allegro_primitives.dir/high_primitives.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/high_primitives.c

addons/primitives/CMakeFiles/allegro_primitives.dir/high_primitives.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_primitives.dir/high_primitives.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/high_primitives.c > CMakeFiles/allegro_primitives.dir/high_primitives.c.i

addons/primitives/CMakeFiles/allegro_primitives.dir/high_primitives.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_primitives.dir/high_primitives.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/high_primitives.c -o CMakeFiles/allegro_primitives.dir/high_primitives.c.s

addons/primitives/CMakeFiles/allegro_primitives.dir/line_soft.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/line_soft.c.o: ../addons/primitives/line_soft.c
addons/primitives/CMakeFiles/allegro_primitives.dir/line_soft.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object addons/primitives/CMakeFiles/allegro_primitives.dir/line_soft.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/line_soft.c.o -MF CMakeFiles/allegro_primitives.dir/line_soft.c.o.d -o CMakeFiles/allegro_primitives.dir/line_soft.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/line_soft.c

addons/primitives/CMakeFiles/allegro_primitives.dir/line_soft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_primitives.dir/line_soft.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/line_soft.c > CMakeFiles/allegro_primitives.dir/line_soft.c.i

addons/primitives/CMakeFiles/allegro_primitives.dir/line_soft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_primitives.dir/line_soft.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/line_soft.c -o CMakeFiles/allegro_primitives.dir/line_soft.c.s

addons/primitives/CMakeFiles/allegro_primitives.dir/point_soft.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/point_soft.c.o: ../addons/primitives/point_soft.c
addons/primitives/CMakeFiles/allegro_primitives.dir/point_soft.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object addons/primitives/CMakeFiles/allegro_primitives.dir/point_soft.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/point_soft.c.o -MF CMakeFiles/allegro_primitives.dir/point_soft.c.o.d -o CMakeFiles/allegro_primitives.dir/point_soft.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/point_soft.c

addons/primitives/CMakeFiles/allegro_primitives.dir/point_soft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_primitives.dir/point_soft.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/point_soft.c > CMakeFiles/allegro_primitives.dir/point_soft.c.i

addons/primitives/CMakeFiles/allegro_primitives.dir/point_soft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_primitives.dir/point_soft.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/point_soft.c -o CMakeFiles/allegro_primitives.dir/point_soft.c.s

addons/primitives/CMakeFiles/allegro_primitives.dir/polygon.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/polygon.c.o: ../addons/primitives/polygon.c
addons/primitives/CMakeFiles/allegro_primitives.dir/polygon.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object addons/primitives/CMakeFiles/allegro_primitives.dir/polygon.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/polygon.c.o -MF CMakeFiles/allegro_primitives.dir/polygon.c.o.d -o CMakeFiles/allegro_primitives.dir/polygon.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/polygon.c

addons/primitives/CMakeFiles/allegro_primitives.dir/polygon.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_primitives.dir/polygon.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/polygon.c > CMakeFiles/allegro_primitives.dir/polygon.c.i

addons/primitives/CMakeFiles/allegro_primitives.dir/polygon.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_primitives.dir/polygon.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/polygon.c -o CMakeFiles/allegro_primitives.dir/polygon.c.s

addons/primitives/CMakeFiles/allegro_primitives.dir/polyline.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/polyline.c.o: ../addons/primitives/polyline.c
addons/primitives/CMakeFiles/allegro_primitives.dir/polyline.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object addons/primitives/CMakeFiles/allegro_primitives.dir/polyline.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/polyline.c.o -MF CMakeFiles/allegro_primitives.dir/polyline.c.o.d -o CMakeFiles/allegro_primitives.dir/polyline.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/polyline.c

addons/primitives/CMakeFiles/allegro_primitives.dir/polyline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_primitives.dir/polyline.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/polyline.c > CMakeFiles/allegro_primitives.dir/polyline.c.i

addons/primitives/CMakeFiles/allegro_primitives.dir/polyline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_primitives.dir/polyline.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/polyline.c -o CMakeFiles/allegro_primitives.dir/polyline.c.s

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_directx.cpp.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/prim_directx.cpp.o: ../addons/primitives/prim_directx.cpp
addons/primitives/CMakeFiles/allegro_primitives.dir/prim_directx.cpp.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object addons/primitives/CMakeFiles/allegro_primitives.dir/prim_directx.cpp.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/prim_directx.cpp.o -MF CMakeFiles/allegro_primitives.dir/prim_directx.cpp.o.d -o CMakeFiles/allegro_primitives.dir/prim_directx.cpp.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_directx.cpp

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_directx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/allegro_primitives.dir/prim_directx.cpp.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_directx.cpp > CMakeFiles/allegro_primitives.dir/prim_directx.cpp.i

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_directx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/allegro_primitives.dir/prim_directx.cpp.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_directx.cpp -o CMakeFiles/allegro_primitives.dir/prim_directx.cpp.s

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_opengl.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/prim_opengl.c.o: ../addons/primitives/prim_opengl.c
addons/primitives/CMakeFiles/allegro_primitives.dir/prim_opengl.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object addons/primitives/CMakeFiles/allegro_primitives.dir/prim_opengl.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/prim_opengl.c.o -MF CMakeFiles/allegro_primitives.dir/prim_opengl.c.o.d -o CMakeFiles/allegro_primitives.dir/prim_opengl.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_opengl.c

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_opengl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_primitives.dir/prim_opengl.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_opengl.c > CMakeFiles/allegro_primitives.dir/prim_opengl.c.i

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_opengl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_primitives.dir/prim_opengl.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_opengl.c -o CMakeFiles/allegro_primitives.dir/prim_opengl.c.s

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_soft.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/prim_soft.c.o: ../addons/primitives/prim_soft.c
addons/primitives/CMakeFiles/allegro_primitives.dir/prim_soft.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object addons/primitives/CMakeFiles/allegro_primitives.dir/prim_soft.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/prim_soft.c.o -MF CMakeFiles/allegro_primitives.dir/prim_soft.c.o.d -o CMakeFiles/allegro_primitives.dir/prim_soft.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_soft.c

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_soft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_primitives.dir/prim_soft.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_soft.c > CMakeFiles/allegro_primitives.dir/prim_soft.c.i

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_soft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_primitives.dir/prim_soft.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_soft.c -o CMakeFiles/allegro_primitives.dir/prim_soft.c.s

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_util.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/prim_util.c.o: ../addons/primitives/prim_util.c
addons/primitives/CMakeFiles/allegro_primitives.dir/prim_util.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object addons/primitives/CMakeFiles/allegro_primitives.dir/prim_util.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/prim_util.c.o -MF CMakeFiles/allegro_primitives.dir/prim_util.c.o.d -o CMakeFiles/allegro_primitives.dir/prim_util.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_util.c

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_primitives.dir/prim_util.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_util.c > CMakeFiles/allegro_primitives.dir/prim_util.c.i

addons/primitives/CMakeFiles/allegro_primitives.dir/prim_util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_primitives.dir/prim_util.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/prim_util.c -o CMakeFiles/allegro_primitives.dir/prim_util.c.s

addons/primitives/CMakeFiles/allegro_primitives.dir/primitives.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/primitives.c.o: ../addons/primitives/primitives.c
addons/primitives/CMakeFiles/allegro_primitives.dir/primitives.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object addons/primitives/CMakeFiles/allegro_primitives.dir/primitives.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/primitives.c.o -MF CMakeFiles/allegro_primitives.dir/primitives.c.o.d -o CMakeFiles/allegro_primitives.dir/primitives.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/primitives.c

addons/primitives/CMakeFiles/allegro_primitives.dir/primitives.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_primitives.dir/primitives.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/primitives.c > CMakeFiles/allegro_primitives.dir/primitives.c.i

addons/primitives/CMakeFiles/allegro_primitives.dir/primitives.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_primitives.dir/primitives.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/primitives.c -o CMakeFiles/allegro_primitives.dir/primitives.c.s

addons/primitives/CMakeFiles/allegro_primitives.dir/triangulator.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/flags.make
addons/primitives/CMakeFiles/allegro_primitives.dir/triangulator.c.o: ../addons/primitives/triangulator.c
addons/primitives/CMakeFiles/allegro_primitives.dir/triangulator.c.o: addons/primitives/CMakeFiles/allegro_primitives.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object addons/primitives/CMakeFiles/allegro_primitives.dir/triangulator.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/primitives/CMakeFiles/allegro_primitives.dir/triangulator.c.o -MF CMakeFiles/allegro_primitives.dir/triangulator.c.o.d -o CMakeFiles/allegro_primitives.dir/triangulator.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/triangulator.c

addons/primitives/CMakeFiles/allegro_primitives.dir/triangulator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_primitives.dir/triangulator.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/triangulator.c > CMakeFiles/allegro_primitives.dir/triangulator.c.i

addons/primitives/CMakeFiles/allegro_primitives.dir/triangulator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_primitives.dir/triangulator.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives/triangulator.c -o CMakeFiles/allegro_primitives.dir/triangulator.c.s

# Object files for target allegro_primitives
allegro_primitives_OBJECTS = \
"CMakeFiles/allegro_primitives.dir/high_primitives.c.o" \
"CMakeFiles/allegro_primitives.dir/line_soft.c.o" \
"CMakeFiles/allegro_primitives.dir/point_soft.c.o" \
"CMakeFiles/allegro_primitives.dir/polygon.c.o" \
"CMakeFiles/allegro_primitives.dir/polyline.c.o" \
"CMakeFiles/allegro_primitives.dir/prim_directx.cpp.o" \
"CMakeFiles/allegro_primitives.dir/prim_opengl.c.o" \
"CMakeFiles/allegro_primitives.dir/prim_soft.c.o" \
"CMakeFiles/allegro_primitives.dir/prim_util.c.o" \
"CMakeFiles/allegro_primitives.dir/primitives.c.o" \
"CMakeFiles/allegro_primitives.dir/triangulator.c.o"

# External object files for target allegro_primitives
allegro_primitives_EXTERNAL_OBJECTS =

lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/high_primitives.c.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/line_soft.c.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/point_soft.c.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/polygon.c.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/polyline.c.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/prim_directx.cpp.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/prim_opengl.c.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/prim_soft.c.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/prim_util.c.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/primitives.c.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/triangulator.c.o
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/build.make
lib/liballegro_primitives.5.2.7.dylib: lib/liballegro.5.2.7.dylib
lib/liballegro_primitives.5.2.7.dylib: addons/primitives/CMakeFiles/allegro_primitives.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX shared library ../../lib/liballegro_primitives.dylib"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allegro_primitives.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/liballegro_primitives.5.2.7.dylib ../../lib/liballegro_primitives.5.2.dylib ../../lib/liballegro_primitives.dylib

lib/liballegro_primitives.5.2.dylib: lib/liballegro_primitives.5.2.7.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/liballegro_primitives.5.2.dylib

lib/liballegro_primitives.dylib: lib/liballegro_primitives.5.2.7.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/liballegro_primitives.dylib

# Rule to build all files generated by this target.
addons/primitives/CMakeFiles/allegro_primitives.dir/build: lib/liballegro_primitives.dylib
.PHONY : addons/primitives/CMakeFiles/allegro_primitives.dir/build

addons/primitives/CMakeFiles/allegro_primitives.dir/clean:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives && $(CMAKE_COMMAND) -P CMakeFiles/allegro_primitives.dir/cmake_clean.cmake
.PHONY : addons/primitives/CMakeFiles/allegro_primitives.dir/clean

addons/primitives/CMakeFiles/allegro_primitives.dir/depend:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0 /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/primitives /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/primitives/CMakeFiles/allegro_primitives.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : addons/primitives/CMakeFiles/allegro_primitives.dir/depend


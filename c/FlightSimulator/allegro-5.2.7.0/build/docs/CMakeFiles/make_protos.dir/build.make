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
include docs/CMakeFiles/make_protos.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include docs/CMakeFiles/make_protos.dir/compiler_depend.make

# Include the progress variables for this target.
include docs/CMakeFiles/make_protos.dir/progress.make

# Include the compile flags for this target's objects.
include docs/CMakeFiles/make_protos.dir/flags.make

docs/CMakeFiles/make_protos.dir/scripts/make_protos.c.o: docs/CMakeFiles/make_protos.dir/flags.make
docs/CMakeFiles/make_protos.dir/scripts/make_protos.c.o: ../docs/scripts/make_protos.c
docs/CMakeFiles/make_protos.dir/scripts/make_protos.c.o: docs/CMakeFiles/make_protos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object docs/CMakeFiles/make_protos.dir/scripts/make_protos.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT docs/CMakeFiles/make_protos.dir/scripts/make_protos.c.o -MF CMakeFiles/make_protos.dir/scripts/make_protos.c.o.d -o CMakeFiles/make_protos.dir/scripts/make_protos.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/make_protos.c

docs/CMakeFiles/make_protos.dir/scripts/make_protos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/make_protos.dir/scripts/make_protos.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/make_protos.c > CMakeFiles/make_protos.dir/scripts/make_protos.c.i

docs/CMakeFiles/make_protos.dir/scripts/make_protos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/make_protos.dir/scripts/make_protos.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/make_protos.c -o CMakeFiles/make_protos.dir/scripts/make_protos.c.s

docs/CMakeFiles/make_protos.dir/scripts/aatree.c.o: docs/CMakeFiles/make_protos.dir/flags.make
docs/CMakeFiles/make_protos.dir/scripts/aatree.c.o: ../docs/scripts/aatree.c
docs/CMakeFiles/make_protos.dir/scripts/aatree.c.o: docs/CMakeFiles/make_protos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object docs/CMakeFiles/make_protos.dir/scripts/aatree.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT docs/CMakeFiles/make_protos.dir/scripts/aatree.c.o -MF CMakeFiles/make_protos.dir/scripts/aatree.c.o.d -o CMakeFiles/make_protos.dir/scripts/aatree.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/aatree.c

docs/CMakeFiles/make_protos.dir/scripts/aatree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/make_protos.dir/scripts/aatree.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/aatree.c > CMakeFiles/make_protos.dir/scripts/aatree.c.i

docs/CMakeFiles/make_protos.dir/scripts/aatree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/make_protos.dir/scripts/aatree.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/aatree.c -o CMakeFiles/make_protos.dir/scripts/aatree.c.s

docs/CMakeFiles/make_protos.dir/scripts/dawk.c.o: docs/CMakeFiles/make_protos.dir/flags.make
docs/CMakeFiles/make_protos.dir/scripts/dawk.c.o: ../docs/scripts/dawk.c
docs/CMakeFiles/make_protos.dir/scripts/dawk.c.o: docs/CMakeFiles/make_protos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object docs/CMakeFiles/make_protos.dir/scripts/dawk.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT docs/CMakeFiles/make_protos.dir/scripts/dawk.c.o -MF CMakeFiles/make_protos.dir/scripts/dawk.c.o.d -o CMakeFiles/make_protos.dir/scripts/dawk.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/dawk.c

docs/CMakeFiles/make_protos.dir/scripts/dawk.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/make_protos.dir/scripts/dawk.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/dawk.c > CMakeFiles/make_protos.dir/scripts/dawk.c.i

docs/CMakeFiles/make_protos.dir/scripts/dawk.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/make_protos.dir/scripts/dawk.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/dawk.c -o CMakeFiles/make_protos.dir/scripts/dawk.c.s

docs/CMakeFiles/make_protos.dir/scripts/trex.c.o: docs/CMakeFiles/make_protos.dir/flags.make
docs/CMakeFiles/make_protos.dir/scripts/trex.c.o: ../docs/scripts/trex.c
docs/CMakeFiles/make_protos.dir/scripts/trex.c.o: docs/CMakeFiles/make_protos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object docs/CMakeFiles/make_protos.dir/scripts/trex.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT docs/CMakeFiles/make_protos.dir/scripts/trex.c.o -MF CMakeFiles/make_protos.dir/scripts/trex.c.o.d -o CMakeFiles/make_protos.dir/scripts/trex.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/trex.c

docs/CMakeFiles/make_protos.dir/scripts/trex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/make_protos.dir/scripts/trex.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/trex.c > CMakeFiles/make_protos.dir/scripts/trex.c.i

docs/CMakeFiles/make_protos.dir/scripts/trex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/make_protos.dir/scripts/trex.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs/scripts/trex.c -o CMakeFiles/make_protos.dir/scripts/trex.c.s

# Object files for target make_protos
make_protos_OBJECTS = \
"CMakeFiles/make_protos.dir/scripts/make_protos.c.o" \
"CMakeFiles/make_protos.dir/scripts/aatree.c.o" \
"CMakeFiles/make_protos.dir/scripts/dawk.c.o" \
"CMakeFiles/make_protos.dir/scripts/trex.c.o"

# External object files for target make_protos
make_protos_EXTERNAL_OBJECTS =

docs/make_protos: docs/CMakeFiles/make_protos.dir/scripts/make_protos.c.o
docs/make_protos: docs/CMakeFiles/make_protos.dir/scripts/aatree.c.o
docs/make_protos: docs/CMakeFiles/make_protos.dir/scripts/dawk.c.o
docs/make_protos: docs/CMakeFiles/make_protos.dir/scripts/trex.c.o
docs/make_protos: docs/CMakeFiles/make_protos.dir/build.make
docs/make_protos: docs/CMakeFiles/make_protos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable make_protos"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/make_protos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
docs/CMakeFiles/make_protos.dir/build: docs/make_protos
.PHONY : docs/CMakeFiles/make_protos.dir/build

docs/CMakeFiles/make_protos.dir/clean:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs && $(CMAKE_COMMAND) -P CMakeFiles/make_protos.dir/cmake_clean.cmake
.PHONY : docs/CMakeFiles/make_protos.dir/clean

docs/CMakeFiles/make_protos.dir/depend:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0 /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/docs /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/docs/CMakeFiles/make_protos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : docs/CMakeFiles/make_protos.dir/depend


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
include addons/video/CMakeFiles/allegro_video.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include addons/video/CMakeFiles/allegro_video.dir/compiler_depend.make

# Include the progress variables for this target.
include addons/video/CMakeFiles/allegro_video.dir/progress.make

# Include the compile flags for this target's objects.
include addons/video/CMakeFiles/allegro_video.dir/flags.make

addons/video/CMakeFiles/allegro_video.dir/video.c.o: addons/video/CMakeFiles/allegro_video.dir/flags.make
addons/video/CMakeFiles/allegro_video.dir/video.c.o: ../addons/video/video.c
addons/video/CMakeFiles/allegro_video.dir/video.c.o: addons/video/CMakeFiles/allegro_video.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object addons/video/CMakeFiles/allegro_video.dir/video.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/video/CMakeFiles/allegro_video.dir/video.c.o -MF CMakeFiles/allegro_video.dir/video.c.o.d -o CMakeFiles/allegro_video.dir/video.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/video/video.c

addons/video/CMakeFiles/allegro_video.dir/video.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_video.dir/video.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/video/video.c > CMakeFiles/allegro_video.dir/video.c.i

addons/video/CMakeFiles/allegro_video.dir/video.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_video.dir/video.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/video/video.c -o CMakeFiles/allegro_video.dir/video.c.s

addons/video/CMakeFiles/allegro_video.dir/ogv.c.o: addons/video/CMakeFiles/allegro_video.dir/flags.make
addons/video/CMakeFiles/allegro_video.dir/ogv.c.o: ../addons/video/ogv.c
addons/video/CMakeFiles/allegro_video.dir/ogv.c.o: addons/video/CMakeFiles/allegro_video.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object addons/video/CMakeFiles/allegro_video.dir/ogv.c.o"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT addons/video/CMakeFiles/allegro_video.dir/ogv.c.o -MF CMakeFiles/allegro_video.dir/ogv.c.o.d -o CMakeFiles/allegro_video.dir/ogv.c.o -c /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/video/ogv.c

addons/video/CMakeFiles/allegro_video.dir/ogv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/allegro_video.dir/ogv.c.i"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/video/ogv.c > CMakeFiles/allegro_video.dir/ogv.c.i

addons/video/CMakeFiles/allegro_video.dir/ogv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/allegro_video.dir/ogv.c.s"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/video/ogv.c -o CMakeFiles/allegro_video.dir/ogv.c.s

# Object files for target allegro_video
allegro_video_OBJECTS = \
"CMakeFiles/allegro_video.dir/video.c.o" \
"CMakeFiles/allegro_video.dir/ogv.c.o"

# External object files for target allegro_video
allegro_video_EXTERNAL_OBJECTS =

lib/liballegro_video.5.2.7.dylib: addons/video/CMakeFiles/allegro_video.dir/video.c.o
lib/liballegro_video.5.2.7.dylib: addons/video/CMakeFiles/allegro_video.dir/ogv.c.o
lib/liballegro_video.5.2.7.dylib: addons/video/CMakeFiles/allegro_video.dir/build.make
lib/liballegro_video.5.2.7.dylib: lib/liballegro_audio.5.2.7.dylib
lib/liballegro_video.5.2.7.dylib: /usr/local/lib/libtheoradec.dylib
lib/liballegro_video.5.2.7.dylib: /usr/local/lib/libogg.dylib
lib/liballegro_video.5.2.7.dylib: /usr/local/lib/libvorbisfile.dylib
lib/liballegro_video.5.2.7.dylib: /usr/local/lib/libvorbis.dylib
lib/liballegro_video.5.2.7.dylib: /usr/local/lib/libogg.dylib
lib/liballegro_video.5.2.7.dylib: lib/liballegro.5.2.7.dylib
lib/liballegro_video.5.2.7.dylib: /usr/local/lib/libvorbisfile.dylib
lib/liballegro_video.5.2.7.dylib: /usr/local/lib/libvorbis.dylib
lib/liballegro_video.5.2.7.dylib: addons/video/CMakeFiles/allegro_video.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library ../../lib/liballegro_video.dylib"
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allegro_video.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/liballegro_video.5.2.7.dylib ../../lib/liballegro_video.5.2.dylib ../../lib/liballegro_video.dylib

lib/liballegro_video.5.2.dylib: lib/liballegro_video.5.2.7.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/liballegro_video.5.2.dylib

lib/liballegro_video.dylib: lib/liballegro_video.5.2.7.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/liballegro_video.dylib

# Rule to build all files generated by this target.
addons/video/CMakeFiles/allegro_video.dir/build: lib/liballegro_video.dylib
.PHONY : addons/video/CMakeFiles/allegro_video.dir/build

addons/video/CMakeFiles/allegro_video.dir/clean:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video && $(CMAKE_COMMAND) -P CMakeFiles/allegro_video.dir/cmake_clean.cmake
.PHONY : addons/video/CMakeFiles/allegro_video.dir/clean

addons/video/CMakeFiles/allegro_video.dir/depend:
	cd /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0 /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/addons/video /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video /Users/renato/Workspace/github/university/c/FlightSimulator/allegro-5.2.7.0/build/addons/video/CMakeFiles/allegro_video.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : addons/video/CMakeFiles/allegro_video.dir/depend


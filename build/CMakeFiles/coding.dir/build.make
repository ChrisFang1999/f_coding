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
CMAKE_COMMAND = /usr/share/cmake-3.21.0/bin/cmake

# The command to remove a file.
RM = /usr/share/cmake-3.21.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qrg/software_dyfang/f_coding

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qrg/software_dyfang/f_coding/build

# Include any dependencies generated for this target.
include CMakeFiles/coding.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/coding.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/coding.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/coding.dir/flags.make

CMakeFiles/coding.dir/src/coding.cc.o: CMakeFiles/coding.dir/flags.make
CMakeFiles/coding.dir/src/coding.cc.o: ../src/coding.cc
CMakeFiles/coding.dir/src/coding.cc.o: CMakeFiles/coding.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qrg/software_dyfang/f_coding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/coding.dir/src/coding.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/coding.dir/src/coding.cc.o -MF CMakeFiles/coding.dir/src/coding.cc.o.d -o CMakeFiles/coding.dir/src/coding.cc.o -c /home/qrg/software_dyfang/f_coding/src/coding.cc

CMakeFiles/coding.dir/src/coding.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coding.dir/src/coding.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qrg/software_dyfang/f_coding/src/coding.cc > CMakeFiles/coding.dir/src/coding.cc.i

CMakeFiles/coding.dir/src/coding.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coding.dir/src/coding.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qrg/software_dyfang/f_coding/src/coding.cc -o CMakeFiles/coding.dir/src/coding.cc.s

# Object files for target coding
coding_OBJECTS = \
"CMakeFiles/coding.dir/src/coding.cc.o"

# External object files for target coding
coding_EXTERNAL_OBJECTS =

../bin/coding: CMakeFiles/coding.dir/src/coding.cc.o
../bin/coding: CMakeFiles/coding.dir/build.make
../bin/coding: CMakeFiles/coding.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qrg/software_dyfang/f_coding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/coding"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/coding.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/coding.dir/build: ../bin/coding
.PHONY : CMakeFiles/coding.dir/build

CMakeFiles/coding.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coding.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coding.dir/clean

CMakeFiles/coding.dir/depend:
	cd /home/qrg/software_dyfang/f_coding/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qrg/software_dyfang/f_coding /home/qrg/software_dyfang/f_coding /home/qrg/software_dyfang/f_coding/build /home/qrg/software_dyfang/f_coding/build /home/qrg/software_dyfang/f_coding/build/CMakeFiles/coding.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coding.dir/depend


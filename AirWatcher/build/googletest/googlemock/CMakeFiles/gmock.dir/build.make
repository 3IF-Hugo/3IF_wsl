# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hgrel/3IF_wsl/AirWatcher

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hgrel/3IF_wsl/AirWatcher/build

# Include any dependencies generated for this target.
include googletest/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include googletest/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/googlemock/CMakeFiles/gmock.dir/flags.make

googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: googletest/googlemock/CMakeFiles/gmock.dir/flags.make
googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../googletest/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hgrel/3IF_wsl/AirWatcher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /home/hgrel/3IF_wsl/AirWatcher/build/googletest/googlemock && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /home/hgrel/3IF_wsl/AirWatcher/googletest/googlemock/src/gmock-all.cc

googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /home/hgrel/3IF_wsl/AirWatcher/build/googletest/googlemock && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hgrel/3IF_wsl/AirWatcher/googletest/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /home/hgrel/3IF_wsl/AirWatcher/build/googletest/googlemock && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hgrel/3IF_wsl/AirWatcher/googletest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmock.a: googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
lib/libgmock.a: googletest/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmock.a: googletest/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hgrel/3IF_wsl/AirWatcher/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libgmock.a"
	cd /home/hgrel/3IF_wsl/AirWatcher/build/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /home/hgrel/3IF_wsl/AirWatcher/build/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/googlemock/CMakeFiles/gmock.dir/build: lib/libgmock.a

.PHONY : googletest/googlemock/CMakeFiles/gmock.dir/build

googletest/googlemock/CMakeFiles/gmock.dir/clean:
	cd /home/hgrel/3IF_wsl/AirWatcher/build/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : googletest/googlemock/CMakeFiles/gmock.dir/clean

googletest/googlemock/CMakeFiles/gmock.dir/depend:
	cd /home/hgrel/3IF_wsl/AirWatcher/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hgrel/3IF_wsl/AirWatcher /home/hgrel/3IF_wsl/AirWatcher/googletest/googlemock /home/hgrel/3IF_wsl/AirWatcher/build /home/hgrel/3IF_wsl/AirWatcher/build/googletest/googlemock /home/hgrel/3IF_wsl/AirWatcher/build/googletest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/googlemock/CMakeFiles/gmock.dir/depend


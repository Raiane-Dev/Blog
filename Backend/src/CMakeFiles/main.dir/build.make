# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /app/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /app/src

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/Server.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Server.cpp.o: Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/Server.cpp.o -c /app/src/Server.cpp

CMakeFiles/main.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /app/src/Server.cpp > CMakeFiles/main.dir/Server.cpp.i

CMakeFiles/main.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /app/src/Server.cpp -o CMakeFiles/main.dir/Server.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/Server.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

/app/build/bin/main: CMakeFiles/main.dir/Server.cpp.o
/app/build/bin/main: CMakeFiles/main.dir/build.make
/app/build/bin/main: /app/libraries/vcpkg_installed/x64-linux/debug/lib/libPocoFoundationd.a
/app/build/bin/main: /app/libraries/vcpkg_installed/x64-linux/debug/lib/libpcre.a
/app/build/bin/main: /app/libraries/vcpkg_installed/x64-linux/lib/libz.a
/app/build/bin/main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/app/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /app/build/bin/main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: /app/build/bin/main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /app/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app/src /app/src /app/src /app/src /app/src/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend


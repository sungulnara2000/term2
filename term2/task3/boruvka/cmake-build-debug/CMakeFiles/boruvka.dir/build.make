# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/boruvka.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boruvka.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boruvka.dir/flags.make

CMakeFiles/boruvka.dir/main.cpp.o: CMakeFiles/boruvka.dir/flags.make
CMakeFiles/boruvka.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boruvka.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boruvka.dir/main.cpp.o -c /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/main.cpp

CMakeFiles/boruvka.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boruvka.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/main.cpp > CMakeFiles/boruvka.dir/main.cpp.i

CMakeFiles/boruvka.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boruvka.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/main.cpp -o CMakeFiles/boruvka.dir/main.cpp.s

CMakeFiles/boruvka.dir/ListGraph.cpp.o: CMakeFiles/boruvka.dir/flags.make
CMakeFiles/boruvka.dir/ListGraph.cpp.o: ../ListGraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/boruvka.dir/ListGraph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boruvka.dir/ListGraph.cpp.o -c /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/ListGraph.cpp

CMakeFiles/boruvka.dir/ListGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boruvka.dir/ListGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/ListGraph.cpp > CMakeFiles/boruvka.dir/ListGraph.cpp.i

CMakeFiles/boruvka.dir/ListGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boruvka.dir/ListGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/ListGraph.cpp -o CMakeFiles/boruvka.dir/ListGraph.cpp.s

CMakeFiles/boruvka.dir/MSTweight.cpp.o: CMakeFiles/boruvka.dir/flags.make
CMakeFiles/boruvka.dir/MSTweight.cpp.o: ../MSTweight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/boruvka.dir/MSTweight.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boruvka.dir/MSTweight.cpp.o -c /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/MSTweight.cpp

CMakeFiles/boruvka.dir/MSTweight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boruvka.dir/MSTweight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/MSTweight.cpp > CMakeFiles/boruvka.dir/MSTweight.cpp.i

CMakeFiles/boruvka.dir/MSTweight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boruvka.dir/MSTweight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/MSTweight.cpp -o CMakeFiles/boruvka.dir/MSTweight.cpp.s

# Object files for target boruvka
boruvka_OBJECTS = \
"CMakeFiles/boruvka.dir/main.cpp.o" \
"CMakeFiles/boruvka.dir/ListGraph.cpp.o" \
"CMakeFiles/boruvka.dir/MSTweight.cpp.o"

# External object files for target boruvka
boruvka_EXTERNAL_OBJECTS =

boruvka: CMakeFiles/boruvka.dir/main.cpp.o
boruvka: CMakeFiles/boruvka.dir/ListGraph.cpp.o
boruvka: CMakeFiles/boruvka.dir/MSTweight.cpp.o
boruvka: CMakeFiles/boruvka.dir/build.make
boruvka: CMakeFiles/boruvka.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable boruvka"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boruvka.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boruvka.dir/build: boruvka

.PHONY : CMakeFiles/boruvka.dir/build

CMakeFiles/boruvka.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boruvka.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boruvka.dir/clean

CMakeFiles/boruvka.dir/depend:
	cd /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/cmake-build-debug /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/cmake-build-debug /home/gulnara/Documents/programming/git_repo/term2/task3/boruvka/cmake-build-debug/CMakeFiles/boruvka.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boruvka.dir/depend


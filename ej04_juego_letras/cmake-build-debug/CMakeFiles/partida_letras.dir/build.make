# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/egalv/Desktop/ej04_juego_letras

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/partida_letras.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/partida_letras.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/partida_letras.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/partida_letras.dir/flags.make

CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.o: CMakeFiles/partida_letras.dir/flags.make
CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.o: ../estudiante/src/partida_letras.cpp
CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.o: CMakeFiles/partida_letras.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.o -MF CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.o.d -o CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.o -c /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/partida_letras.cpp

CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/partida_letras.cpp > CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.i

CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/partida_letras.cpp -o CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.s

CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.o: CMakeFiles/partida_letras.dir/flags.make
CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.o: ../estudiante/src/letters_set.cpp
CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.o: CMakeFiles/partida_letras.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.o -MF CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.o.d -o CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.o -c /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/letters_set.cpp

CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/letters_set.cpp > CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.i

CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/letters_set.cpp -o CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.s

CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.o: CMakeFiles/partida_letras.dir/flags.make
CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.o: ../estudiante/src/letters_bag.cpp
CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.o: CMakeFiles/partida_letras.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.o -MF CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.o.d -o CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.o -c /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/letters_bag.cpp

CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/letters_bag.cpp > CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.i

CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/letters_bag.cpp -o CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.s

CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.o: CMakeFiles/partida_letras.dir/flags.make
CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.o: ../estudiante/src/solver.cpp
CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.o: CMakeFiles/partida_letras.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.o -MF CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.o.d -o CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.o -c /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/solver.cpp

CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/solver.cpp > CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.i

CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/solver.cpp -o CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.s

CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.o: CMakeFiles/partida_letras.dir/flags.make
CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.o: ../estudiante/src/dictionary.cpp
CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.o: CMakeFiles/partida_letras.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.o -MF CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.o.d -o CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.o -c /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/dictionary.cpp

CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/dictionary.cpp > CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.i

CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/egalv/Desktop/ej04_juego_letras/estudiante/src/dictionary.cpp -o CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.s

# Object files for target partida_letras
partida_letras_OBJECTS = \
"CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.o" \
"CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.o" \
"CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.o" \
"CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.o" \
"CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.o"

# External object files for target partida_letras
partida_letras_EXTERNAL_OBJECTS =

partida_letras: CMakeFiles/partida_letras.dir/estudiante/src/partida_letras.cpp.o
partida_letras: CMakeFiles/partida_letras.dir/estudiante/src/letters_set.cpp.o
partida_letras: CMakeFiles/partida_letras.dir/estudiante/src/letters_bag.cpp.o
partida_letras: CMakeFiles/partida_letras.dir/estudiante/src/solver.cpp.o
partida_letras: CMakeFiles/partida_letras.dir/estudiante/src/dictionary.cpp.o
partida_letras: CMakeFiles/partida_letras.dir/build.make
partida_letras: CMakeFiles/partida_letras.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable partida_letras"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/partida_letras.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/partida_letras.dir/build: partida_letras
.PHONY : CMakeFiles/partida_letras.dir/build

CMakeFiles/partida_letras.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/partida_letras.dir/cmake_clean.cmake
.PHONY : CMakeFiles/partida_letras.dir/clean

CMakeFiles/partida_letras.dir/depend:
	cd /mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/egalv/Desktop/ej04_juego_letras /mnt/c/Users/egalv/Desktop/ej04_juego_letras /mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug /mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug /mnt/c/Users/egalv/Desktop/ej04_juego_letras/cmake-build-debug/CMakeFiles/partida_letras.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/partida_letras.dir/depend


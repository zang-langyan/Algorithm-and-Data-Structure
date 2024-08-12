# Algorithm and Data Structure
***Author: Langyan Zang***

This is a repository holding all my practice of algorithm and data structure.
Issues and PRs are welcome!


## Quick Start 
This project is based on CMake. (If you are looking for Python, Lua, Go, Rust codes, OFC you can run those code directly. But using CMake to manage this repo's organization is highly recommended)

To generate this project, simply run the following command
```sh
cmake -B build
```

To run a specfic file, run `cmake --build build --target <file/dir name>_<language>`

For example, if you want to run the union_find C++ version, run
```sh
cmake --build build --target union_find_cpp
```
or if you want to run the union_find Lua version, run
```sh
cmake --build build --target union_find_lua
```
or if you want to run the dijkstra algo Python version run
```sh
cmake --build build --target dijkstra_py
```
etc.

Check the source file for the main program defined in it. Edit it as you like to practice, and use the above commands to see the results.

## Q&A
- C++
- Python
- Fortran
- Lua
- Go
- Rust

The above languages version will update from time to time...

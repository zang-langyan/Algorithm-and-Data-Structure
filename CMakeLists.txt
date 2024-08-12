cmake_minimum_required(VERSION 3.20)

project(Algorithm_and_Data_Structure)


set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(OUTPUT_DIR ${PROJECT_DIR}/bin)

#[[ C++ ]]
add_subdirectory(${PROJECT_DIR}/C++ ${OUTPUT_DIR}/C++)

#[[ Python ]]
add_subdirectory(${PROJECT_DIR}/Python ${OUTPUT_DIR}/Python)

#[[ Fortran ]]

#[[ Lua ]]
add_subdirectory(${PROJECT_DIR}/Lua ${OUTPUT_DIR}/Lua)

#[[ Go ]]

#[[ Rust ]]

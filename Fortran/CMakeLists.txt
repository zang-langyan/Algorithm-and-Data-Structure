cmake_minimum_required(VERSION 3.20)

project(ADS_Fortran)
enable_language(Fortran)

set(FORTRAN_PROJECT_DIR ${PROJECT_SOURCE_DIR})

message("Building Fortran in ${FORTRAN_PROJECT_DIR}")

function(GenFort)
  set(exe_name EXE_NAME)
  set(source_args SOURCE_LIST)
  cmake_parse_arguments(GenFort "" "${exe_name}" "${source_args}" ${ARGN})
  
  set(EXE_NAME GenFort_EXE_NAME)
  set(SOURCE_LIST GenFort_SOURCE_LIST)
  set(INCLUDE_LIST GenFort_INCLUDE_LIST)

  add_executable(${${EXE_NAME}}_fort_exe ${${SOURCE_LIST}})
  add_custom_target(
    ${${EXE_NAME}}_fortran
    COMMAND ${OUTPUT_DIR}/Fortran/${${EXE_NAME}}_fort_exe
    DEPENDS ${${EXE_NAME}}_fort_exe
  )
endfunction()

# --------------------------------
# Union Find
# --------------------------------
#[[ Union Find ]]
GenFort(
  EXE_NAME union_find 
  SOURCE_LIST ${FORTRAN_PROJECT_DIR}/union_find/union_find.f90 
)

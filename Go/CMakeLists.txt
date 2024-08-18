cmake_minimum_required(VERSION 3.20)

project(ADS_Go)

set(GO_PROJECT_DIR ${PROJECT_SOURCE_DIR})

set(GO go)

message("Building Go in ${GO_PROJECT_DIR}")

function(GenGo)
  set(exe_name EXE_NAME)
  set(source_args SOURCE_LIST)
  cmake_parse_arguments(GenGo "" "${exe_name}" "${source_args}" ${ARGN})
  
  set(EXE_NAME GenGo_EXE_NAME)
  set(SOURCE_LIST GenGo_SOURCE_LIST)

  set(OUTFILE_GO ${${EXE_NAME}}_go_exe)

  add_custom_target(
    ${${EXE_NAME}}_go_exe
    COMMAND ${GO} build -o ${OUTFILE_GO} ${GO_PROJECT_DIR}/Logging.go ${${SOURCE_LIST}}
    DEPENDS ${${SOURCE_LIST}}
    VERBATIM
  )
  add_custom_target(
    ${${EXE_NAME}}_go
    COMMAND ./${OUTFILE_GO}
    DEPENDS ${OUTFILE_GO}
    VERBATIM
  )
  add_dependencies(${${EXE_NAME}}_go ${${EXE_NAME}}_go_exe)
endfunction()

# --------------------------------
# ListNode
# --------------------------------
#[[ ListNode ]]
GenGo(
  EXE_NAME ListNode
  SOURCE_LIST ${GO_PROJECT_DIR}/ListNode.go
)

# --------------------------------
# Tree
# --------------------------------
#[[ Binary Search Tree ]]
GenGo(
  EXE_NAME BST
  SOURCE_LIST ${GO_PROJECT_DIR}/Tree.go ${GO_PROJECT_DIR}/BST.go
)


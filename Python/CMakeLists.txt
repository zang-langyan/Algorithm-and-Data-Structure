cmake_minimum_required(VERSION 3.20)

project(ADS_Py)

set(PY_PROJECT_DIR ${PROJECT_SOURCE_DIR})

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(PY python3)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  set(PY python)
endif()

message("Building Python in ${PY_PROJECT_DIR}")

function(GenPy)
  set(exe_name EXE_NAME SOURCE_FILE)
  cmake_parse_arguments(GenPy "" "${exe_name}" "" ${ARGN})
  
  set(EXE_NAME GenPy_EXE_NAME)
  set(SOURCE_FILE GenPy_SOURCE_FILE)

  add_custom_target(
    ${${EXE_NAME}}_py
    COMMAND ${PY} ${${SOURCE_FILE}}
    DEPENDS ${${SOURCE_FILE}}
    VERBATIM
  )
endfunction()

# --------------------------------
# Union Find
# --------------------------------
#[[ Union Find ]]
GenPy(
  EXE_NAME union_find
  SOURCE_FILE ${PY_PROJECT_DIR}/union_find/uf.py
)

# --------------------------------
# Shortest Path
# --------------------------------
#[[ Dijkstra ]]
GenPy(
  EXE_NAME dijkstra 
  SOURCE_FILE ${PY_PROJECT_DIR}/shortest_path/dijkstra.py
)

#[[ Floyd ]]
GenPy(
  EXE_NAME floyd 
  SOURCE_FILE ${PY_PROJECT_DIR}/shortest_path/floyd.py
)

# --------------------------------
# Pattern Matching
# --------------------------------
#[[ KMP ]]
set(KMP_SOURCE ${PY_PROJECT_DIR}/pattern_matching/kmp.py)
GenPy(
  EXE_NAME kmp 
  SOURCE_FILE ${KMP_SOURCE} 
)


# --------------------------------
# Minimum Support Tree
# --------------------------------
#[[ Kruskal ]]
set(KRUSKAL_SOURCE ${PY_PROJECT_DIR}/minimum_support_tree/kruskal.py)
GenPy(
  EXE_NAME kruskal 
  SOURCE_FILE ${KRUSKAL_SOURCE} 
)

#[[ Prim ]]
set(PRIM_SOURCE ${PY_PROJECT_DIR}/minimum_support_tree/prim.py)
GenPy(
  EXE_NAME prim 
  SOURCE_FILE ${PRIM_SOURCE} 
)

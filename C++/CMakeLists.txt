cmake_minimum_required(VERSION 3.20)

project(ADS_Cpp)
set(CMAKE_CXX_STANDARD 17)

set(CPP_PROJECT_DIR ${PROJECT_SOURCE_DIR})

message("Building C++ in ${CPP_PROJECT_DIR}")

function(GenCpp)
  set(exe_name EXE_NAME)
  set(source_include_args SOURCE_LIST INCLUDE_LIST)
  cmake_parse_arguments(GenCpp "" "${exe_name}" "${source_include_args}" ${ARGN})
  
  set(EXE_NAME GenCpp_EXE_NAME)
  set(SOURCE_LIST GenCpp_SOURCE_LIST)
  set(INCLUDE_LIST GenCpp_INCLUDE_LIST)

  add_executable(${${EXE_NAME}}_cpp_exe ${${SOURCE_LIST}})
  target_include_directories(${${EXE_NAME}}_cpp_exe PUBLIC ${${INCLUDE_LIST}})
  add_custom_target(
    ${${EXE_NAME}}_cpp
    COMMAND ${OUTPUT_DIR}/C++/${${EXE_NAME}}_cpp_exe
    DEPENDS ${${EXE_NAME}}_cpp_exe
  )
endfunction()

# --------------------------------
# Union Find
# --------------------------------
#[[ Union Find ]]
set(UNION_FIND_SOURCE ${CPP_PROJECT_DIR}/union_find/UF.cpp)
set(UNION_FIND_INCLUDE ${CPP_PROJECT_DIR}/union_find)
GenCpp(
  EXE_NAME union_find 
  SOURCE_LIST ${UNION_FIND_SOURCE} 
  INCLUDE_LIST ${UNION_FIND_INCLUDE}
)

# --------------------------------
# Combinatories
# --------------------------------
#[[ AllPermutation ]]
set(ALLPERMUTATION_SOURCE ${CPP_PROJECT_DIR}/allPermutation.cpp)
GenCpp(
  EXE_NAME allPermutation 
  SOURCE_LIST ${ALLPERMUTATION_SOURCE} 
)

#[[ AllCombination ]]
set(ALLCOMBINATION_SOURCE ${CPP_PROJECT_DIR}/allCombination.cpp)
GenCpp(
  EXE_NAME allCombination 
  SOURCE_LIST ${ALLCOMBINATION_SOURCE} 
)

# --------------------------------
# ListNodes
# --------------------------------
#[[ ListNodes ]]
set(LISTNODES_SOURCE ${CPP_PROJECT_DIR}/ListNodes.cpp)
GenCpp(
  EXE_NAME ListNodes 
  SOURCE_LIST ${LISTNODES_SOURCE} 
)

# --------------------------------
# Tree
# --------------------------------
#[[ BinaryTree ]]
set(BINARYTREE_SOURCE ${CPP_PROJECT_DIR}/Tree/BinaryTree.cpp)
GenCpp(
  EXE_NAME BinaryTree 
  SOURCE_LIST ${BINARYTREE_SOURCE} 
)

#[[ Binary Search Tree ]]
set(BST_SOURCE ${CPP_PROJECT_DIR}/Tree/BST.cpp)
GenCpp(
  EXE_NAME BST 
  SOURCE_LIST ${BST_SOURCE} 
)

#[[ AVLTree ]]
set(AVLTREE_SOURCE ${CPP_PROJECT_DIR}/Tree/AVLTree.cpp)
GenCpp(
  EXE_NAME AVLTree 
  SOURCE_LIST ${AVLTREE_SOURCE} 
)

# --------------------------------
# Sorting
# --------------------------------
#[[ Sorting ]]
set(SORTING_SOURCE ${CPP_PROJECT_DIR}/Sorting/main.cpp)
set(SORTING_INCLUDE ${CPP_PROJECT_DIR}/Sorting)
GenCpp(
  EXE_NAME Sorting 
  SOURCE_LIST ${SORTING_SOURCE} 
  INCLUDE_LIST ${SORTING_INCLUDE}
)

# --------------------------------
# Shortest Path
# --------------------------------
#[[ Dijkstra ]]
set(DIJKSTRA_SOURCE ${CPP_PROJECT_DIR}/shortest_path/dijkstra.cpp)
GenCpp(
  EXE_NAME dijkstra 
  SOURCE_LIST ${DIJKSTRA_SOURCE} 
)

#[[ Floyd ]]
set(FLOYD_SOURCE ${CPP_PROJECT_DIR}/shortest_path/floyd.cpp)
GenCpp(
  EXE_NAME floyd 
  SOURCE_LIST ${FLOYD_SOURCE} 
)


# --------------------------------
# Pattern Matching
# --------------------------------
#[[ KMP ]]
set(KMP_SOURCE ${CPP_PROJECT_DIR}/pattern_matching/kmp.cpp)
GenCpp(
  EXE_NAME kmp 
  SOURCE_LIST ${KMP_SOURCE} 
)


# --------------------------------
# Minimum Support Tree
# --------------------------------
#[[ Kruskal ]]
set(KRUSKAL_SOURCE ${CPP_PROJECT_DIR}/minimum_support_tree/kruskal.cpp)
GenCpp(
  EXE_NAME kruskal 
  SOURCE_LIST ${KRUSKAL_SOURCE} 
)

#[[ Prim ]]
set(PRIM_SOURCE ${CPP_PROJECT_DIR}/minimum_support_tree/prim.cpp)
GenCpp(
  EXE_NAME prim 
  SOURCE_LIST ${PRIM_SOURCE} 
)

# --------------------------------
# Computational Geometry
# --------------------------------
#[[ Convex Hull ]]
set(CONVEX_SOURCE ${CPP_PROJECT_DIR}/Computational_Geometry/Convex.cpp)
GenCpp(
  EXE_NAME Convex 
  SOURCE_LIST ${CONVEX_SOURCE} 
)


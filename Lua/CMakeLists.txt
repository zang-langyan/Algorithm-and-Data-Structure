cmake_minimum_required(VERSION 3.20)

project(ADS_Lua)

set(LUA_PROJECT_DIR ${PROJECT_SOURCE_DIR})

set(LUAC luac)
set(LUA  lua )

message("Building Lua in ${LUA_PROJECT_DIR}")

function(GenLua)
  set(exe_name EXE_NAME SOURCE_FILE)
  cmake_parse_arguments(GenLua "" "${exe_name}" "" ${ARGN})
  
  set(EXE_NAME GenLua_EXE_NAME)
  set(SOURCE_FILE GenLua_SOURCE_FILE)

  set(OUTFILE_LUAC ${${EXE_NAME}}.luac)

  add_custom_target(
    ${${EXE_NAME}}_luac
    COMMAND ${LUAC} -o ${OUTFILE_LUAC} ${${SOURCE_FILE}}
    DEPENDS ${${SOURCE_FILE}}
    VERBATIM
  )
  add_custom_target(
    ${${EXE_NAME}}_lua
    COMMAND ${LUA} ${OUTFILE_LUAC}
    DEPENDS ${OUTFILE_LUAC}
    VERBATIM
  )
  add_dependencies(${${EXE_NAME}}_lua ${${EXE_NAME}}_luac)
endfunction()

# --------------------------------
# Union Find
# --------------------------------
#[[ Union Find ]]
GenLua(
  EXE_NAME union_find
  SOURCE_FILE ${LUA_PROJECT_DIR}/union_find/uf.lua
)



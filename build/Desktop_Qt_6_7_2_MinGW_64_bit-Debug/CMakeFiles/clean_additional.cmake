# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\pecker_vt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\pecker_vt_autogen.dir\\ParseCache.txt"
  "pecker_vt_autogen"
  )
endif()

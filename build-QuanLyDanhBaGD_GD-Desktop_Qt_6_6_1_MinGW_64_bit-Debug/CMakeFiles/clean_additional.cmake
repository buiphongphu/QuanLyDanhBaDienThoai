# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QuanLyDanhBaGD_GD_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QuanLyDanhBaGD_GD_autogen.dir\\ParseCache.txt"
  "QuanLyDanhBaGD_GD_autogen"
  )
endif()

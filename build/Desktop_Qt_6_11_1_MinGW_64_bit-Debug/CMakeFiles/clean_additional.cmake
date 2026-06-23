# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CalculadoraCuadratica_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CalculadoraCuadratica_autogen.dir\\ParseCache.txt"
  "CalculadoraCuadratica_autogen"
  )
endif()

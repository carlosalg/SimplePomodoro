# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appSimplePomodoro_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appSimplePomodoro_autogen.dir/ParseCache.txt"
  "appSimplePomodoro_autogen"
  )
endif()

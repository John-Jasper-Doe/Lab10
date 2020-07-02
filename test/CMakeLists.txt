# CMake file for test directory

set(CMAKE_FOLDER "${CMAKE_FOLDER}/test")

set(PROJECT_SRC
  ${CMAKE_SOURCE_DIR}/src/common/cmdpool.cpp
  ${CMAKE_SOURCE_DIR}/src/common/counter.cpp
)

addtest("alltests"
#  reader.cpp
  testcmdpool.cpp
  testcounter.cpp
  testtsqueue.cpp
  ${PROJECT_SRC}
)

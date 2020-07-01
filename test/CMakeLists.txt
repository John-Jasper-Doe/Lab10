# CMake file for test directory

set(CMAKE_FOLDER "${CMAKE_FOLDER}/test")

set(PROJECT_SRC
  ${CMAKE_SOURCE_DIR}/src/common/cmdpool.cpp
)

addtest("alltests" reader.cpp testcmdpool.cpp ${PROJECT_SRC})

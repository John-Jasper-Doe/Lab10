# Root CMake file for BULKMT Project
#
# Copyright John Doe 2020
# Distributed under the OSI-approved BSD 3-Clause License. See accompanying
# file LICENSE.txt or https://opensource.org/licenses/BSD-3-Clause for details.

cmake_minimum_required(VERSION 3.8)

# Setting name for this project.
set(PROJECT_NAME bulkmt)

# Adding a path with "cmake" modules to the system search paths.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Setting up a project version.
include(version)
if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
  set(BULKMT_PATCH $ENV{TRAVIS_BUILD_NUMBER})
endif ()
set(BULKMT_VERSION ${BULKMT_MAJOR}.${BULKMT_MINOR}.${BULKMT_PATCH})
configure_file(version.hpp.in ${CMAKE_BINARY_DIR}/src/include/version.hpp @ONLY)

## Set property
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Werror -Wextra -Wpedantic -g -O0)
include_directories(${CMAKE_BINARY_DIR}/src/include)

# Setting up a project.
include(print)
include(function)

project(${PROJECT_NAME} CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Setting options on project
option(CLANG_FORMAT "Enable clang-format target" OFF)
option(DOCUMENTATION "Build documentation" ON)
option(TESTING "Build tests" OFF)

if(CLANG_FORMAT)
  include(clang-format)
endif()

if(DOCUMENTATION)
  find_package(Doxygen COMPONENTS dot)
  include(doxygen)
endif()

# Settings for test cases.
if (TESTING)
  print("Target \"test\" enabled")
  include(gtest)
  # set GTEST_INCLUDE_DIR properly
  set(GTEST_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/3rdpaty/gtest/src/googletest/include
    CACHE PATH "path to gtest includes"
  )
  include(CTest)
  include_directories(${GTEST_INCLUDE_DIR})
  add_subdirectory(test)
  enable_testing()
endif()

# Added source directory
add_subdirectory(src)

# generate .deb package
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${BULKMT_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${BULKMT_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${BULKMT_PATCH}")

set(CPACK_PACKAGE_CONTACT john.jasper.doe@gmail.com)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

# include will generate proper code for .deb generation
include(CPack)


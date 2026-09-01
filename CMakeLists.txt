cmake_minimum_required(VERSION 3.31)
project(cmake_tools VERSION 1.0.0)

option(BUILD_TESTS "Build project tests" ON)
option(RUN_TESTS "Run project tests" ON)
option(ENABLE_COVERAGE "Enable code coverage reporting" ON)
option(BUILD_EXAMPLES "Build project examples" ON)

include(cmake/add_target.cmake)
include(cmake/coverage.cmake)
include(cmake/tests.cmake)
include(cmake/version_header.cmake)

add_version_header()
setup_coverage_targets()
  
find_package(fmt QUIET)

add_target(${PROJECT_NAME} STATIC
  INCLUDE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  SOURCES_PATH 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
  PCH_PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gpch.h
  USES_PUBLIC 
    $<TARGET_NAME_IF_EXISTS:fmt::fmt>
  TEST_SOURCES_PATH 
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
)

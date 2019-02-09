cmake_minimum_required(VERSION 3.2)
set(PROJECT_NAME mdckp)
project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)
add_compile_options(-std=c++1y)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(third_party EXCLUDE_FROM_ALL)
set(THIRD_PARTY_INCLUDE_PATH ${THIRD_PARTY_INCLUDE_PATH} PARENT_SCOPE)
set(TEST_THIRD_PARTY_INCLUDE_PATH ${TEST_THIRD_PARTY_INCLUDE_PATH} PARENT_SCOPE)
include_directories(${THIRD_PARTY_INCLUDE_PATH})

include_directories(${CMAKE_CURRENT_BINARY_DIR}/lib/)
add_subdirectory(lib)
include_directories(${LIBRARY_INCLUDE_PATH})
set(MDCKP_LIBRARY_INCLUDE_PATH "${LIBRARY_INCLUDE_PATH}" PARENT_SCOPE)
set(MDCKP_LIBRARY_NAME "${LIB_NAME}" PARENT_SCOPE)

add_subdirectory(apps)

enable_testing()


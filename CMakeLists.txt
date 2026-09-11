cmake_minimum_required(VERSION 3.14)
project(ODTE VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ── Dependencias ──────────────────────────────────────────────
# Boost
find_package(Boost REQUIRED COMPONENTS json)

# GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

# ── Directorios ───────────────────────────────────────────────
set(ODTE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(ODTE_SCHEMA_DIR  ${CMAKE_SOURCE_DIR}/schemas)

# ── Library ───────────────────────────────────────────────────
add_library(odte STATIC
  src/version.cpp
)
target_include_directories(odte PUBLIC ${ODTE_INCLUDE_DIR})
target_link_libraries(odte PUBLIC Boost::json)

# ── Tests ─────────────────────────────────────────────────────
enable_testing()
add_subdirectory(tests)

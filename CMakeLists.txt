cmake_minimum_required(VERSION 3.14)
project(ODTE VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ── Dependencias ──────────────────────────────────────────────
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

# ── Library (por ahora stub, crecerá con el desarrollo) ───────
add_library(odte INTERFACE)
target_include_directories(odte INTERFACE ${ODTE_INCLUDE_DIR})

# ── Tests ─────────────────────────────────────────────────────
enable_testing()
add_subdirectory(tests)

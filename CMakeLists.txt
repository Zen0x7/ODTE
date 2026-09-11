cmake_minimum_required(VERSION 3.14)

if(NOT DEFINED PROJECT_VERSION)
  set(PROJECT_VERSION "0.0.0")
endif()

project(ODTE VERSION ${PROJECT_VERSION} LANGUAGES CXX)

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

# ── Coverage ──────────────────────────────────────────────────
option(ODTE_COVERAGE "Enable code coverage" OFF)
if(ODTE_COVERAGE)
  add_compile_options(--coverage -fprofile-arcs -ftest-coverage -O0)
  add_link_options(--coverage)
endif()

# ── Library ───────────────────────────────────────────────────
add_library(odte STATIC
  src/version.cpp
  src/domain/tax_number.cpp
  src/domain/document_type.cpp
  src/domain/date.cpp
  src/domain/amount.cpp
  src/domain/folio.cpp
  src/domain/business_name.cpp
  src/domain/payment_method.cpp
)
target_include_directories(odte PUBLIC ${ODTE_INCLUDE_DIR})
target_link_libraries(odte PUBLIC Boost::json)

# ── Tests ─────────────────────────────────────────────────────
enable_testing()
add_subdirectory(tests)

# ── CPack ─────────────────────────────────────────────────────
include(GNUInstallDirs)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
  set(ODTE_ARCH "arm64")
else()
  set(ODTE_ARCH "amd64")
endif()

set(CPACK_PACKAGE_NAME "odte")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Orquestador de Documentos Tributarios Electronicos")
set(CPACK_PACKAGE_VENDOR "Zen0x7")
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/LICENSE)
set(CPACK_PACKAGE_CONTACT "https://github.com/Zen0x7/ODTE")

set(CPACK_GENERATOR "TGZ;DEB;RPM")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-Linux-${ODTE_ARCH}")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Zen0x7")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libboost-json-dev")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE ${ODTE_ARCH})
set(CPACK_RPM_PACKAGE_LICENSE "AGPLv3")
set(CPACK_RPM_PACKAGE_REQUIRES "boost-json")
set(CPACK_RPM_PACKAGE_ARCHITECTURE ${ODTE_ARCH})

include(CPack)

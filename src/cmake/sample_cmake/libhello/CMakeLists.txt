cmake_minimum_required(VERSION 3.14.2)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}\\scripts\\buildsystems\\vcpkg.cmake" CACHE STRING "")
endif()

project(libhello)

option(BUILD_INSTALL	"Install header and library"	ON)
option(BUILD_TEST		"Build own tests."				ON)

add_subdirectory(hello)
if (BUILD_TEST)
	enable_testing()
	add_subdirectory(hello_test)
endif(BUILD_TEST)
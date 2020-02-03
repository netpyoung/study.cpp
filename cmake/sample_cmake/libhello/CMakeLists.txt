cmake_minimum_required(VERSION 3.14.2)

project(libhello)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "")

option(BUILD_INSTALL	"Install header and library"	ON)
option(BUILD_TEST		"Build own tests."				ON)

add_subdirectory(hello)
add_subdirectory(hello_test)

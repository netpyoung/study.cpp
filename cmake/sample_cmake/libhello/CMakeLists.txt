cmake_minimum_required(VERSION 3.14.2)

project(libhello)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "")
enable_testing()

add_subdirectory(src)
add_subdirectory(test)

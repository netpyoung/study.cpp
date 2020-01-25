cmake_minimum_required(VERSION 3.14.2)

project(project_helloworld)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "")
enable_testing()

add_subdirectory(helloworld)
add_subdirectory(helloworld_test)
add_subdirectory(main)

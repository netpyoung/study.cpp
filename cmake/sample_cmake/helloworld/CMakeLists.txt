cmake_minimum_required(VERSION 3.14.2)

project(project_helloworld)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "")



option(SNAPPY_BUILD_TESTS "Build Snappy's own tests." ON)
option(SNAPPY_INSTALL "Install Snappy's header and library" ON)


if(SNAPPY_INSTALL)
endif(SNAPPY_INSTALL)

add_subdirectory(helloworld)

add_subdirectory(helloworld_exe)

add_subdirectory(helloworld_test)

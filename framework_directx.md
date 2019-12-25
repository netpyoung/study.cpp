
http://www.rastertek.com/tutdx11s2.html

[Thinking Differennt - directx](https://copynull.tistory.com/category/DirectX%2011%20%EA%B0%95%EC%A2%8C/Basic?page=6)

[ms: windows 10 sdk](https://developer.microsoft.com/en-us/windows/downloads/windows-10-sdk)
[msdn: Programming Guide for Direct3D 11](https://docs.microsoft.com/en-us/windows/win32/direct3d11/dx-graphics-overviews)

vcpkg install directxtk:x86-windows
vcpkg install directxtk:x64-windows


cmake_minimum_required(VERSION 3.12.0)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake CACHE STRING "")
endif()

project(...)

find_path(WIC_TEXTURE_LOADER_INCLUDE_DIR DirectXTK/WICTextureLoader.h)
include_directories(${WIC_TEXTURE_LOADER_INCLUDE_DIR})

find_library(DIRECTXTK_LIBRARY DirectXTK)
target_link_libraries(ppp ${DIRECTXTK_LIBRARY})



precompiled-header
https://docs.microsoft.com/en-us/cpp/build/creating-precompiled-header-files?view=vs-2019

https://github.com/tuccio/IBLGGX/blob/master/CMakeLists.txt



#define WIN32_LEAN_AND_MEAN


https://docs.microsoft.com/en-us/windows/win32/winprog/using-the-windows-headers
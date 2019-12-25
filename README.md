## [vcpkg](https://github.com/Microsoft/vcpkg)

``` ps
PS> cd /
PS> git clone https://github.com/Microsoft/vcpkg.git
PS> cd vcpkg
PS> .\bootstrap-vcpkg.bat
PS> .\vcpkg install gtest:x86-windows gtest:x86-windows-static gtest:x64-windows gtest:x64-windows-static
```

### [triplets](https://github.com/microsoft/vcpkg/blob/master/docs/users/triplets.md)

``` cmd
VCPKG_DEFAULT_TRIPLET=x64-windows
vcpkg install gtest gmock gtest_main gmock_main --triplet x64-windows
```

## CMake

[cmake: env variables](https://cmake.org/cmake/help/latest/manual/cmake-env-variables.7.html)

- environ

``` cmd
VCPKG_ROOT=C:\vcpkg
CMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake
CMAKE_ROOT=C:\Program Files (x86)\CMake\share\cmake-3.14
CMAKE_MODULE_PATH=%CMAKE_ROOT%\Modules
```

``` cmd
// x86
cmake -DCMAKE_GENERATOR_PLATFORM=x86 .

// x64
cmake -DCMAKE_GENERATOR_PLATFORM=x64 .
```

``` cmd
> cmake .
> cmake --build .
```

## [CTest](https://cmake.org/cmake/help/latest/manual/cmake.1.html#build-tool-mode)

``` cmd
> ctest -C Debug
```

``` cmake
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
```
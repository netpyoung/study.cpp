> cd study.cpp/sample_cmake/libhello
> cmake .
> cmake --build . --target install

> cd study.cpp/sample_cmake/helloworld

project/

``` cmake
cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(modern-cmake-template)

enable_testing()

add_subdirectory(..somewhere/lib/lib1)
add_subdirectory(app)
```


..somewhere/lib/lib1

```cmake
enable_testing()
add_subdirectory(src)
add_subdirectory(test)
```

..somewhere/lib/lib1/src
``` cmake
project(lib1)

if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif()

target_compile_options(${PROJECT_NAME} PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall>
     $<$<CXX_COMPILER_ID:MSVC>:
          /WX /Wall /utf-8>)

add_library(${PROJECT_NAME} STATIC
	lib1-priv-impl.cpp
)

add_library(libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(${PROJECT_NAME}	PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

```

..somewhere/lib/lib1/test
``` cmake
project(lib1_test)
if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif()

add_executable(${PROJECT_NAME} Main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE libs::lib1)

add_test(lib1_test ${PROJECT_NAME})
```


project/app/
``` cmake
add_subdirectory(src)
add_subdirectory(test)
```

project/app/src
``` cmake
project(app)

if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif()

add_executable(${PROJECT_NAME}
	Main.cpp
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		libs::lib1
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
```

project/app/tests
``` cmake
project(app_test)
if(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif()

add_executable(${PROJECT_NAME}
    Main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        libs::lib1
)

add_test(app_test ${PROJECT_NAME})
```





ExternalProject_Add (
       B
      GIT_REPOSITORY "<git_repo_url>"
      GIT_TAG "<git_tag_commit_or_branch>"
      UPDATE_COMMAND ""
      INSTALL_COMMAND "" )
ExternalProject_Add (  B ... )
ExternalProject_Add (  C ...  DEPENDS B )
ExternalProject_Add (  A ...  DEPENDS B C 
---------------
#if (MSVC)
#  target_compile_options(${PROJECT_NAME} PUBLIC "$<$<CONFIG:DEBUG>:/MTd>")
#  target_compile_options(${PROJECT_NAME} PUBLIC "$<$<CONFIG:RELEASE>:/MT>")
#endif()
# https://cmake.org/cmake/help/v3.16/prop_tgt/MSVC_RUNTIME_LIBRARY.html
#set_property(
#  TARGET ${PROJECT_NAME}
#  PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
#)

#set(VCPKG_TARGET_ARCHITECTURE x64)
#set(VCPKG_CRT_LINKAGE static)
#set(VCPKG_LIBRARY_LINKAGE static)


#set(GTEST_ROOT "$ENV{VCPKG_ROOT}\\packages\\gtest_x64-windows-static\\share\\gtest" CACHE PATH "Path to googletest")

Cache
set(MY_CACHE_VARIABLE "VALUE" CACHE STRING "Description")
CMakeCache.txt


target_include_directories(mylib PUBLIC include)
target_include_directories(mylib PRIVATE src)


include_directories is directory scope
target_include_directories is target scope

PUBLIC
PRIVATE
INTERFACE


target_link_libraries 

3.4+


add_executable
add_library

get_target_property
set_target_properties
get_property(TARGET)
set_property(TARGET)
target_compile_features
target_compile_options
target_link_libraries
target_sources

PRIVATE - non-INTERFACE_ 속성
INTERFACE - INTERFACE_ 속성
PUBLIC - 둘다


https://stackoverflow.com/questions/31969547/what-is-the-difference-between-include-directories-and-target-include-directorie
https://cmake.org/cmake/help/latest/command/target_include_directories.html

[CMake 할때 쪼오오금 도움이 되는 문서](https://gist.github.com/luncliff/6e2d4eb7ca29a0afd5b592f72b80cb5c)


[CppCon 2017: Mathieu Ropert “Using Modern CMake Patterns to Enforce a Good Modular Design”](https://www.youtube.com/watch?v=eC9-iRN2b04)
[C++Now 2017: Daniel Pfeifer “Effective CMake”](https://www.youtube.com/watch?v=bsXLMQ6WgIk)
[gist: Effective Modern CMake](https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1)

https://cliutils.gitlab.io/modern-cmake/
https://github.com/pr0g/cmake-examples


target_compile_options PRIVATE -Wall
PUBLIC과 INTERFACE용으로 넣지말것!

# DON'T USE
affect all targets
add_compiler_options
include_directories
ADD_DEFINITIONS
LINK_LIBRARIES

CMAKE_CXX_FLAGS 손대지 말것.

보류.. file(GLOB)
- https://stackoverflow.com/questions/1027247/is-it-better-to-specify-source-files-with-glob-or-each-file-individually-in-cmak/18538444
개발할때 빡심
CONFIGURE_DEPENDS는 하지않는 선에서


file(GLOB to_remove file_to_remove.cpp)
list(REMOVE_ITEM list ${to_remove})



-----------------

add_custom_command( 
    OUTPUT      src/simple.cpp              # <-- output path
    COMMAND     echo    "my first command"  # <-- command + args
)


if(WIN32)
    add_custom_command(
        OUTPUT      src/simple.cpp
        COMMAND     call ${CMAKE_CURRENT_SOURCE_DIR}/scripts/create_simple_cpp.sh 
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT     "creating simple.cpp"
    )
elseif(UNIX)
    add_custom_command(
        OUTPUT      src/simple.cpp
        COMMAND     bash ${CMAKE_CURRENT_SOURCE_DIR}/scripts/create_simple_cpp.sh 
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT     "creating simple.cpp"
    )
	
add_custom_target(get_index_html
    COMMAND curl -L "https://cmake.org/cmake/help/latest/" 
                -o "index.html"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)



find_package(fmt  5.3
CONFIG 
    REQUIRED
    PATHS       C:/vcpkg/installed/x64-windows
                /mnt/vcpkg/installed/x64-linux
)


find_package(Boost  1.59
CONFIG                      # <--- try without CONFIG if the function fails !
    REQUIRED
    COMPONENTS system thread timer
)

endif()






set_target_properties(my_modern_cpp_lib
PROPERTIES
    CXX_STANDARD 17
)



source_group
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" FILES ${HEADER_} ${SOURCE_})
https://cmake.org/cmake/help/v3.16/command/source_group.html



https://gitlab.kitware.com/cmake/community/wikis/doc/tutorials/How-to-create-a-ProjectConfig.cmake-file
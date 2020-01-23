cmake_minimum_required(VERSION 3.14.2)

project(
	lib_helloworld
	VERSION 1.0.0
	LANGUAGES CXX
)

file(GLOB_RECURSE public **.hpp)
file(GLOB_RECURSE private **.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${public} ${private})


add_library(${PROJECT_NAME} STATIC
    ${public}
    ${private}
)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
#add_library(lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_options(${PROJECT_NAME} PRIVATE /WX /Wall /utf-8)

target_compile_features(${PROJECT_NAME}	PRIVATE cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

set(CMAKE_INSTALL_PREFIX "C:/install")

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${public})

target_include_directories(${PROJECT_NAME}
	PUBLIC
	    $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
)

project(helloworld_lib VERSION 1.0.0 LANGUAGES CXX)

file(GLOB_RECURSE public **.hpp)
file(GLOB_RECURSE private **.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${public} ${private})

set(hello_DIR "C:/install/share/hello")
set(world_DIR "C:/install/share/world")

find_package(hello CONFIG REQUIRED)
find_package(world CONFIG REQUIRED)

add_library(${PROJECT_NAME}
	STATIC
	${public}
    ${private}
	#INTERFACE
	#world
)
target_compile_options(${PROJECT_NAME} PRIVATE /WX /Wall /utf-8)
target_compile_features(${PROJECT_NAME}	PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

add_library(lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})



set(CMAKE_INSTALL_PREFIX "C:/install")

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${public})

target_include_directories(${PROJECT_NAME}
	PUBLIC
	    $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$<BUILD_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
)
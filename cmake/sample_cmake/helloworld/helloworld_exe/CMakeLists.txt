project(helloworld_exe VERSION 1.0.0 LANGUAGES CXX)

file(GLOB_RECURSE public **.hpp)
file(GLOB_RECURSE private **.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${public} ${private})

add_executable(${PROJECT_NAME} ${public} ${private})

#target_link_libraries(${PROJECT_NAME} helloworld_lib)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(${PROJECT_NAME}	PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME} PRIVATE /WX /Wall /utf-8)




set(CMAKE_INSTALL_PREFIX "C:/install")
set(CMAKE_PREFIX_PATH "C:/install")
find_package(hello CONFIG REQUIRED)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
	    $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	lib::hello
	helloworld_lib
)
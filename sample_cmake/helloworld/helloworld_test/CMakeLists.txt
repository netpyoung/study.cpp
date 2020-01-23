project(helloworld_test
	LANGUAGES CXX)

set(GTest_ROOT "$ENV{VCPKG_ROOT}\\packages\\gtest_x64-windows\\share\\gtest")
find_package(GTest CONFIG REQUIRED)

file(GLOB_RECURSE public **.hpp)
file(GLOB_RECURSE private **.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${public} ${private})
add_executable(${PROJECT_NAME} ${public} ${private})

target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/../src"
)

set(CMAKE_INSTALL_PREFIX "C:/install")
set(CMAKE_PREFIX_PATH "C:/install")
find_package(hello CONFIG REQUIRED)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  lib::hello
  lib_helloworld
  GTest::gtest
  GTest::gtest_main
  GTest::gmock
  GTest::gmock_main
)

add_test(
  NAME ${PROJECT_NAME}
  COMMAND ${PROJECT_NAME}
)

if (BUILD_TEST)
	enable_testing()

	project(hello_test VERSION 1.0.0 LANGUAGES CXX)
	
	file(GLOB_RECURSE public **.hpp)
	file(GLOB_RECURSE private **.cpp)
	source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${public} ${private})


	set(GTest_ROOT "$ENV{VCPKG_ROOT}\\packages\\gtest_x64-windows\\share\\gtest")	
	find_package(GTest CONFIG REQUIRED)


	add_executable(${PROJECT_NAME} ${public} ${private})
	target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
	target_compile_features(${PROJECT_NAME}	PRIVATE cxx_std_17)
	set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

	target_include_directories(${PROJECT_NAME}
		PUBLIC
			$<INSTALL_INTERFACE:include>
			$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		PRIVATE
			"${CMAKE_CURRENT_SOURCE_DIR}/../hello"
	)

	target_link_libraries(
		${PROJECT_NAME}
		PRIVATE
		hello
		GTest::gtest
		GTest::gtest_main
		GTest::gmock
		GTest::gmock_main
	)

	add_test(
		NAME	${PROJECT_NAME}
		COMMAND	${PROJECT_NAME}
	)
endif (BUILD_TEST)
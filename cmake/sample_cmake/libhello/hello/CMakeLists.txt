project(hello VERSION 1.0.0 LANGUAGES CXX)

file(GLOB_RECURSE public **.hpp)
file(GLOB_RECURSE private **.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${public} ${private})

add_library(${PROJECT_NAME}
	STATIC
    ${public}
    ${private}
)
target_compile_options(${PROJECT_NAME} PRIVATE /WX /Wall /utf-8)
target_compile_features(${PROJECT_NAME}	PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

add_library(lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})



#set(CMAKE_INSTALL_PREFIX "C:/install")

#set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${public})

#target_include_directories(${PROJECT_NAME}
#	PUBLIC
#	    $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
#		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#	PRIVATE
#		${CMAKE_CURRENT_SOURCE_DIR}
#)

# ========================================================
# BUILD
# ========================================================
if (BUILD_INSTALL)
	set(CMAKE_INSTALL_PREFIX "C:/install")
	set(EXPORT_NAME ${PROJECT_NAME}-config)

	foreach(file ${public})
		get_filename_component(dir ${file} DIRECTORY)
		string(REPLACE ${CMAKE_CURRENT_SOURCE_DIR} "" dir ${dir})
		install(
			FILES 		${file}
			DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${dir}
			COMPONENT	Headers
		)
	endforeach()

	install(
		TARGETS						${PROJECT_NAME}
		DESTINATION 				${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}
		EXPORT						${EXPORT_NAME}
	)

	install(
		EXPORT          ${EXPORT_NAME}
		NAMESPACE       lib::
		DESTINATION     ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}
	)

	include(CMakePackageConfigHelpers)
	set(VERSION_FILE_PATH   ${CMAKE_BINARY_DIR}/cmake/${PROJECT_NAME}-config-version.cmake)

	write_basic_package_version_file(
		${VERSION_FILE_PATH}
		VERSION             ${PROJECT_VERSION} # x.y.z
		COMPATIBILITY       SameMajorVersion
	)

	install(
		FILES           ${VERSION_FILE_PATH} 
		DESTINATION     ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}
	)
endif (BUILD_INSTALL)

cmake_minimum_required(VERSION 3.0)

project(ArtVis C CXX)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Binaries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Binaries)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Binaries)
set_property(GLOBAL PROPERTY USE_FOLDERS OFF)


if(MSVC)
	add_compile_options(
		"$<$<CONFIG:Debug>:/MDd>"
		"$<$<CONFIG:RelWithDebInfo>:/MD>"
		"$<$<CONFIG:Release>:/MD>"
		"$<$<CONFIG:MinSizeRel>:/MD>"
	)
endif()


set(Qt5_DIR "C:\\Qt\\5.13.0\\msvc2017_64\\lib\\cmake\\Qt5")
find_package(Qt5 COMPONENTS Core Widgets 3DCore 3DInput 3DLogic 3DRender Network REQUIRED)

if(WIN32)
	add_compile_definitions(ARTVIS_WIN32)
endif()

add_subdirectory(Source)
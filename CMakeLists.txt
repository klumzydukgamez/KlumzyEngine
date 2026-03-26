# This file is apart of KlumzyEngine and is property of Klumzy Duk Gamez
# Copyright (c) 2026 Klumzy Duk Gamez
# See LICENSE.md for license details

cmake_minimum_required(VERSION 3.20)

project(KlumzyEngine)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
execute_process(
	COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}")

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Include")
set(VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Vendor")

find_package(OpenGL REQUIRED COMPONENTS OpenGL)

# Library
file(GLOB_RECURSE Library_SOURCES 
	"${SOURCE_DIR}/**/*.cpp" "${SOURCE_DIR}/*.cpp"
	"${SOURCE_DIR}/**/*.c" "${SOURCE_DIR}/*.c"
)
list(FILTER Library_SOURCES EXCLUDE REGEX "^${SOURCE_DIR}/Editor/.*")

add_library(Library SHARED ${Library_SOURCES})
target_compile_definitions(Library PRIVATE
	KLUMZY_EXPORT_DLL
)
target_compile_options(Library PRIVATE
	-g -O0
)
target_include_directories(Library PRIVATE
	${INCLUDE_DIR}
)
target_link_libraries(Library PRIVATE
	${OPENGL_LIBRARIES}
)
set_target_properties(Library PROPERTIES
	OUTPUT_NAME "KlumzyEngine"
)

install(
	FILES $<TARGET_FILE:Library>
	DESTINATION Bin
)

# Editor
file(GLOB_RECURSE Editor_SOURCES 
	"${SOURCE_DIR}/Editor/**/*.cpp" "${SOURCE_DIR}/Editor/*.cpp"
	"${SOURCE_DIR}/Editor/**/*.c" "${SOURCE_DIR}/Editor/*.c"
)

add_executable(Editor ${Editor_SOURCES})
target_compile_options(Editor PRIVATE
	-g -O0
)
target_include_directories(Editor PRIVATE
	${INCLUDE_DIR}
)
target_link_libraries(Editor PRIVATE
	Library
)
set_target_properties(Editor PROPERTIES
	OUTPUT_NAME "KlumzyEditor"
)

install(
	FILES $<TARGET_FILE:Editor>
	DESTINATION Bin
)

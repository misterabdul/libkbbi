cmake_minimum_required(VERSION 3.9)

# Project description
project(
	libkbbi
	VERSION 0.0.1
	DESCRIPTION "Library containing KBBI data."
)

# Custom definitions
set(LIB_NAME kbbi)
set(LIB_SO_VERSION 0)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Targets
add_library(
	${LIB_NAME}
	SHARED
	src/libkbbi.c
	src/kbbi_data.c
)

# Properties
set_target_properties(
	${LIB_NAME} PROPERTIES
	VERSION ${PROJECT_VERSION}
	SOVERSION ${LIB_SO_VERSION}
	PUBLIC_HEADER inc/libkbbi.h
)

# Includes
target_include_directories(
	${LIB_NAME}
	PRIVATE inc
	PRIVATE src
)

# Use GNU Installation Standard
include(GNUInstallDirs)

# Declare file to install
install(
	TARGETS ${LIB_NAME}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/libkbbi
)

# Expand .pc file
configure_file(
	libkbbi.pc.in
	libkbbi.pc
	@ONLY
)

# Expand uninstall script
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
    IMMEDIATE @ONLY
)

# Install the file
install(
	FILES ${CMAKE_BINARY_DIR}/libkbbi.pc
	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)

# Add uninstall target
add_custom_target(
	uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake
)

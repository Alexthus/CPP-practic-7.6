cmake_minimum_required(VERSION 3.18)      
project(    
    Matrix
    VERSION 0.0.1
    DESCRIPTION "Dynamic library"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
 
include(GenerateExportHeader)

set(sources                               
    matrixlib/matrix.h
    matrixlib/matrix.cpp

    matrixlib/export.h
    matrixlib/c/c_api.h
    matrixlib/c/c_api.cpp
)

add_library(static-matrixlib STATIC ${sources})

target_include_directories(static-matrixlib 
    PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

set_target_properties(static-matrixlib PROPERTIES PREFIX "")

generate_export_header(
    static-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_static.h"
    BASE_NAME matrixlib
)

add_library(shared-matrixlib SHARED ${sources})

target_include_directories(shared-matrixlib 
    PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

set_target_properties(shared-matrixlib PROPERTIES PREFIX "")

generate_export_header(
    shared-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrixlib
)
cmake_minimum_required(VERSION 3.1.0)
project("proj1")

#SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE} CACHE PATH "Executable output path")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

add_executable(proj1
        WoodCommon.hpp
        WoodItem.hpp
        WoodItem.cpp
        WoodOrder.hpp
        WoodOrder.cpp
        WoodOrderDetail.hpp
        WoodOrderDetail.cpp
        WoodOrderManager.hpp
        WoodOrderManager.cpp
        main.cpp)

file(COPY input.txt DESTINATION ${CMAKE_BINARY_DIR})

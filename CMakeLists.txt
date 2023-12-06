cmake_minimum_required(VERSION 3.22)

project(dummy-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(dummy-cpp)

target_sources(dummy-cpp PRIVATE 
	main.cc
)

find_package(Boost QUIET REQUIRED COMPONENTS program_options)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()

target_link_libraries(dummy-cpp PUBLIC
    Boost::program_options
)
cmake_minimum_required (VERSION 3.22)

#####################################
# DEPENDENCY CONFIG                 #
#####################################

find_package(Boost QUIET REQUIRED COMPONENTS program_options)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()

#####################################
# TARGET DEFINITION                 #
#####################################

add_library (dummy-cpp-core)

set_target_properties(dummy-cpp-core
    PROPERTIES
    OUTPUT_NAME dummy-cpp
    VERSION ${PROJECT_VERSION}
)

target_sources(dummy-cpp-core PRIVATE 
    Data.cc
    InputDTO.cc
    OutputDTO.cc
)

target_include_directories (dummy-cpp-core
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries (dummy-cpp-core
    PUBLIC
    Boost::program_options
)

install (TARGETS dummy-cpp-core EXPORT dummy-cpp-export
    RUNTIME_DEPENDENCY_SET dummy-cpp-dependencies
)


include (GNUInstallDirs)

install (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hh"
)

add_library (${PROJECT_NAME}::dummy-cpp-core ALIAS dummy-cpp-core)
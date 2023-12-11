cmake_minimum_required (VERSION 3.22)

#####################################
# TARGET DEFINITION                 #
#####################################

add_executable (dummy-cpp-exe)

set_target_properties(dummy-cpp-exe
    PROPERTIES
    OUTPUT_NAME dummy-cpp
)

target_sources(dummy-cpp-exe PRIVATE 
    main.cc
)

target_include_directories (dummy-cpp-exe
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries (dummy-cpp-exe
    PUBLIC
    ${PROJECT_NAME}::dummy-cpp-core
)

install (TARGETS dummy-cpp-exe EXPORT dummy-cpp-export
    RUNTIME_DEPENDENCY_SET dummy-cpp-dependencies
)

add_executable (${PROJECT_NAME}::dummy-cpp-exe ALIAS dummy-cpp-exe)
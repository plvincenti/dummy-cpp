cmake_minimum_required (VERSION 3.22)

#####################################
# PROJECT CONFIG                    #
#####################################

project (dummy-cpp VERSION 1.0.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED True)
set (CMAKE_CXX_EXTENSIONS OFF)


#####################################
# TARGET DEFINITION                 #
#####################################

add_subdirectory (src)

#####################################
# INSTALL CONFIG                    #
#####################################

include (GNUInstallDirs)

install (RUNTIME_DEPENDENCY_SET dummy-cpp-dependencies)

list( APPEND CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_LIBDIR} )
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# CMAKE CONFIG INSTALLATION

set (ConfigPackageLocation "share/cmake/dummy-cpp-${PROJECT_VERSION}")
include (CMakePackageConfigHelpers)

write_basic_package_version_file ("${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

configure_package_config_file (cmake/${PROJECT_NAME}-config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}-config.cmake"
    INSTALL_DESTINATION "${ConfigPackageLocation}"
    NO_SET_AND_CHECK_MACRO)

install (EXPORT ${PROJECT_NAME}-export
    FILE ${PROJECT_NAME}-target.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION "${ConfigPackageLocation}")


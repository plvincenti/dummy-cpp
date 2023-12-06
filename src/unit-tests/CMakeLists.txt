cmake_minimum_required (VERSION 3.22)

find_package (Boost REQUIRED COMPONENTS unit_test_framework)

add_executable (unit-tests)

target_sources (unit-tests
    PRIVATE
    main.cc
    DummyTST.cc
)

target_link_libraries (unit-tests
    PRIVATE
    Boost::unit_test_framework
)

file (MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/tests-reports)

add_custom_target (run_unit_tests)

add_custom_command (OUTPUT ${CMAKE_BINARY_DIR}/tests-reports/unit_tests.xml
    COMMAND unit-tests --log_level=all
    DEPENDS unit-tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests-reports
)
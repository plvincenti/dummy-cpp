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

add_custom_target (run_unit_tests
    DEPENDS ${CMAKE_BINARY_DIR}/tests-reports/unit_tests.xml
    COMMENT "Run unit tests"
)

add_custom_command (OUTPUT ${CMAKE_BINARY_DIR}/tests-reports/unit_tests.xml
    COMMAND $<TARGET_FILE:unit-tests> --log_level=error --report_level=short --log_format=HRF
    DEPENDS unit-tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests-reports 
)
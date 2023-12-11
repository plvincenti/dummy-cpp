target_sources (unit-tests
    PRIVATE
    DataTST.cc
)

target_link_libraries (unit-tests
    PRIVATE
    ${PROJECT_NAME}::dummy-cpp-core
)
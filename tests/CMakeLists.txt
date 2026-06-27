# Optimise for test-only native/unit-test builds
if(BUILD_MODE STREQUAL "esp32")
    message(FATAL_ERROR
        "tests/CMakeLists.txt must not be included for BUILD_MODE=esp32. "
        "Use 'native' build mode for unit tests instead.")
endif()

find_package(GTest REQUIRED)

# Automatically collect test sources to avoid keeping this list in sync
# with reality. CONFIGURE_DEPENDS ensures fresh runs re-scan on changes.
file(GLOB_RECURSE _test_sources
    CONFIGURE_DEPENDS
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    *.cpp
    *.cc
    *.cxx
)

add_executable(rover_tests ${_test_sources})

target_link_libraries(rover_tests
    PRIVATE
        rover_core
        rover_mock
        GTest::gtest_main
)

target_include_directories(rover_tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Make CTest (ctest) aware of every GoogleTest test case
include(GoogleTest)
gtest_discover_tests(rover_tests)

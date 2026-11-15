include(FetchContent)
FetchContent_Declare(
    googletest
    url https://github.com/google/googletest/archive/refs/tags/v1 14.0.zip

)

fetchContent_MakeAvailable(googletest)


enable_testing()
add_executable(raft_tests tests/test_clock.cpp tests/test_queue.cpp tests/test_elecion.cpp tests)
target_link_libraries(raft_test PRIVATE raft_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(raft_tests)

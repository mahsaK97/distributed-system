include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v114.0.zip

)

fetchContent_MakeAvailable(googletest)


enable_testing()
add_executable(raft_test tests/test_clock.cpp tests/test_queue.cpp tests/test_election.cpp tests)
target_link_libraries(raft_test PRIVATE raft_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(raft_test)

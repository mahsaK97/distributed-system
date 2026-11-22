cmake_minimum_required(VERSION 3.20)
project(distributed_system LANGUAGE CXX)



include(FetchContent)
fetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip

)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

fetchContent_MakeAvailable(googletest)


enable_testing()
add_executable(raft_test 
tests/test_clock.cpp 
tests/test_queue.cpp 
tests/test_election.cpp)
target_link_libraries(
    raft_test 
    PRIVATE 
    raft_core 
    GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(raft_test)

add_library(raft
RAftNode.cpp
RaftLog.cpp)

target_include_directories(raft
PUBLIC
${PROJECT_SOURCE_DIR} /include)

target_link_libraries(raft
PUBLIC
node
protocol
network)

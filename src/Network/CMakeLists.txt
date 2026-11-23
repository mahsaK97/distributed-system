add_library(Network 
TcpClient.cpp
TcpServer.cpp)


target_include_directories(network
PUBLIC
${PROJECT_BINARY_DIR}/include)

find_package(Threads REQUIRED)

target_link_libraries(network
PUBLIC
threads::threads)


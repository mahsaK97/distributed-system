add_subdirectory(Node)
add_subdirectory(protocol)
add_subdirectory(Network)
add_subdirectory(Raft)


add_executable(distributed_sysytem
PRIVATE
node
protocol
network
reft
) 
add_library(node
Node.cpp
StateMachine.cpp
VirtualClock.cpp
)

terget_include_directories(node
PUBLIC
${PROJRCT_SOURCE_DIR}/include)
# 指定链接目录
link_directories(${CMAKE_BINARY_DIR}/proto)

# 包含生成的*.pb.h文件的目录
include_directories(${CMAKE_BINARY_DIR}/proto)

# 定义客户端和服务端可执行文件
add_executable(client client.cpp)
add_executable(server server.cpp)

# 添加链接库
target_link_libraries(client message ${PROTOBUF_LIBRARIES})
target_link_libraries(server message ${PROTOBUF_LIBRARIES})

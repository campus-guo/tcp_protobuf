cmake_minimum_required(VERSION 3.12)

# 在build目录中运行protoc命令
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS message.proto)
###这样也可以直接生成protoc --cpp_out=. message.proto

# 创建protobuf生成的源文件的库
add_library(message ${PROTO_SRCS} ${PROTO_HDRS})

# 包含protobuf包含目录
target_include_directories(message PUBLIC ${PROTOBUF_INCLUDE_DIR})

# 链接protobuf库
target_link_libraries(message ${PROTOBUF_LIBRARY})

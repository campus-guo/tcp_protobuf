cmake_minimum_required(VERSION 3.12)
project(tcp_protobuf_test)

set(CMAKE_CXX_STANDARD 11)

# 查找 protobuf，确保系统已经安装protobuf库和编译器
find_package(Protobuf REQUIRED)

# 包含子目录
add_subdirectory(proto)
add_subdirectory(src)
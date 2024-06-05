#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "message.pb.h"

int main() {
    // 初始化socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 定义服务器地址
    struct sockaddr_in address{};
    address.sin_family = AF_INET; // 使用IPv4
    address.sin_addr.s_addr = INADDR_ANY; // 监听任何IP地址
    address.sin_port = htons(12345); // 设置端口号

    // 绑定socket到服务器地址
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // 监听socket，最多允许3个等待连接的队列
    listen(server_fd, 3);

    // 接收连接
    int addrlen = sizeof(address);
    int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

    // 接收数据
    char buffer[1024] = {0};
    read(new_socket, buffer, 1024);

    // 反序列化protobuf消息
    demo::MyMessage msg;
    msg.ParseFromArray(buffer, 1024);

    // 打印消息内容
    std::cout << "Received message: " << msg.id() << " - " << msg.content() << std::endl;

    // 关闭socket
    close(new_socket);
    close(server_fd);

    return 0;
}

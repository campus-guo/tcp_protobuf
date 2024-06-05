#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "message.pb.h"

int main() {
    // 创建socket
    int sock = 0;
    struct sockaddr_in serv_addr{};
    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET; // 使用IPv4
    serv_addr.sin_port = htons(12345); // 设置服务器端口

    // 将IPv4地址从文本转换为二进制形式，并设置服务器IP,这里是本地地址
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // 连接到服务器
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // 创建protobuf消息
    demo::MyMessage msg;
    //这里是自己定义的变量叫id，所以才set_id，如果定义的叫image，这里就是set_image
    msg.set_id(1);
    //这里跟上面同理，但是要注意每个message里面的标签编号必须是一致的
    msg.set_content("Hello from client!");

    // 序列化消息到字符串
    std::string serialized;
    msg.SerializeToString(&serialized);

    // 发送消息
    send(sock, serialized.c_str(), serialized.size(), 0);

    // 关闭socket
    close(sock);

    return 0;
}

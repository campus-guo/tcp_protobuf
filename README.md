# TCP 和 Protocol Buffers 进程间通信示例  -- campus

本项目演示了如何在C++中使用TCP套接字和Protocol Buffers进行简单的客户端-服务器通信。

## 前提条件

在开始之前，请确保你已经满足以下要求：

- 你已经安装了支持C++11的C++编译器，例如`g++`。
- 你已经安装了[CMake](https://cmake.org/download/)（3.12或更高版本）。
- 你已经安装了[Protocol Buffers 编译器 (protoc)](https://grpc.io/docs/protoc-installation/)。

## 环境配置

1. 安装 g++ 和 make （Linux）：

    ```sh
    sudo apt-get update
    sudo apt-get install build-essential
    ```

2. 安装 CMake：

    - 在 Ubuntu 上：

        ```sh
        sudo apt-get install cmake
        ```

    - 或者，按照[官方 CMake 网站](https://cmake.org/download/)上的指南进行安装。

3. 安装 Protocol Buffers 编译器：

    - 在 Ubuntu 上：

        ```sh
        sudo apt-get install protobuf-compiler
        sudo apt-get install libprotobuf-dev
        ```

    - 对于其他平台，请按照[gRPC 网站上的安装指南](https://grpc.io/docs/protoc-installation/)进行操作。

## 构建项目

按照以下步骤构建项目：

1. 克隆仓库：

    ```sh
    git clone https://github.com/yourusername/tcp_protobuf_demo.git
    cd tcp_protobuf_demo
    ```

2. 创建并进入构建目录：

    ```sh
    mkdir build && cd build
    ```

3. 运行 CMake 生成 Makefile：

    ```sh
    cmake ..
    ```

4. 编译代码：

    ```sh
    make
    ```

完成这些命令后，在`build/src`目录下应该生成了`client`和`server`两个可执行文件。

## 运行应用程序

要运行服务器和客户端应用程序，请打开两个终端窗口。

在第一个终端中，启动服务器：

```sh
./build/src/server
```

在第二个终端中，执行客户端：
```sh
./build/src/client
```
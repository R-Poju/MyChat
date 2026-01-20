基于Qt，采用C++开发的全栈聊天室项目



**本次更新：**

优化了ChatServer和Client的代码逻辑。优化后，逻辑更清晰，代码更规范



**项目描述:**

这是一个全栈的即时通讯项目，前端基于QT实现气泡聊天对话框，通过QListWidget实现好友列表，利用GridLayout和QPainter封装气泡聊天框组件，基于QT network模块封装http和tcp服务。支持添加好友，好友通信，聊天记录展示等功能，仿微信布局并使用qss优化界面

后端采用分布式设计，分为GateServer网关服务，多个ChatServer聊天服务，StatusServer状态服务以及VerifyServer验证服务。

各服务通过grpc通信，支持断线重连。GateServer网关对外采用http服务，负责处理用户登录和注册功能。登录时GateServer从StatusServer查询聊天服务达到负载均衡，ChatServer聊天服务采用asio实现tcp可靠长链接异步通信和转发, 采用多线程模式封装iocontext池提升并发性能。数据存储采用mysql服务，并基于mysqlconnector库封装连接池，同时封装redis连接池处理缓存数据，以及grpc连接池保证多服务并发访问。

经测试单服务器支持8000连接，多服务器分布部署可支持1W~2W活跃用户。



**业务概览：**

使用BoostAsio搭建高性能异步网络通信模块，支持客户端与服务端长连接通信

构建网关服务，负责接收登录/注册请求并通过gRPC协调各子服务，内部异步逻辑基于Asio线程实现

开发验证服务，基于Node.js实现邮件验证码发送功能，结合Redis设置过期校验机制

构建状态服务，实时收集各聊天服务负载，基于gRPC长连接智能路由分发请求

实现聊天服务，支持用户实时收发信息，管理会话状态

开发Qt客户端，集成注册/登录/好友管理/实时聊天功能


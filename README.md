基于Qt，采用C++开发的全栈聊天室项目

类似桌面版微信



Qt客户端，负责收发验证码，实现用户的注册、重置密码及登录验证服务

StatusServer服务器，负责token验证



新增ChatServer聊天服务器，接收来自客户端的连接，并实现发送接收数据，由StatusServer分配给客户端

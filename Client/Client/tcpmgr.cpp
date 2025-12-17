#include "tcpmgr.h"

TcpMgr::TcpMgr(): _host(""), _port(0), _b_recv_pending(false), _message_id(0), _message_len(0)
{
    //接下来连接网络请求的信号
    QObject::connect(&_socket, &QTcpSocket::connected, [&](){
        qDebug() << "Connected to server!";
        //建立连接后发送信号
        emit sig_con_success(true);
    });

    QObject::connect(&_socket, &QTcpSocket::readyRead, [&](){
        //当有数据可读时，读取所有数据并追加到缓冲区
        _buffer.append(_socket.readAll());
        QDataStream stream(&_buffer, QIODevice::ReadOnly);
        stream.setVersion(QDataStream::Qt_5_14);

        forever{
            //先解析头部数据
            if(!_b_recv_pending){
                //检查缓冲区中的数据是否足够解析出一个消息头（消息ID + 消息长度）
                if(_buffer.size() < static_cast<int>(sizeof(quint16) * 2)){
                    return;//数据不够，等待更多数据
                }

                //预读取消息ID和消息长度，但不从缓冲区中移除
                stream >> _message_id >> _message_len;

                //将buffer中的前四个字节移除
                _buffer = _buffer.mid(sizeof(quint16) * 2);

                //输出读取的数据
                qDebug() << "Message ID:" << _message_id << ", Length:" << _message_len;

            }

            //判断buffer剩余长度是否满足消息体长度，不满足则退出并继续等待接收新的数据

            if(_buffer.size() < _message_len){
                _b_recv_pending = true;
                return;
            }

            _b_recv_pending = false;
            //读取消息体
            QByteArray messageBody = _buffer.mid(0, _message_len);
            qDebug() << "receive body msg is " << messageBody;

            _buffer = _buffer.mid(_message_len);
        }
    });

    //处理错误
    QObject::connect(&_socket, static_cast<void (QTcpSocket::*)(QTcpSocket::SocketError)>(&QTcpSocket::error),
                     [&](QTcpSocket::SocketError socketError){
        qDebug() << "Error:" << _socket.errorString();
        switch(socketError){
            case QTcpSocket::ConnectionRefusedError:
                qDebug() << "Connection Refused!";
                emit sig_con_success(false);
                break;
            case QTcpSocket::RemoteHostClosedError:
                qDebug() << "Remote Host Closed Connection!";
                break;
            case QTcpSocket::HostNotFoundError:
                qDebug() << "Host Not Found!";
                emit sig_con_success(false);
                break;
            case QTcpSocket::SocketTimeoutError:
                qDebug() << "Connection Timeout!";
                emit sig_con_success(false);
                break;
            case QTcpSocket::NetworkError:
                qDebug() << "Network Error!";
                break;
            default:
                qDebug() << "Other Error!";
                break;
        }
    });

    //处理连接断开
    QObject::connect(&_socket, &QTcpSocket::disconnected, [&](){
        qDebug() << "Disconnected from server.";
    });

    QObject::connect(this, &TcpMgr::sig_send_data, this, &TcpMgr::slot_send_data);
}

void TcpMgr::slot_tcp_connect(ServerInfo si)
{
    qDebug() << "receive tcp connect signal";
    //尝试连接到服务器
    qDebug() << "Connecting to server...";
    _host = si.Host;
    _port = static_cast<uint16_t>(si.Port.toUInt());
    _socket.connectToHost(si.Host, _port);
}

//客户端发送数据这一行为，可能发生在任何线程中。为了保证线程安全，我们在发送数据时，发送TcpMgr的sig_send_data信号，并实现槽函数
void TcpMgr::slot_send_data(ReqId reqId, QString data)
{
    uint16_t id = reqId;

    //将字符串转换为UTF-8编码的字节数组
    QByteArray dataBytes = data.toUtf8();

    //计算长度（使用网络字节序转换）
    quint16 len = static_cast<quint16>(data.size());

    //创建一个QByteArray用于存储要发送的所有数据
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    //设置数据流，使用网络字节序
    out.setByteOrder(QDataStream::BigEndian);

    //写入ID和长度
    out << id << len;

    //添加字符串数据
    block.append(data);

    //发送数据
    _socket.write(block);
}































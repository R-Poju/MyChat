#ifndef USERMGR_H
#define USERMGR_H

#include <QObject>
#include <memory>
#include <singleton.h>

class UserMgr :public QObject, public Singleton<UserMgr>,
        public std::enable_shared_from_this<UserMgr>
{
    Q_OBJECT
public:
    friend class Singleton<UserMgr>;
    ~UserMgr();
    void SetName(QString name);
    void SetToken(QString token);
    void SetUid(int uid);

private:
    UserMgr();
    QString _name;
    QString _token;
    int _uid;
};

#endif // USERMGR_H






































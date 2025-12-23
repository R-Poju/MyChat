#include "usermgr.h"

UserMgr::~UserMgr()
{

}

void UserMgr::SetName(QString name)
{
    _name = name;
}

void UserMgr::SetToken(QString token)
{
    _token = token;
}

void UserMgr::SetUid(int uid)
{
    _uid = uid;
}

UserMgr::UserMgr()
{

}

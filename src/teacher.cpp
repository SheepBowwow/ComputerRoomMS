#include "teacher.h"
using namespace std;

//无参构造
Teacher::Teacher()
{
    
}

//有参构造
Teacher::Teacher(int id, const string &name, const string &pwd)
{

}

//菜单界面
void Teacher::openMenu()
{

}

//查看所有预约
void Teacher::showAllOrder()
{

}

//审核预约
void Teacher::vaildOrder()
{

}

//获取 id
const int& Teacher::getID() const
{
    return t_id;
}

//获取学生姓名
const string& Teacher::getName() const 
{
    return u_Name;
}

//获取学生密码
const string& Teacher::getPwd() const 
{
    return u_Pwd;
}

//设置 id
void Teacher::setID(const int &id)
{
    t_id = id;
}

//设置 name
void Teacher::setName(const string &name)
{
    u_Name = name;
}

//设置 pwd
void Teacher::setPwd(const string &pwd)
{
    u_Pwd = pwd;
}
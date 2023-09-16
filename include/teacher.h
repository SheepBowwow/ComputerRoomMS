#ifndef TEACHER_H
#define TEACHER_H

#include "identity.h"

class Teacher : public Identity
{
public:
    //无参构造
    Teacher();

    //有参构造
    Teacher(int id, const string &name, const string &pwd);

    //菜单界面
    virtual void openMenu();

    //查看所有预约
    void showAllOrder();

    //审核预约
    void vaildOrder();

    //获取 id
    const int &getID() const;

    //获取姓名
    const string &getName() const;
    
    //获取密码
    const string &getPwd() const;

    //设置 id
    void setID(const int &id);

    //设置 name
    void setName(const string &name);

    //设置 pwd
    void setPwd(const string &pwd);

    //重载==
    bool operator==(const Teacher &other) const {return other.getID() == t_id;}

private:
    int t_id;
};

#endif
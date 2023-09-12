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

    //设置 id
    void setID(const int &id);
    
private:
    int t_id;
};

#endif
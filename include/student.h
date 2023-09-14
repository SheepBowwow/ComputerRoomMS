#ifndef STUDENT_H
#define STUDENT_H

#include "identity.h"

class Student : public Identity
{
public:
    //默认构造
    Student();

    //有参构造
    Student(int id, string name, string pwd);

    //菜单
    virtual void openMenu();

    //申请预约
    void applyOrder();

    //查看我的预约
    void showMyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    //获取 id
    const int &getID() const;

    //设置 id
    void setID(const int &id);

private:
    int s_id;
};

#endif
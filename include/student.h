#ifndef STUDENT_H
#define STUDENT_H

#include "identity.h"
#include "computerRoom.h"
#include <vector>

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

    const string &getName() const;

    const string &getPwd() const;

    //设置 id
    void setID(const int &id);

    //设置 name
    void setName(const string &name);

    //设置 pwd
    void setPwd(const string &pwd);

    //初始化容器,读取文件中的账号
	void initVector();

    //用到find函数，重载operator==
    bool operator==(const Student &other) const {return other.getID() == s_id;}

private:
    int s_id;
    
    //机房容器
	vector<ComputerRoom> vCom;
};

#endif
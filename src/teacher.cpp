#include "teacher.h"
using namespace std;

//�޲ι���
Teacher::Teacher()
{
    
}

//�вι���
Teacher::Teacher(int id, const string &name, const string &pwd)
{

}

//�˵�����
void Teacher::openMenu()
{

}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{

}

//���ԤԼ
void Teacher::vaildOrder()
{

}

//��ȡ id
const int& Teacher::getID() const
{
    return t_id;
}

//��ȡѧ������
const string& Teacher::getName() const 
{
    return u_Name;
}

//��ȡѧ������
const string& Teacher::getPwd() const 
{
    return u_Pwd;
}

//���� id
void Teacher::setID(const int &id)
{
    t_id = id;
}

//���� name
void Teacher::setName(const string &name)
{
    u_Name = name;
}

//���� pwd
void Teacher::setPwd(const string &pwd)
{
    u_Pwd = pwd;
}
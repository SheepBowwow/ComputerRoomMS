#ifndef STUDENT_H
#define STUDENT_H

#include "identity.h"
#include "computerRoom.h"
#include <vector>

class Student : public Identity
{
public:
    //Ĭ�Ϲ���
    Student();

    //�вι���
    Student(int id, string name, string pwd);

    //�˵�
    virtual void openMenu();

    //����ԤԼ
    void applyOrder();

    //�鿴�ҵ�ԤԼ
    void showMyOrder();

    //�鿴����ԤԼ
    void showAllOrder();

    //ȡ��ԤԼ
    void cancelOrder();

    //��ȡ id
    const int &getID() const;

    const string &getName() const;

    const string &getPwd() const;

    //���� id
    void setID(const int &id);

    //���� name
    void setName(const string &name);

    //���� pwd
    void setPwd(const string &pwd);

    //��ʼ������,��ȡ�ļ��е��˺�
	void initVector();

    //�õ�find����������operator==
    bool operator==(const Student &other) const {return other.getID() == s_id;}

private:
    int s_id;
    
    //��������
	vector<ComputerRoom> vCom;
};

#endif
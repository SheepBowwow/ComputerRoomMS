#ifndef STUDENT_H
#define STUDENT_H

#include "identity.h"

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

    //���� id
    void setID(const int &id);

private:
    int s_id;
};

#endif
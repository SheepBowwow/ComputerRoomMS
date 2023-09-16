#ifndef TEACHER_H
#define TEACHER_H

#include "identity.h"

class Teacher : public Identity
{
public:
    //�޲ι���
    Teacher();

    //�вι���
    Teacher(int id, const string &name, const string &pwd);

    //�˵�����
    virtual void openMenu();

    //�鿴����ԤԼ
    void showAllOrder();

    //���ԤԼ
    void vaildOrder();

    //��ȡ id
    const int &getID() const;

    //��ȡ����
    const string &getName() const;
    
    //��ȡ����
    const string &getPwd() const;

    //���� id
    void setID(const int &id);

    //���� name
    void setName(const string &name);

    //���� pwd
    void setPwd(const string &pwd);

    //����==
    bool operator==(const Teacher &other) const {return other.getID() == t_id;}

private:
    int t_id;
};

#endif
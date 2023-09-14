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

    //���� id
    void setID(const int &id);
    
private:
    int t_id;
};

#endif
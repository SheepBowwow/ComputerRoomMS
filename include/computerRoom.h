#ifndef COMPUTER_ROOM_H
#define COMPUTER_ROOM_H

#include<iostream>
using namespace std;
//������
class ComputerRoom
{
public:
    // ��ȡid
    const int &getID() const;

    // ��ȡ�����������
    const int &getNum() const;

    // ����id
    void setID(const int &id);

    // ���û����������
    void setMaxNum(const int &num);

private:
    int c_id; // ����id��

    int c_maxNum; // �����������   
};


#endif
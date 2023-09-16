#ifndef COMPUTER_ROOM_H
#define COMPUTER_ROOM_H

#include<iostream>
using namespace std;
//机房类
class ComputerRoom
{
public:
    // 获取id
    const int &getID() const;

    // 获取机房最大容量
    const int &getNum() const;

    // 设置id
    void setID(const int &id);

    // 设置机房最大容量
    void setMaxNum(const int &num);

private:
    int c_id; // 机房id号

    int c_maxNum; // 机房最大容量   
};


#endif
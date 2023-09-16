#include "computerRoom.h"

const int &ComputerRoom::getID() const
{
    return c_id;
}

const int &ComputerRoom::getNum() const
{
    return c_maxNum;
}

void ComputerRoom::setID(const int &id)
{
    c_id = id;
}

void ComputerRoom::setMaxNum(const int &num)
{
    c_maxNum = num;
}

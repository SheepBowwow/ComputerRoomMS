#ifndef  IDENTITY_H
#define IDENTITY_H

#include <iostream>
using namespace std;

class Identity
{
public:
    virtual void openMenu() = 0;
    
protected:
    string u_Name;
    string u_Pwd;
};

#endif
#include "manager.h"
#include "globalConstant.h"
using namespace std;

//默认构造
Manager::Manager()
{
}

//有参构造
Manager::Manager(string name, string pwd)
{
    u_Name = name;
    u_Pwd = pwd;
}

//选择菜单
void Manager::openMenu()
{
    printf("\n");
    cout << "--------------   机房管理系统(管理员)   --------------" << endl;
    cout << "                   1. 添加账号" << endl;
    cout << "                   2. 查看账号" << endl;
    cout << "                   3. 查看机房" << endl;
    cout << "                   4. 清空预约" << endl;
    cout << "                   0. 注销登录" << endl;
}

//添加账号  
void Manager::addPerson()
{
}

//查看账号
void Manager::showPerson()
{
}

//查看机房信息
void Manager::showComputer()
{
}

//清空预约记录
void Manager::cleanFile()
{
}
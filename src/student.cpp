#include "student.h"
#include <fstream>
#include "globalConstant.h"
#include "computerRoom.h"
#include <algorithm>
using namespace std;

void s_printComputer(ComputerRoom &c);

// 无参构造
Student::Student()
{
}

// 有参构造
Student::Student(int id, string name, string pwd)
{
    this->s_id = id;
    u_Name = name;
    u_Pwd = pwd;

    this->initVector();
}

// 菜单选择
void Student::openMenu()
{
    printf("\n");
    cout << "--------------   机房管理系统(管理员)   --------------" << endl;
    cout << "                   1. 申请预约" << endl;
    cout << "                   2. 查看我的预约" << endl;
    cout << "                   3. 查看所有预约" << endl;
    cout << "                   4. 取消预约" << endl;
    cout << "                   0. 注销登录" << endl;
}

// 申请预约
void Student::applyOrder()
{
    int date = 0;     // 周一 ~ 周五
    int interval = 0; // 预约时间段
    int room = 0;     // 机房

    // 选择时间
    while (true)
    {
        system("cls");
        printf("\n");
        cout << "--------------   上机预约(时间)   --------------" << endl;
        cout << "                   1. 周一" << endl;
        cout << "                   2. 周二" << endl;
        cout << "                   3. 周三" << endl;
        cout << "                   4. 周四" << endl;
        cout << "                   5. 周五" << endl;
        cout << "请选择预约时间: " << endl;
        cin >> date;
        if (date >= 1 && date <= 5)
            break;
        cout << "输入有误,请重新输入" << endl;
        my_sleep(1);
    }

    // 选择时间段
    while (true)
    {
        system("cls");
        printf("\n");
        cout << "--------------   上机预约(时间)   --------------" << endl;
        cout << "                   1. 上午" << endl;
        cout << "                   2. 下午" << endl;
        cout << "请选择预约时间段: " << endl;
        cin >> interval;
        if (interval >= 1 && interval <= 2)
            break;
        cout << "输入有误,请重新输入" << endl;
        my_sleep(1);
    }

    // 选择机房
    while (true)
    {
        system("cls");
        printf("\n");
        cout << "--------------   上机预约(机房)   --------------" << endl;
        for_each(vCom.begin(), vCom.end(), s_printComputer);
        cout << "请选择预约机房: " << endl;
        cin >> room;
        if (room >= 1 && room <= vCom.size())
            break;
        cout << "输入有误,请重新输入" << endl;
        my_sleep(1);
    }

    cout << "预约成功 ! 审核中" << endl;

    //格式 date(周几) interval(时间段) stuID(学号) stuName(学生姓名) roomID(机房编号) status(状态) 
    ofstream ofs(ORDER_FILE, ios::app);
    ofs << date << " " << interval << " " << s_id << " " << u_Name << " " << room << " " << 1 << endl;

    ofs.close();

    system("pause");
    system("cls");
    
}

// 查看我的预约
void Student::showMyOrder()
{
}

// 查看所有预约
void Student::showAllOrder()
{
}

// 取消预约
void Student::cancelOrder()
{
}

// 获取学生id
const int &Student::getID() const
{
    return s_id;
}

// 获取学生姓名
const string &Student::getName() const
{
    return u_Name;
}

// 获取学生密码
const string &Student::getPwd() const
{
    return u_Pwd;
}

// 设置学生id
void Student::setID(const int &id)
{
    s_id = id;
}

// 设置学生姓名
void Student::setName(const string &name)
{
    u_Name = name;
}

// 设置学生密码
void Student::setPwd(const string &pwd)
{
    u_Pwd = pwd;
}

void Student::initVector()
{
    ifstream ifs;

    // 读取机房
    ifs.open(COMPUTER_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }
    int id;
    int maxNum; // 机房最大容量
    while (ifs >> id && ifs >> maxNum)
    {
        ComputerRoom c;
        c.setID(id);
        c.setMaxNum(maxNum);
        vCom.push_back(c);
    }
    ifs.close();
}

void s_printComputer(ComputerRoom &c)
{
    cout << "\t\t" << c.getID() << "号机房\t"
         << "容量: " << c.getNum() << endl;
}
#include "manager.h"
#include "globalConstant.h"
#include "mainMenu.h"
#include <fstream>
#include <algorithm>
using namespace std;

void printStudent(Student &s);
void printTeacher(Teacher &t);
void m_printComputer(ComputerRoom &c);

//默认构造
Manager::Manager()
{
}

//有参构造
Manager::Manager(string name, string pwd)
{
    u_Name = name;
    u_Pwd = pwd;

    initVector();
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
    string fileName;
    string tip;
    ofstream ofs;

    int id;
    string name;
    string pwd;

    int option = -1;
    while (1)
    {
        system("cls");
        cout << "--------------   机房管理系统(管理员)   --------------" << endl;
        cout << "                   1. 添加学生" << endl;
        cout << "                   2. 添加老师" << endl;
        cout << "                   0. 返回上一级" << endl;
        cout << "请输入您的选择: ";

        cin >> option;
        if(option == 1)
        {
            fileName = STUDENT_FILE;
            tip = "请输入学号: ";
            break;
        }
        else if(option == 2)
        {
            fileName = TEACHER_FILE;
            tip = "请输入教职工编号: ";
            break;
        }
        else
        {
            cout << "输入错误,请重新输入" << endl;
            my_sleep(1);
        }
    }
    ofs.open(fileName, ios::out | ios::app); //app追加在末尾

    
    cout << tip;
    cin >> id;
    if(option == 1)
    {
        if(findPerson(STUDENT, id))
        {
            cout << "该学号已被注册..." << endl;
            my_sleep(1);
            system("cls");
            return;
        }
    }
    else
    {
        if(findPerson(TEACHER, id))
        {
            cout << "该教职工编号已被注册..." << endl;
            my_sleep(1);
            system("cls");
            return;
        }
    }

    cout << "请输入您的姓名: ";
    cin >> name;

    cout << "请输入密码: ";
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << "\n";
    cout << "添加成功..." << endl;

    system("pause");
    system("cls");

    ofs.close();
}

//查看账号
void Manager::showPerson()
{
    system("cls");
    cout << "--------------   机房管理系统(管理员)   --------------" << endl;
    cout << "                   1. 查看所有学生" << endl;
    cout << "                   2. 查看所有老师" << endl;
    cout << "                   other. 返回上一级" << endl;
    cout << "请输入您的选择: ";

	int option = -1;

	cin >> option;
    
	if (option == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if(option == 2)
	{
		cout << "所有老师信息如下： " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
    else
    {
        system("cls");
        return;
    }
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下： " << endl;
    for_each(vCom.begin(), vCom.end(), m_printComputer);
    system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
    //ios::trunc 覆盖当前记录再写入,不操作就关闭就是清空记录
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器,读取文件中的账号
void Manager::initVector()
{
    ifstream ifs;

    //读取学生
    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
		return;
    }

    vStu.clear();
    vTea.clear();

    int id;  //表示学生老师机房的id
    string name;
    string pwd;
    while(ifs >> id && ifs >> name && ifs >> pwd)
    {
        Student s;
        s.setID(id);
        s.setName(name);
        s.setPwd(pwd);
        vStu.push_back(s);
    }
    ifs.close();

    //读取老师
    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
		return;
    }

    while(ifs >> id && ifs >> name && ifs >> pwd)
    {
        Teacher t;
        t.setID(id);
        t.setName(name);
        t.setPwd(pwd);
        vTea.push_back(t);
    }
    ifs.close();

    //读取机房
    ifs.open(COMPUTER_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
		return;
    }

    int maxNum; //机房最大容量
    while(ifs >> id && ifs >> maxNum)
    {
        ComputerRoom c;
        c.setID(id);
        c.setMaxNum(maxNum);
        vCom.push_back(c);
    }
    ifs.close();
}

//容器接口
bool Manager::findPerson(int identity, int id)
{
    
    if(identity == STUDENT)
    {
        for (const Student& student : vStu) 
        {
            if (student.getID() == id) 
                return true;
        }
    }
    else if(identity == TEACHER)
    {
        for (const Teacher& teacher : vTea) {
            if (teacher.getID() == id) 
                return true;
        }
    }
    return false;
}


void printStudent(Student &s)
{
    cout << "学号： " << s.getID() << " 姓名： " << s.getName() << " 密码：" << s.getPwd() << endl;
}

void printTeacher(Teacher &t)
{
    cout << "学号： " << t.getID() << " 姓名： " << t.getName() << " 密码：" << t.getPwd() << endl;
}

void m_printComputer(ComputerRoom &c)
{
    cout << "机房编号: " << c.getID() << "\t容量: " << c.getNum() << endl;
}
#include "loginIn.h"
#include <fstream>
#include "identity.h"
#include "globalConstant.h"
#include "student.h"
#include "manager.h"
#include "teacher.h"
#include "mainMenu.h"
#include <string>
using namespace std;

void LoginIn(std::string fileName, int identity)
{
    Identity *user = nullptr;

    ifstream ifs;
    ifs.open(fileName, ios::in);

    //文件不存在情况
    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        my_sleep(1);
        system("cls");
        return;
    }

    int id = -1;
    string name;
    string pwd;

    if(identity == STUDENT)
    {
        cout << "学号: ";
        cin >> id;
    }
    else if(identity == TEACHER)
    {
        cout << "教职工号: ";
        cin >> id;
    }

    cout << "用户名: ";
    cin >> name;

    cout << "密码: ";
    cin >> pwd;

    if(identity == STUDENT)
    {
        //学生登录验证
        int fId;
        string fName;
        string fPwd;
        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(fId == id && name == fName && pwd == fPwd)
            {
                cout << "学生验证,登录成功" << endl;
                system("pause");
                system("cls");
                user = new Student(id, name, pwd);
                studentMenu(user);
                return;
            }
        }
    }
    else if(identity == TEACHER)
    {
        int fId;
        string fName;
        string fPwd;
        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(fId == id && name == fName && pwd == fPwd)
            {
                cout << "教师验证,登录成功" << endl;
                system("pause");
                system("cls");
                user = new Teacher(id, name, pwd);
                return;
            }
        }
    }
    else if(identity == ADMIN)
    {
        string fName;
        string fPwd;
        while(ifs >> fName && ifs >> fPwd)
        {
            if(name == fName && pwd == fPwd)
            {
                cout << "管理员验证,登录成功" << endl;
                system("pause");
                system("cls");
                user = new Manager(name, pwd);
                managerMenu(user);
                return;
            }
        }
    }
    
    cout << "验证登录失败! " << endl;
    my_sleep(1);

    system("cls");
    return;
}
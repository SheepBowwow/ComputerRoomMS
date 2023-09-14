#include "loginIn.h"
#include <fstream>
#include "identity.h"
#include "globalConstant.h"
#include "student.h"
#include <thread>
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
        this_thread::sleep_for(std::chrono::seconds(1));
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
            //if(fId == id && name.compare(fName) && pwd.compare(fPwd))
            if(fName == name)
            {
                cout << "学生验证登录成功" << endl;
                system("pause");
                system("cls");
                user = new Student(id, name, pwd);
                return;
            }
        }
        cout << fId  << " "<< fName << " " << fPwd << endl;
    }
    else if(identity == TEACHER)
    {
        //教师登录验证
    }
    else if(identity == ADMIN)
    {
        //管理员
    }
    
    cout << "验证登录失败! " << endl;
    this_thread::sleep_for(std::chrono::seconds(1));
    //system("cls");
    return;
}
#include <iostream>
#include "mainMenu.h"
#include "loginIn.h"
#include "globalConstant.h"
#include <thread>
using namespace std;


//order 格式 date(周几) interval(时间段) stuID(学号) stuName(学生姓名) roomID(机房编号) status(状态) 
int main()
{
    //用户选项
    int Option = -1;
    while (true)
    {
        showMainMenu();

        cout << "请输入您的选择: ";
        cin >> Option;
        
        switch (Option)
        {
        case ADMIN:     //进入管理员界面
            LoginIn(ADMIN_FILE, ADMIN);
            break;
        case TEACHER:     //进入教师界面
            LoginIn(TEACHER_FILE, TEACHER);
            break;
        case STUDENT:     //进入学生界面
            LoginIn(STUDENT_FILE, STUDENT);
            break;
        case EXIT:     //退出程序
            //system("cls");
            exit(0);
            break;
        default:
            cout << "输入有误, 请重新输入" << endl;
            my_sleep(1);
            system("cls");
            break;
        }
    }
    

    return 0;
}
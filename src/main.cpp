#include <iostream>
//# include <Windows.h>
#include "mainMenu.h"
#include "loginIn.h"
#include "globalConstant.h"
#include <thread>
using namespace std;

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
        case STUDENT:     //进入管理员界面
            LoginIn(STUDENT_FILE, Option);
            break;
        case TEACHER:     //进入教师界面
            LoginIn(TEACHER_FILE, Option);
            break;
        case ADMIN:     //进入学生界面
            LoginIn(ADMIN_FILE, Option);
            break;
        case EXIT:     //退出程序
            //system("cls");
            exit(0);
            break;
        default:
            cout << "输入有误, 请重新输入" << endl;
            this_thread::sleep_for(std::chrono::seconds(1));
            system("cls");
            break;
        }
    }
    

    return 0;
}
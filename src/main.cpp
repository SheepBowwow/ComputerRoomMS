#include <iostream>
# include <Windows.h>
#include "mainMenu.h"
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
        case 1:     //进入管理员界面
            break;
        case 2:     //进入教师界面
            break;
        case 3:     //进入学生界面
            break;
        case 0:     //退出程序
            exit(0);
            break;
        default:
            cout << "输入有误, 请重新输入" << endl;
            Sleep(1000);
            system("cls");
            break;
        }
    }
    

    return 0;
}
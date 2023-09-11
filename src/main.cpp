#include <iostream>
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
            break;
        }
    }
    

    return 0;
}
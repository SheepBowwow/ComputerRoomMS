#include "mainMenu.h"
#include "globalConstant.h"
#include <iostream>
using namespace std;

void showMainMenu()
{
    printf("\n");
    cout << "--------------   机房管理系统   --------------" << endl;
    cout << "                   1、管理员" << endl;
    cout << "                   2、老师" << endl;
    cout << "                   3、学生" << endl;
    cout << "                   0、退出" << endl;
}

//管理员菜单
void managerMenu(Identity *& manager)
{
    //用户选项
    int Option = -1;
    Manager *man = (Manager *)manager;
    while (true)
    {
        manager->openMenu();

        cout << "请输入您的选择: ";
        cin >> Option;
        
        switch (Option)
        {
        case ADD_PERSON:     //添加账号
            cout << "添加账号" << endl;
            man->addPerson();
            break;
        case SHOW_PERSON:     //查看账号
            cout << "查看账号" << endl;
			man->showPerson(); 
            break;
        case SHOW_COMPUTER:     //查看机房
            cout << "查看机房" << endl;
			man->showComputer();
            break;
        case CLEAN_FILE:     //清空预约
            cout << "清空预约" << endl;
			man->cleanFile();
            break;
        case EXIT:     //退出程序
            system("cls");
            return;
        default:
            cout << "输入有误, 请重新输入" << endl;
            my_sleep(1);
            system("cls");
            break;
        }
    }
}
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
            man->addPerson();
            break;
        case SHOW_PERSON:     //查看账号
			man->showPerson(); 
            break;
        case SHOW_COMPUTER:     //查看机房
			man->showComputer();
            break;
        case CLEAN_FILE:     //清空预约
			man->cleanFile();
            break;
        case EXIT:     //退出程序
            delete manager;
            cout << "注销成功" << endl;
			system("pause");
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

void studentMenu(Identity *&student)
{
    Student* stu = (Student*)student;
	while (true)
	{
		//学生菜单
		student->openMenu();
        cout << "请输入您的选择: ";
		
        int option = 0;
		cin >> option;

		if (option == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (option == 2) //查看自身预约
		{
			stu->showMyOrder();
		}
		else if (option == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (option == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else if (option == EXIT)
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
        else
        {
            cout << "输入有误,请重新输入" << endl;
            my_sleep(1);
            system("cls");
        }
	}
}

#include "mainMenu.h"
#include "globalConstant.h"
#include <iostream>
using namespace std;

void showMainMenu()
{
    printf("\n");
    cout << "--------------   ��������ϵͳ   --------------" << endl;
    cout << "                   1������Ա" << endl;
    cout << "                   2����ʦ" << endl;
    cout << "                   3��ѧ��" << endl;
    cout << "                   0���˳�" << endl;
}

//����Ա�˵�
void managerMenu(Identity *& manager)
{
    //�û�ѡ��
    int Option = -1;
    Manager *man = (Manager *)manager;
    while (true)
    {
        manager->openMenu();

        cout << "����������ѡ��: ";
        cin >> Option;
        
        switch (Option)
        {
        case ADD_PERSON:     //����˺�
            man->addPerson();
            break;
        case SHOW_PERSON:     //�鿴�˺�
			man->showPerson(); 
            break;
        case SHOW_COMPUTER:     //�鿴����
			man->showComputer();
            break;
        case CLEAN_FILE:     //���ԤԼ
			man->cleanFile();
            break;
        case EXIT:     //�˳�����
            delete manager;
            cout << "ע���ɹ�" << endl;
			system("pause");
            system("cls");
            return;
        default:
            cout << "��������, ����������" << endl;
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
		//ѧ���˵�
		student->openMenu();
        cout << "����������ѡ��: ";
		
        int option = 0;
		cin >> option;

		if (option == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (option == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (option == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (option == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else if (option == EXIT)
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
        else
        {
            cout << "��������,����������" << endl;
            my_sleep(1);
            system("cls");
        }
	}
}

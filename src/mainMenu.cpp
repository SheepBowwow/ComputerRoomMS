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
            cout << "����˺�" << endl;
            man->addPerson();
            break;
        case SHOW_PERSON:     //�鿴�˺�
            cout << "�鿴�˺�" << endl;
			man->showPerson(); 
            break;
        case SHOW_COMPUTER:     //�鿴����
            cout << "�鿴����" << endl;
			man->showComputer();
            break;
        case CLEAN_FILE:     //���ԤԼ
            cout << "���ԤԼ" << endl;
			man->cleanFile();
            break;
        case EXIT:     //�˳�����
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
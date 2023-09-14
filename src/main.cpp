#include <iostream>
//# include <Windows.h>
#include "mainMenu.h"
#include "loginIn.h"
#include "globalConstant.h"
#include <thread>
using namespace std;

int main()
{
    //�û�ѡ��
    int Option = -1;
    while (true)
    {
        showMainMenu();

        cout << "����������ѡ��: ";
        cin >> Option;
        
        switch (Option)
        {
        case ADMIN:     //�������Ա����
            LoginIn(ADMIN_FILE, ADMIN);
            break;
        case TEACHER:     //�����ʦ����
            LoginIn(TEACHER_FILE, TEACHER);
            break;
        case STUDENT:     //����ѧ������
            LoginIn(STUDENT_FILE, STUDENT);
            break;
        case EXIT:     //�˳�����
            //system("cls");
            exit(0);
            break;
        default:
            cout << "��������, ����������" << endl;
            this_thread::sleep_for(std::chrono::seconds(1));
            system("cls");
            break;
        }
    }
    

    return 0;
}
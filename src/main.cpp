#include <iostream>
#include "mainMenu.h"
#include "loginIn.h"
#include "globalConstant.h"
#include <thread>
using namespace std;


//order ��ʽ date(�ܼ�) interval(ʱ���) stuID(ѧ��) stuName(ѧ������) roomID(�������) status(״̬) 
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
            my_sleep(1);
            system("cls");
            break;
        }
    }
    

    return 0;
}
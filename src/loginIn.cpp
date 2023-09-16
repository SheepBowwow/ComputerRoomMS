#include "loginIn.h"
#include <fstream>
#include "identity.h"
#include "globalConstant.h"
#include "student.h"
#include "manager.h"
#include "teacher.h"
#include "mainMenu.h"
#include <string>
using namespace std;

void LoginIn(std::string fileName, int identity)
{
    Identity *user = nullptr;

    ifstream ifs;
    ifs.open(fileName, ios::in);

    //�ļ����������
    if(!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        ifs.close();
        my_sleep(1);
        system("cls");
        return;
    }

    int id = -1;
    string name;
    string pwd;

    if(identity == STUDENT)
    {
        cout << "ѧ��: ";
        cin >> id;
    }
    else if(identity == TEACHER)
    {
        cout << "��ְ����: ";
        cin >> id;
    }

    cout << "�û���: ";
    cin >> name;

    cout << "����: ";
    cin >> pwd;

    if(identity == STUDENT)
    {
        //ѧ����¼��֤
        int fId;
        string fName;
        string fPwd;
        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(fId == id && name == fName && pwd == fPwd)
            {
                cout << "ѧ����֤,��¼�ɹ�" << endl;
                system("pause");
                system("cls");
                user = new Student(id, name, pwd);
                studentMenu(user);
                return;
            }
        }
    }
    else if(identity == TEACHER)
    {
        int fId;
        string fName;
        string fPwd;
        while(ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if(fId == id && name == fName && pwd == fPwd)
            {
                cout << "��ʦ��֤,��¼�ɹ�" << endl;
                system("pause");
                system("cls");
                user = new Teacher(id, name, pwd);
                return;
            }
        }
    }
    else if(identity == ADMIN)
    {
        string fName;
        string fPwd;
        while(ifs >> fName && ifs >> fPwd)
        {
            if(name == fName && pwd == fPwd)
            {
                cout << "����Ա��֤,��¼�ɹ�" << endl;
                system("pause");
                system("cls");
                user = new Manager(name, pwd);
                managerMenu(user);
                return;
            }
        }
    }
    
    cout << "��֤��¼ʧ��! " << endl;
    my_sleep(1);

    system("cls");
    return;
}
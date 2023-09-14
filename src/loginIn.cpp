#include "loginIn.h"
#include <fstream>
#include "identity.h"
#include "globalConstant.h"
#include "student.h"
#include <thread>
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
        this_thread::sleep_for(std::chrono::seconds(1));
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
            //if(fId == id && name.compare(fName) && pwd.compare(fPwd))
            if(fName == name)
            {
                cout << "ѧ����֤��¼�ɹ�" << endl;
                system("pause");
                system("cls");
                user = new Student(id, name, pwd);
                return;
            }
        }
        cout << fId  << " "<< fName << " " << fPwd << endl;
    }
    else if(identity == TEACHER)
    {
        //��ʦ��¼��֤
    }
    else if(identity == ADMIN)
    {
        //����Ա
    }
    
    cout << "��֤��¼ʧ��! " << endl;
    this_thread::sleep_for(std::chrono::seconds(1));
    //system("cls");
    return;
}
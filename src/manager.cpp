#include "manager.h"
#include "globalConstant.h"
using namespace std;

//Ĭ�Ϲ���
Manager::Manager()
{
}

//�вι���
Manager::Manager(string name, string pwd)
{
    u_Name = name;
    u_Pwd = pwd;
}

//ѡ��˵�
void Manager::openMenu()
{
    printf("\n");
    cout << "--------------   ��������ϵͳ(����Ա)   --------------" << endl;
    cout << "                   1. ����˺�" << endl;
    cout << "                   2. �鿴�˺�" << endl;
    cout << "                   3. �鿴����" << endl;
    cout << "                   4. ���ԤԼ" << endl;
    cout << "                   0. ע����¼" << endl;
}

//����˺�  
void Manager::addPerson()
{
}

//�鿴�˺�
void Manager::showPerson()
{
}

//�鿴������Ϣ
void Manager::showComputer()
{
}

//���ԤԼ��¼
void Manager::cleanFile()
{
}
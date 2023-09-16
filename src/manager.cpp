#include "manager.h"
#include "globalConstant.h"
#include "mainMenu.h"
#include <fstream>
#include <algorithm>
using namespace std;

void printStudent(Student &s);
void printTeacher(Teacher &t);
void m_printComputer(ComputerRoom &c);

//Ĭ�Ϲ���
Manager::Manager()
{
}

//�вι���
Manager::Manager(string name, string pwd)
{
    u_Name = name;
    u_Pwd = pwd;

    initVector();
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
    string fileName;
    string tip;
    ofstream ofs;

    int id;
    string name;
    string pwd;

    int option = -1;
    while (1)
    {
        system("cls");
        cout << "--------------   ��������ϵͳ(����Ա)   --------------" << endl;
        cout << "                   1. ���ѧ��" << endl;
        cout << "                   2. �����ʦ" << endl;
        cout << "                   0. ������һ��" << endl;
        cout << "����������ѡ��: ";

        cin >> option;
        if(option == 1)
        {
            fileName = STUDENT_FILE;
            tip = "������ѧ��: ";
            break;
        }
        else if(option == 2)
        {
            fileName = TEACHER_FILE;
            tip = "�������ְ�����: ";
            break;
        }
        else
        {
            cout << "�������,����������" << endl;
            my_sleep(1);
        }
    }
    ofs.open(fileName, ios::out | ios::app); //app׷����ĩβ

    
    cout << tip;
    cin >> id;
    if(option == 1)
    {
        if(findPerson(STUDENT, id))
        {
            cout << "��ѧ���ѱ�ע��..." << endl;
            my_sleep(1);
            system("cls");
            return;
        }
    }
    else
    {
        if(findPerson(TEACHER, id))
        {
            cout << "�ý�ְ������ѱ�ע��..." << endl;
            my_sleep(1);
            system("cls");
            return;
        }
    }

    cout << "��������������: ";
    cin >> name;

    cout << "����������: ";
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << "\n";
    cout << "��ӳɹ�..." << endl;

    system("pause");
    system("cls");

    ofs.close();
}

//�鿴�˺�
void Manager::showPerson()
{
    system("cls");
    cout << "--------------   ��������ϵͳ(����Ա)   --------------" << endl;
    cout << "                   1. �鿴����ѧ��" << endl;
    cout << "                   2. �鿴������ʦ" << endl;
    cout << "                   other. ������һ��" << endl;
    cout << "����������ѡ��: ";

	int option = -1;

	cin >> option;
    
	if (option == 1)
	{
		cout << "����ѧ����Ϣ���£� " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if(option == 2)
	{
		cout << "������ʦ��Ϣ���£� " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
    else
    {
        system("cls");
        return;
    }
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£� " << endl;
    for_each(vCom.begin(), vCom.end(), m_printComputer);
    system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
    //ios::trunc ���ǵ�ǰ��¼��д��,�������͹رվ�����ռ�¼
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������,��ȡ�ļ��е��˺�
void Manager::initVector()
{
    ifstream ifs;

    //��ȡѧ��
    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "�ļ���ȡʧ��" << endl;
		return;
    }

    vStu.clear();
    vTea.clear();

    int id;  //��ʾѧ����ʦ������id
    string name;
    string pwd;
    while(ifs >> id && ifs >> name && ifs >> pwd)
    {
        Student s;
        s.setID(id);
        s.setName(name);
        s.setPwd(pwd);
        vStu.push_back(s);
    }
    ifs.close();

    //��ȡ��ʦ
    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "�ļ���ȡʧ��" << endl;
		return;
    }

    while(ifs >> id && ifs >> name && ifs >> pwd)
    {
        Teacher t;
        t.setID(id);
        t.setName(name);
        t.setPwd(pwd);
        vTea.push_back(t);
    }
    ifs.close();

    //��ȡ����
    ifs.open(COMPUTER_FILE, ios::in);
    if(!ifs.is_open())
    {
        cout << "�ļ���ȡʧ��" << endl;
		return;
    }

    int maxNum; //�����������
    while(ifs >> id && ifs >> maxNum)
    {
        ComputerRoom c;
        c.setID(id);
        c.setMaxNum(maxNum);
        vCom.push_back(c);
    }
    ifs.close();
}

//�����ӿ�
bool Manager::findPerson(int identity, int id)
{
    
    if(identity == STUDENT)
    {
        for (const Student& student : vStu) 
        {
            if (student.getID() == id) 
                return true;
        }
    }
    else if(identity == TEACHER)
    {
        for (const Teacher& teacher : vTea) {
            if (teacher.getID() == id) 
                return true;
        }
    }
    return false;
}


void printStudent(Student &s)
{
    cout << "ѧ�ţ� " << s.getID() << " ������ " << s.getName() << " ���룺" << s.getPwd() << endl;
}

void printTeacher(Teacher &t)
{
    cout << "ѧ�ţ� " << t.getID() << " ������ " << t.getName() << " ���룺" << t.getPwd() << endl;
}

void m_printComputer(ComputerRoom &c)
{
    cout << "�������: " << c.getID() << "\t����: " << c.getNum() << endl;
}
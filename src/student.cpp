#include "student.h"
#include <fstream>
#include "globalConstant.h"
#include "computerRoom.h"
#include <algorithm>
using namespace std;

void s_printComputer(ComputerRoom &c);

// �޲ι���
Student::Student()
{
}

// �вι���
Student::Student(int id, string name, string pwd)
{
    this->s_id = id;
    u_Name = name;
    u_Pwd = pwd;

    this->initVector();
}

// �˵�ѡ��
void Student::openMenu()
{
    printf("\n");
    cout << "--------------   ��������ϵͳ(����Ա)   --------------" << endl;
    cout << "                   1. ����ԤԼ" << endl;
    cout << "                   2. �鿴�ҵ�ԤԼ" << endl;
    cout << "                   3. �鿴����ԤԼ" << endl;
    cout << "                   4. ȡ��ԤԼ" << endl;
    cout << "                   0. ע����¼" << endl;
}

// ����ԤԼ
void Student::applyOrder()
{
    int date = 0;     // ��һ ~ ����
    int interval = 0; // ԤԼʱ���
    int room = 0;     // ����

    // ѡ��ʱ��
    while (true)
    {
        system("cls");
        printf("\n");
        cout << "--------------   �ϻ�ԤԼ(ʱ��)   --------------" << endl;
        cout << "                   1. ��һ" << endl;
        cout << "                   2. �ܶ�" << endl;
        cout << "                   3. ����" << endl;
        cout << "                   4. ����" << endl;
        cout << "                   5. ����" << endl;
        cout << "��ѡ��ԤԼʱ��: " << endl;
        cin >> date;
        if (date >= 1 && date <= 5)
            break;
        cout << "��������,����������" << endl;
        my_sleep(1);
    }

    // ѡ��ʱ���
    while (true)
    {
        system("cls");
        printf("\n");
        cout << "--------------   �ϻ�ԤԼ(ʱ��)   --------------" << endl;
        cout << "                   1. ����" << endl;
        cout << "                   2. ����" << endl;
        cout << "��ѡ��ԤԼʱ���: " << endl;
        cin >> interval;
        if (interval >= 1 && interval <= 2)
            break;
        cout << "��������,����������" << endl;
        my_sleep(1);
    }

    // ѡ�����
    while (true)
    {
        system("cls");
        printf("\n");
        cout << "--------------   �ϻ�ԤԼ(����)   --------------" << endl;
        for_each(vCom.begin(), vCom.end(), s_printComputer);
        cout << "��ѡ��ԤԼ����: " << endl;
        cin >> room;
        if (room >= 1 && room <= vCom.size())
            break;
        cout << "��������,����������" << endl;
        my_sleep(1);
    }

    cout << "ԤԼ�ɹ� ! �����" << endl;

    //��ʽ date(�ܼ�) interval(ʱ���) stuID(ѧ��) stuName(ѧ������) roomID(�������) status(״̬) 
    ofstream ofs(ORDER_FILE, ios::app);
    ofs << date << " " << interval << " " << s_id << " " << u_Name << " " << room << " " << 1 << endl;

    ofs.close();

    system("pause");
    system("cls");
    
}

// �鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
}

// �鿴����ԤԼ
void Student::showAllOrder()
{
}

// ȡ��ԤԼ
void Student::cancelOrder()
{
}

// ��ȡѧ��id
const int &Student::getID() const
{
    return s_id;
}

// ��ȡѧ������
const string &Student::getName() const
{
    return u_Name;
}

// ��ȡѧ������
const string &Student::getPwd() const
{
    return u_Pwd;
}

// ����ѧ��id
void Student::setID(const int &id)
{
    s_id = id;
}

// ����ѧ������
void Student::setName(const string &name)
{
    u_Name = name;
}

// ����ѧ������
void Student::setPwd(const string &pwd)
{
    u_Pwd = pwd;
}

void Student::initVector()
{
    ifstream ifs;

    // ��ȡ����
    ifs.open(COMPUTER_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ���ȡʧ��" << endl;
        return;
    }
    int id;
    int maxNum; // �����������
    while (ifs >> id && ifs >> maxNum)
    {
        ComputerRoom c;
        c.setID(id);
        c.setMaxNum(maxNum);
        vCom.push_back(c);
    }
    ifs.close();
}

void s_printComputer(ComputerRoom &c)
{
    cout << "\t\t" << c.getID() << "�Ż���\t"
         << "����: " << c.getNum() << endl;
}
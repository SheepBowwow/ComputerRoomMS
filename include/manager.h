#ifndef MANAGER_H
#define MANAGER_H

#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <vector>
using namespace std;

class Manager : public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���  ����Ա����������
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void openMenu();

	//����˺�  
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������,��ȡ�ļ��е��˺�
	void initVector();

	//�����ӿ�
    bool findPerson(int identity, int id);

private:
	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vCom;
};

#endif
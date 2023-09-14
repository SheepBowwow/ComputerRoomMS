#ifndef GLOBAL_FILE_H
#define GLOBAL_FILE_H

#include <thread>

/**
 * �ļ�
*/

#define ADMIN_FILE     "dataFile/admin.txt"         //����Ա�ļ�
#define STUDENT_FILE   "dataFile/student.txt"       //ѧ���ļ�
#define TEACHER_FILE   "dataFile/teacher.txt"       //��ʦ�ļ�
#define COMPUTER_FILE  "dataFile/computerRoom.txt"  //������Ϣ�ļ�
#define ORDER_FILE     "dataFile/order.txt"         //�����ļ�

/**
 * ���
*/
#define ADMIN 1     //ѧ�����
#define TEACHER 2   //��ʦ���
#define STUDENT 3   //����Ա���

/**
 * ����Ա����
*/
#define ADD_PERSON 1        //����˺�
#define SHOW_PERSON 2       //�鿴�˺�
#define SHOW_COMPUTER 3     //�鿴����
#define CLEAN_FILE 4        //���ԤԼ

//�˳�
#define EXIT 0

//˯�ߺ���
void my_sleep(int second);

#endif
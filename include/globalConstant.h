#ifndef GLOBAL_FILE_H
#define GLOBAL_FILE_H

#include <thread>

/**
 * 文件
*/

#define ADMIN_FILE     "dataFile/admin.txt"         //管理员文件
#define STUDENT_FILE   "dataFile/student.txt"       //学生文件
#define TEACHER_FILE   "dataFile/teacher.txt"       //教师文件
#define COMPUTER_FILE  "dataFile/computerRoom.txt"  //机房信息文件
#define ORDER_FILE     "dataFile/order.txt"         //订单文件

/**
 * 身份
*/
#define ADMIN 1     //学生身份
#define TEACHER 2   //老师身份
#define STUDENT 3   //管理员身份

/**
 * 管理员操作
*/
#define ADD_PERSON 1        //添加账号
#define SHOW_PERSON 2       //查看账号
#define SHOW_COMPUTER 3     //查看机房
#define CLEAN_FILE 4        //清空预约

//退出
#define EXIT 0

//睡眠函数
void my_sleep(int second);

#endif
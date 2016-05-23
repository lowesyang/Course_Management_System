#include <iostream>
#include <string>
#include "mysql_connect.h"
using namespace std;

class STUDENT{
private:
	string s_id, name, major, dept;
public:
	STUDENT(string s_id,string name,string major, string dept);
	void course_sel(MYSQL *mysql,string sec_id,string year);		//ѡ��
	void course_del(MYSQL *mysql, string sec_id,string year);		//�˿�
	void get_course(MYSQL *mysql,string year);						//��ȡ��ѡ�γ�
	void search_course(MYSQL *mysql,string keywords,string type);					//��ѯ�ſ����
	string get_sid();
	string get_name();
	string get_major();
	string get_dept();
};
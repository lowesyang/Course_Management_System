#include <iostream>
#include <string>
using namespace std;

class LOGIN{
private:
	MYSQL_RES *res;														//�����¼��Ľ����
public:
	int is_login;
	LOGIN();
	void login(MYSQL *mysql, string user, string pswd, string type);	//��¼
	MYSQL_RES *get_result();											// ��ȡ�����
	void logout();														//�ǳ�
};
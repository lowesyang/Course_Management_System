#include <iostream>
#include <string>
using namespace std;

class LOGIN{
private:
	MYSQL_RES *res;														//保存登录后的结果集
public:
	int is_login;
	LOGIN();
	void login(MYSQL *mysql, string user, string pswd, string type);	//登录
	MYSQL_RES *get_result();											// 获取结果集
	void logout();														//登出
};
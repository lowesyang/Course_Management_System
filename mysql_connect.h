#include <iostream>
#include <winsock.h>
#include "mysql.h"
using namespace std;

class MYSQL_CONN{
private:
	char *user, *pswd, *host, *table;
	int port;
public:
	static MYSQL *mysql;	//mysql���Ӿ��
	MYSQL_CONN();			//constructor
	int connect();			//����mysql����
	void close();			//�ر�mysql
};
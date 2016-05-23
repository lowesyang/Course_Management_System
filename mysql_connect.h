#include <iostream>
#include <winsock.h>
#include "mysql.h"
using namespace std;

class MYSQL_CONN{
private:
	char *user, *pswd, *host, *table;
	int port;
public:
	static MYSQL *mysql;	//mysql连接句柄
	MYSQL_CONN();			//constructor
	int connect();			//连接mysql函数
	void close();			//关闭mysql
};
#include "mysql_connect.h"

MYSQL *MYSQL_CONN::mysql = NULL;

MYSQL_CONN::MYSQL_CONN(){
	this->user = "root";
	this->pswd = "root";
	this->host = "127.0.0.1";
	this->table = "course_choice";
	this->port = 3306;
}

int MYSQL_CONN::connect(){
	if (MYSQL_CONN::mysql){
		return 1;
	}
	MYSQL_CONN::mysql = new MYSQL();
	mysql_init(MYSQL_CONN::mysql);
	if (mysql_real_connect(MYSQL_CONN::mysql, this->host, this->user, this->pswd, this->table, this->port, NULL, 0)){
		mysql_query(MYSQL_CONN::mysql, "SET NAMES GB2312");
		return 1;
	}
	else return 0;
}

void MYSQL_CONN::close(){
	mysql_close(MYSQL_CONN::mysql);
}

/*
int main(){
	MYSQL_CONN mysql_conn;
	MYSQL *mysql;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	MYSQL_FIELD *fd;
	if (mysql_conn.connect()){
		//cout << mysql_conn.getHost();
		mysql = MYSQL_CONN::mysql;
		cout << "connect succeed!" << endl;
		if (!mysql_query(mysql, "select * from student")){
			result = mysql_store_result(mysql);
			if (result){
				cout << mysql_num_rows(result) << endl;
				int i, j;
				for (i = 0; fd = mysql_fetch_field(result); i++){
					cout << fd->name << "\t";
				}
				cout << endl;
				j = mysql_num_fields(result);
				while (sql_row = mysql_fetch_row(result)){
					for (i = 0; i < j; i++){
						cout << sql_row[i] << "\t";
					}
					cout << endl;
				}
			}
		}
	}
	else{
		cout << "failed" << endl;
	}
	return 0;
}
*/

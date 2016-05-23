#include "mysql_connect.h"
#include "login.h"

LOGIN::LOGIN(){
	this->is_login = 0;
}

void LOGIN::login(MYSQL *mysql,string username,string pswd,string type){
	if (this->is_login){
		cout << "ÕËºÅÒÑµÇÂ¼!";
		return;
	}
	string query = "select * from " + type + " where s_id='" + username + "' and psword='" + pswd + "';";
	const char *sql = query.c_str();
	if (!mysql_query(mysql, sql)){
		this->res = mysql_store_result(mysql);
		if (mysql_num_rows(this->res)){
			this->is_login = 1;
			cout << "µÇÂ¼³É¹¦";
		}
		else{
			cout << "ÕËºÅ»òÃÜÂëÊäÈë´íÎó!";
		}
	}
}

MYSQL_RES *LOGIN::get_result(){
	return this->res;
}

void LOGIN::logout(){
	this->is_login = 0;
}

/*
int main(){
	LOGIN login;
	MYSQL_CONN mysql_conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL_FIELD *fd;
	string user, pswd;
	cin >> user >> pswd;
	if (mysql_conn.connect()){
		login.login(MYSQL_CONN::mysql, user, pswd, "student");
		res = login.get_result();
		if (login.is_login){
			for (int i = 0; fd = mysql_fetch_field(res); i++){
				cout << fd->name << "\t";
			}
			int num = mysql_num_fields(res);
			while (row = mysql_fetch_row(res)){
				for (int i = 0; i < num; i++){
					cout << row[i] << "\t";
				}
			}
		}
	}
	return 0;
}
*/

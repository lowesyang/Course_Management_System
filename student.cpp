#include "student.h"

STUDENT::STUDENT(string s_id, string name, string major, string dept){
	this->s_id = s_id;
	this->name = name;
	this->major = major;
	this->dept = dept;
}

void STUDENT::course_sel(MYSQL *mysql, string sec_id,string year){
	MYSQL_RES *res;
	string find_conflict_sql = "select * from stu_course where sec_id='" + sec_id 
		+ "' and s_id='"+this->s_id+"' and year='"+year+"';";
	if (!mysql_query(mysql, find_conflict_sql.c_str())){
		res = mysql_store_result(mysql);
		if (res && mysql_num_rows(res)){
			cout << "与已选课程冲突"<< endl;
			return;
		}
	}
	string add_new_sql = "insert into stu_course (s_id,sec_id,grade,year) values ('"
		+ this->s_id + "','" + sec_id + "','" + "','" + year + "');";
	if (!mysql_query(mysql, add_new_sql.c_str())){
		cout << "选课成功!";
	}
}

void STUDENT::course_del(MYSQL *mysql, string sec_id,string year){
	string sql = "delete from stu_course where s_id='" + this->s_id + "' and sec_id='" + sec_id + "' and year='"+year+"';";
	if (!mysql_query(mysql, sql.c_str())){
		cout << "删除成功!" << endl;					//暂时未解决如何检测删除操作成功但无记录删除的情况
	}
	else{
		cout << mysql_error(mysql) << endl;
	}
}

void STUDENT::get_course(MYSQL *mysql,string year){
	MYSQL_RES *res;
	MYSQL_ROW row;
	string select_sql = "select * from stu_course as a join course_tech as b on a.sec_id=b.sec_id join course as c on b.course_id = c.course_id where s_id='" 
		+ this->s_id + "' and year='" + year + "';";
	if (!mysql_query(mysql,select_sql.c_str())){
		res = mysql_store_result(mysql);
		if (mysql_num_rows(res)){
			int num = mysql_num_fields(res);
			while (row = mysql_fetch_row(res)){			//fetch结果行
				for (int i = 0; i < num; i++){
					if (row[i] != NULL)
						cout << row[i] << "\t";
					else
						cout << " " << "\t";
				}
				cout << endl;
			}
		}
		else{
			cout << year + "年并没有选课" << endl;
		}
	}
	else{
		cout << "failed" << endl;
	}
}

void STUDENT::search_course(MYSQL *mysql, string keywords, string type){
	MYSQL_RES *res;
	MYSQL_ROW row;
	string search_sql = "select * from course_tech as a join course as b on a.course_id=b.course_id where "
		+ type + " like '%" + keywords + "%';";
	if (!mysql_query(mysql, search_sql.c_str())){
		res = mysql_store_result(mysql);
		if (mysql_num_rows(res)){
			int num = mysql_num_fields(res);
			while (row = mysql_fetch_row(res)){
				for (int i = 0; i < num; i++){
					cout << row[i] << "\t";
				}
				cout << endl;
			}
		}
		else{
			cout << "没有找到相关记录!" << endl;
		}
	}
}

string STUDENT::get_sid(){
	return this->s_id;
}

string STUDENT::get_name(){
	return this->name;
}

string STUDENT::get_major(){
	return this->major;
}

string STUDENT::get_dept(){
	return this->dept;
}

/*
int main(){
	STUDENT stu("1001","杨奕辉","计算机","计算机");
	MYSQL_CONN my;
	if (!my.connect()) return 0;
	//stu.course_sel(MYSQL_CONN::mysql, "1002","2015");
	//stu.course_del(MYSQL_CONN::mysql, "1002","2016");
	//stu.get_course(MYSQL_CONN::mysql, "2016");
	//stu.search_course(MYSQL_CONN::mysql, "1.5", "score");
	return 0;
}
*/
/*
 * mysql.c
 *
 *  Created on: 2018年8月22日
 *      Author: songchaochao
 */

#include "mymysql.h"
#include <string>

using namespace std;

MyMySQL::MyMySQL(string addr_mysql,string user_name,string key_mysql,string database_name,u32 port)
{
	this->addr = addr_mysql;
	this->usr = user_name;
	this->key = key_mysql;
	this->database = database_name;
	this->port = port;
	this->mysql = mysql_init(NULL);//初始化mysql对象
	this->row = NULL;
	this->result = NULL;
}

void MyMySQL::Init()
{
	MyMySQL mymysql(ADDR_DATABASE,USR_MYSQL,KEY_MYSQL,NAME_DATABASE,PORT_MYSQL);
	mysql_real_connect(mymysql.mysql,mymysql.addr.c_str(),mymysql.usr.c_str(),mymysql.key.c_str(),mymysql.database.c_str(),0,NULL,0);

	//string sql = "insert into client(client1,client2,client3,client4) value(1,2,3,4)";
	//string sql = "show databases";//显示各个数据库

//	string sql = "insert into datas(num,yymmdd,msec,digtal,adc_length_byte,channel1,channel2,channel3,channel4)"
//			" value(1,200000,322,1,100,2,3,4,5)";
//
//	mysql_query(mymysql.mysql,sql.c_str());
//
//	mymysql.result = mysql_use_result(mymysql.mysql);
//
//	while(&mymysql.result)
//	{
//
//	//	cout<<mysql_fetch_field(mymysql.result)->length<<endl;
//		// 获取下一行
//		mymysql.row = mysql_fetch_row(mymysql.result);
////		if(mymysql.row <= 0)
////		{
////			break;
////		}
//		// mysql_num_fields()返回结果集中的字段数
//		for(u32 j=0; j < mysql_num_fields(mymysql.result); ++j)
//		{
//
//			cout << mymysql.row[j] << " ";
//		}
//		cout << endl;
//	}
//	cout<<&mymysql.result<<endl;
//	mysql_close(mymysql.mysql);
}

MyMySQL::~MyMySQL()
{
	if(this->mysql!=NULL)
	{
		mysql_close(this->mysql);
	}

}

/*
 * mysql.h
 *
 *  Created on: 2018年8月22日
 *      Author: songchaochao
 */

#ifndef MYMYSQL_H_
#define MYMYSQL_H_

#include <iostream>
#include <mysql/mysql.h>
#include <string>

#define u8 unsigned char
#define u32 unsigned int
#define s32 int
#define s8 char

#define ADDR_DATABASE   "localhost"
#define USR_MYSQL       "root"
#define KEY_MYSQL       "13859017nick"
#define NAME_DATABASE   "udp_datas"
#define PORT_MYSQL      3306

using namespace std;

class MyMySQL
{
public:
	explicit MyMySQL(string addr_mysql,string user_name,string key_mysql,string database_name,u32 port);
	~MyMySQL();
	void Init();
private:
	string usr;
	string addr;
	string key;
	string database;
	u32 port;

	MYSQL * mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
};

#endif /* MYMYSQL_H_ */

/*
 * udp.h
 *
 *  Created on: 2018年8月22日
 *      Author: songchaochao
 */

#ifndef UDP_H_
#define UDP_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define u8 unsigned char
#define u32 unsigned int
#define s32 int
#define s8 char

#define UDP_INIT_ERROR 10
#define UDP_STOPED	   11
#define OK             1


#define RECV_BUF_NUM 2000//存储一次的数据

class UDP
{
public:
	explicit UDP(int server_port);
	~UDP();
	s32 SERV_PORT;//服务器的开放端口

	s32 udp_init();
	s32 udp_start();
private:
	s8 recv_buf[RECV_BUF_NUM+1];
	s32 addr_serv_len;//addr_serv的长度
	s32 sock_fd;//socket文件描述符
	struct sockaddr_in addr_serv;//服务器的地址
	struct sockaddr_in addr_client;//客户端的地址
};



#endif /* UDP_H_ */

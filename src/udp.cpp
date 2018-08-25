/*
 * udp.c
 *
 *  Created on: 2018年8月22日
 *      Author: songchaochao
 */

#include "udp.h"

UDP::UDP(int server_port)
{
	this->SERV_PORT = server_port;//服务器端口
	this->addr_serv_len = 0;//后面会更新
	this->sock_fd = 0;//后面会更新

};

s32 UDP::udp_init()
{
	/* sock_fd --- socket文件描述符 创建udp套接字*/
	this->sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(this->sock_fd < 0)
	{
		perror("socket");
		exit(1);
	}

	/* 将套接字和IP、端口绑定 */

	memset(&this->addr_serv, 0, sizeof(struct sockaddr_in));  //每个字节都用0填充
	this->addr_serv.sin_family = AF_INET;//使用IPV4地址
	this->addr_serv.sin_port = htons(SERV_PORT);//端口
	/* INADDR_ANY表示不管是哪个网卡接收到数据，只要目的端口是SERV_PORT，就会被该应用程序接收到 */
	this->addr_serv.sin_addr.s_addr = htonl(INADDR_ANY);  //自动获取IP地址
	this->addr_serv_len = sizeof(this->addr_serv);

	/* 绑定socket */
	if(bind(this->sock_fd, (struct sockaddr *)&this->addr_serv, sizeof(this->addr_serv)) < 0)
	{
		perror("bind error:");
		return UDP_INIT_ERROR;
	}
	return OK;
};

s32 UDP::udp_start()
{
	u32 recv_num;

	while(1)
	{
		printf("server wait:\n");

		recv_num = recvfrom(this->sock_fd, this->recv_buf, sizeof(this->recv_buf), 0, (struct sockaddr *)&addr_client, (socklen_t *)&this->addr_serv_len);

		if(recv_num < 0)
		{
			perror("recvfrom error:");
			exit(1);
		}

		this->recv_buf[recv_num] = '\0';
		if(recv_num<50)
			printf("server receive %d bytes: %s\n", recv_num,recv_buf);
		else
			printf("server receive %d bytes: ...\n", recv_num);
	}
	return UDP_STOPED;
};

UDP::~UDP()
{

	if(&this->sock_fd)
	{
		close(this->sock_fd);
	}
}

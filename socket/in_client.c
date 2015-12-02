/*****************************************************
	^> File Name: in_client.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/01 - 20:46:33
****************************************************/
#include "../aoeiuv.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> //inet_addr
#include <event.h>
int main(int argc, char **argv)
{
	struct sockaddr_in sai;
	sai.sin_family=AF_INET;
	sai.sin_port=htons(45678);
	sai.sin_addr.s_addr=inet_addr("127.0.0.1");
	avout("family=%x,port=%hx,addr=%x;",sai.sin_family,sai.sin_port,sai.sin_addr.s_addr);
	return 0;
}

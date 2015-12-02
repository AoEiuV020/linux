/*****************************************************
	^> File Name: t.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/01 - 20:40:16
****************************************************/
#include "../aoeiuv.h"
#include <sys/un.h>
#include <netinet/in.h>
#include <sys/socket.h>
int main(int argc, char **argv)
{
	printf("sizeof un=%d,\n",sizeof(struct sockaddr_un));
	printf("sizeof in=%d,\n",sizeof(struct sockaddr_in));
	return 0;
}

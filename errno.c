/*****************************************************
	^> File Name: errno.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/18 - 23:28:43
****************************************************/
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(int argc, char **argv)
{
	remove("/tmp/asdf");
	fprintf(stderr,"remove error:%s\n",strerror(errno));
	return 0;
}

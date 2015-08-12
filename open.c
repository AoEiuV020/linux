/*****************************************************
	^> File Name: open.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/08 - 06:52:24
****************************************************/
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	char s[20]={0};
	int fd;
	int mode=S_ISUID|S_IWUSR|S_IRGRP|S_IXOTH|S_IWOTH;
	read(0,s,19);
	write(1,s,20);
	fd=open("temp",O_CREAT|O_WRONLY,mode);
	printf("%d,%o\n",fd,mode);
	write(fd,s,20);
	close(fd);
	return 0;
}

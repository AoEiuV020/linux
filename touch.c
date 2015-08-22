/*****************************************************
	^> File Name: touch.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/08 - 07:15:32
****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char **argv)
{
	if(argc<1)
	{
		return 1;
	}
	/*
	int fd;
	fd=open(argv[1],O_WRONLY|O_CREAT);
	write(fd,"",0);
	close(fd);
	//*/
	creat(argv[1],0666);
	return 0;
}

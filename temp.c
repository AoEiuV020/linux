/*****************************************************
	^> File Name: temp.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/14 - 15:44:00
****************************************************/
#include "aoeiuv.h"
int main(int argc, char **argv)
{
	int fd;
	fd=open("temp",O_WRONLY|O_CREAT,0777);
	lseek(fd,100,SEEK_END);
	write(fd,&fd,1);
	close(fd);
	return 0;
}

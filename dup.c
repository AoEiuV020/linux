/*****************************************************
	^> File Name: dup.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/23 - 02:42:18
****************************************************/

#include "aoeiuv.h"
int main(int argc, char **argv)
{
	int fd;
	fd=open("/tmp/tmp",O_RDONLY|O_CREAT);
	dup(fd);
	dup2(fd,88);
	close(fd);
	avls("/proc/self/fd");
	return 0;
}

/*****************************************************
	^> File Name: su.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/02 - 20:10:08
****************************************************/
#include "../aoeiuv.h"
#include "tty.h"
#define FF "fifo"
int main(int argc, char **argv)
{
	struct tty tt;
	memset(&tt,0,sizeof(tt));
	readlink("/proc/self/fd/0",tt.tty0,sizeof(tt.tty0));
	readlink("/proc/self/fd/1",tt.tty1,sizeof(tt.tty1));
	readlink("/proc/self/fd/2",tt.tty2,sizeof(tt.tty2));
	avout("%s",tt.tty0);
	avout("%s",tt.tty1);
	avout("%s",tt.tty2);
	int fd;
	fd=avsyscall(open,FF,O_WRONLY);
	write(fd,&tt,sizeof(tt));
	close(fd);
	sleep(222);
	return 0;
}

/*****************************************************
	^> File Name: deamon.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/02 - 18:27:56
****************************************************/
#include "../aoeiuv.h"
#include "tty.h"
#define FF "fifo"
#define TTY "/dev/pts/0"
int main(int argc, char **argv)
{
	int fd;
	struct tty tt;
	while(1)
	{
		memset(&tt,0,sizeof(tt));
		fd=open(FF,O_RDONLY);//可能在su关闭fifo前回到这句，就不阻塞，
		avout("open");
		if(fd==-1)
		{
			averr("open");
		}
		read(fd,&tt,sizeof(tt));
		if(fork()==0)
		{
			if(fork()==0)
			{
				close(0);
				open(tt.tty0,O_RDONLY);
				close(1);
				open(tt.tty1,O_WRONLY);
				close(2);
				open(tt.tty2,O_WRONLY);
				setsid();
				execlp("sh","sh",NULL);
			}
			exit(0);
		}
		close(fd);
	}
	return 0;
}

/*****************************************************
	^> File Name: read.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/01 - 21:12:49
****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#define FF "fifo"

int main(void)
{
	fd_set rfds;
	struct timeval tv;
	int retval;
	int ch;
	int n=20;
	int i;
	int t;
	t=time(0);

	tv.tv_sec = 2;
	tv.tv_usec = 0;
	int fd;
	fd=open(FF,O_RDONLY);
	fprintf(stderr,"fd=%d,\n",fd);
	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);

	while(n-->0)
	{
		retval = select(fd+1, &rfds, NULL, NULL, NULL);
		fprintf(stderr,"ret=%d,\n",retval);
		for(i=0;i<retval;++i)
		{
			if(read(fd,&ch,1)==0)
			{
			}
			else
			write(1,&ch,1);
		}

	}
	exit(EXIT_SUCCESS);
}

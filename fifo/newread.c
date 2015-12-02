/*****************************************************
	^> File Name: newread.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/02 - 17:58:48
****************************************************/
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	char stdinpath[512]={0};
	char buf[512];
	int n;
	readlink("/proc/self/fd/0",stdinpath,sizeof(stdinpath)-1);
	printf("%s,\n",stdinpath);
	memset(buf,0,sizeof(buf));
	while(1)
	{
		if((n=read(STDIN_FILENO,buf,sizeof(buf)-1))>0)
		{
			buf[n]=0;
			write(STDOUT_FILENO,buf,strlen(buf));
		}
		else
		{
			close(0);
			open(stdinpath,O_RDONLY);
		}
	}
	return 0;
}


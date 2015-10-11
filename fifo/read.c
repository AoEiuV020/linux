/*****************************************************
	^> File Name: read.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/10/11 - 03:17:54
****************************************************/
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	char buf[512];
	int n;
	memset(buf,0,sizeof(buf));
	while(1)
	{
		if((n=read(STDIN_FILENO,buf,sizeof(buf)-1))>0)
		{
			buf[n]=0;
			write(STDOUT_FILENO,buf,strlen(buf));
		}
		lseek(STDIN_FILENO,0L,SEEK_CUR);
	}
	return 0;
}


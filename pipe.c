/*****************************************************
	^> File Name: pipe.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/09/11 - 13:04:11
****************************************************/

#include "aoeiuv.h"
int main(int argc, char **argv)
{
	int pfd[2];
	pid_t pid;
	char string[20]="hello...";
	char buf[80];
	avsyscall(pipe,pfd);
	avout("%d,%d;",pfd[0],pfd[1]);
	avls("/proc/self/fd");
	avsyscall(write,pfd[1],string,sizeof(string));
	avsyscall(read,pfd[0],buf,sizeof(buf)-1);
	avout("%s,",buf);
	sprintf(string,"fork...");
	pid=avsyscall(fork);
	if(pid==0)
	{
		avout("child write:");
		avsyscall(write,pfd[1],string,sizeof(string));
	}
	else
	{
		avout("farther read:");
		avsyscall(read,pfd[0],buf,sizeof(buf)-1);
		avout("%s,",buf);
	}
	return 0;
}

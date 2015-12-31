/*****************************************************
	^> File Name: setsid.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/02 - 18:11:21
****************************************************/
#include "aoeiuv.h"
int main(int argc, char **argv)
{
	pid_t pid;
	avout("pid=%d,ppid=%d,sid=%d,",getpid(),getppid(),getsid(getpid()));
	if(fork()>0)
	{
		avout("parent:");
		avout("pid=%d,ppid=%d,sid=%d,",getpid(),getppid(),getsid(getpid()));
		exit(0);
	}
	avout("child");
	avout("pid=%d,ppid=%d,sid=%d,",getpid(),getppid(),getsid(getpid()));
	pid=setsid();
	avout("pid=%d,ppid=%d,sid=%d,",getpid(),getppid(),getsid(getpid()));
	avout("setsid=%d,",pid);
	return 0;
}

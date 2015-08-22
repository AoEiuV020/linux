/*****************************************************
	^> File Name: fork.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/19 - 02:01:19
****************************************************/
#include "aoeiuv.h"
#include <stdio.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	pid_t pid;
	int status;
	if((pid=fork())<0)
	{
		averr("fork");
		exit(1);
	}
	if(pid==0)
	{
		avout("child %d",getpid());
		execlp("ps","ps",NULL);
		averr("child error");
		exit(127);
	}
	else
	{
		if((pid=waitpid(pid,&status,0))<0)
		{
			averr("waitpid");
		}
		else
		{
			avout("waitpid=%d",pid);
			avout("status=%d",status);
		}
		avout("father %d",getpid());
	}
	return 0;
}

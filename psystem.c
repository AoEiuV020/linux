/*****************************************************
	^> File Name: psystem.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/09/14 - 20:39:37
****************************************************/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/*
   psystem("ls -al /proc/%d/fd",getpid());
// */
int psystem(char *format,...)
{
	int err=0;
	va_list arg;
	static FILE *fpipe;/*FILE porinter for sand commond*/
	static pid_t cpid;/*parent pid*/
	static int pfd[2];
	static int init=1;
	if(init)
	{
		pipe(pfd);
		cpid=vfork();
		if(cpid<0)
		{
			perror("vfork error");
			return -1;
		}
		if(cpid==0)
		{
			dup2(pfd[0],STDIN_FILENO);
			close(pfd[0]);
			close(pfd[1]);
			execlp("sh","sh",NULL);
		}
		close(pfd[0]);
		fpipe=fdopen(pfd[1],"wb");
		init=0;
	}
	va_start(arg,format);
	vfprintf(fpipe,format,arg);
	fprintf(fpipe,"\n");
	fflush(fpipe);
	va_end(arg);
	return err;
}
int main(int argc, char **argv)
{
	char cmd[333]={0};
	while(fgets(cmd,sizeof(cmd),stdin))
	{
		psystem(cmd);
	}
	return 0;
}

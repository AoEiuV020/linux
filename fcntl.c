/*****************************************************
	^> File Name: fcntl.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/24 - 22:05:22
****************************************************/

#include "aoeiuv.h"
#include <sys/wait.h>
int main(int argc, char **argv)
{
	int fd,fd2;
	pid_t pid;
	int status;
	fd=avtmp(0);
	avout("%d",fd);
	avls("/proc/self/fd");
	fd2=fcntl(fd,F_DUPFD,80);
	avout("%d",fd2);
	avls("/proc/self/fd");
	close(fd);
	pid=fork();
	if(0==pid)
	{
		avout("filedes %d.FD_CLOEXEC:%d",fd2,fcntl(fd2,F_GETFD,FD_CLOEXEC));
		execlp("ls","ls","-al","/proc/self/fd",NULL);
	}
	waitpid(pid,&status,0);
	pid=fork();
	if(0==pid)
	{
		fcntl(fd2,F_SETFD,FD_CLOEXEC);
		avout("filedes %d.FD_CLOEXEC:%d",fd2,fcntl(fd2,F_GETFD,FD_CLOEXEC));
		execlp("ls","ls","-al","/proc/self/fd",NULL);
	}
	waitpid(pid,&status,0);
	avout("filedes %d.flags=%o",fd2,fcntl(fd2,F_GETFL,0)&O_ACCMODE);/* 0->O_RDONLY,1->WRONLY,2->RDWR;*/
	close(fd2);
	/*
	   F_GETOWN,F_SETOWN;
	   F_GETLK,F_SETLK,F_SETLKW;
	// */
	return 0;
}

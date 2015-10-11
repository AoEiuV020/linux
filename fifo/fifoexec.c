/*****************************************************
	^> File Name: fifoexec.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/10/11 - 03:01:53
****************************************************/
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h> //sprintf,
#include <stdlib.h> //exit,
#include <string.h> //memset,
int main(int argc, char **argv)
{
	/*
	   父进程，做点简单的处理，
	   argv[1]是要后台执行的服务程序，
	   argv[2]是作为后台服务程序输入流的命名管道，
	   argv[3]是作为后台服务程序输出流的命名管道，
	// */
	const char *cmd,*fifo_in,*fifo_out;
	pid_t pid;
	int pin[2];
	int fdfifoin,fdfifoout;
	char buf[512];
	int num;
	char path[512];

	cmd=argv[1];
	fifo_in=argv[2];
	fifo_out=argv[3];
	if(access(fifo_in,F_OK))
	{
		if(mkfifo(fifo_in,0660))
		{
			perror("mkfifo argv[2]");
		}
	}
	if(access(fifo_out,F_OK))
	{
		/*
		if(mkfifo(fifo_out,0660))
		{
			perror("mkfifo argv[3]");
		}
		// */
	}

	if(fork()==0)
	{
		/*
		   临时进程，产生子进程后就自杀，
		   然后孤儿进程自动被祖先进程领养，
		   这是为了得到“真×后台进程”
		   避免shell之类的无良父进程要求子进程陪葬，
		// */
		if(fork()==0)
		{
			/*
			   “真×后台进程”
			   用来和后台服务进程管道通信，"通信进程";

			   读路径存在"fifo_in"的命名管道fdfifoin，写入匿名管道pin[1],
			   pin[0]复制到子进程的标准输入，
			   由于命名管道,读完之后再读，不会阻塞，read直接返回0,
			   所以read返回0的情况重新打开命名管道，read阻塞直到下次连接，

			   通过检查"/proc/子进程/exe"是否存在判断子进程死了没，
			   如果子进程死了，就自杀，避免出现僵尸进程，
			// */
			pipe(pin);
			pid=vfork();
			if(pid==0)
			{
				/*
				   exec进程，
				   通过exec调用sh执行真正要后台运行的服务器程序，
				   调用sh是因为要运行的服务器程序可能有参数，
				   当成一个参数，一股脑的塞给sh就可以了，
				   服务器程序退出时这个sh也会退出，

				   标准输入重定向从匿名管道pin[0]读，
				   标准输出重定向与入命名管道fdfifouout,
				// */
				fdfifoout=open(fifo_out,O_WRONLY|O_CREAT|O_TRUNC,0666);
				dup2(fdfifoout,STDOUT_FILENO);
				dup2(pin[0],STDIN_FILENO);
				close(pin[0]);
				close(pin[1]);
				execlp("sh","sh","-c",cmd,NULL);
				//system(cmd);
			}
			fdfifoin=open(fifo_in,O_RDONLY);
			close(pin[0]);
			memset(buf,0,sizeof(buf));
			sprintf(path,"/proc/%d/exe",pid);
			while(!access(path,F_OK))
			{
				if((num=read(fdfifoin,buf,sizeof(buf)-1))>0)
				{
					buf[num]=0;
					write(pin[1],buf,strlen(buf));
				}
				else
				{
					close(fdfifoin);
					fdfifoin=open(fifo_in,O_RDONLY);
				}
			}
			/* 
			   通信进程死，
			// */
			exit(0);
		}
		/*
		   临时进程死，
		// */
		exit(0);
	}

	return 0;
}

/*****************************************************
	^> File Name: temp.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/14 - 15:44:00
****************************************************/
#include "aoeiuv.h"
#include <dirent.h>
int main(int argc, char **argv)
{
	char pfd[333];
	char fd[333];
	DIR *dp;
	struct dirent *dirp;
	sprintf(pfd,"/proc/%d/fd",getpid());
	sprintf(fd,"%s/33",pfd);
	if(symlink("/tmp/tmp",fd)==-1)
	{
		averr("symlink");
	}
	if((dp=opendir(pfd))==NULL)
	{
		perror("opendir");
		return 1;
	}
	while((dirp=readdir(dp))!=NULL)
	{
		printf("%lu:%lu,%hu,--%d++,%s;\n",dirp->d_ino,dirp->d_off,dirp->d_reclen,dirp->d_type,dirp->d_name);
	}
	return 0;
}

/*****************************************************
	^> File Name: ls.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/19 - 00:31:26
****************************************************/
#include <stdio.h>
#include <dirent.h>
int main(int argc, char **argv)
{
	const char *path=".";
	DIR *dp;
	struct dirent *dirp;
	if(argc>1)
	{
		path=argv[1];
	}
	if((dp=opendir(path))==NULL)
	{
		perror("opendir");
		return 1;
	}
	while((dirp=readdir(dp))!=NULL)
	{
		printf("%lu:%lu,%hu,--%d++,%s;\n",dirp->d_ino,dirp->d_off,dirp->d_reclen,dirp->d_type,dirp->d_name);
	}
	closedir(dp);
	return 0;
}

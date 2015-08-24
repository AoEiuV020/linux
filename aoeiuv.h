/*****************************************************
	^> File Name: aoeiuv.h
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/19 - 01:16:50
****************************************************/
#ifndef AOEIUV_H
#define AOEIUV_H

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <signal.h>
#include <dirent.h>

int averr(const char *format,...);
int avout(const char *format,...);
int avls(const char *path);
int lsfile(const char *file);
int lspath(const char *path);

int averr(const char *format,...)
{
	va_list arg;
	int err;
	va_start(arg,format);
	err=vfprintf(stderr,format,arg);
	fprintf(stderr,": %s\n",strerror(errno));
	va_end(arg);
	return err;
}
int avout(const char *format,...)
{
	va_list arg;
	int err;
	va_start(arg,format);
	fflush(stdout);
	fsync(STDOUT_FILENO);
	err=vfprintf(stdout,format,arg);
	fprintf(stdout,"\n");
	fflush(stdout);
	fsync(STDOUT_FILENO);
	va_end(arg);
	return err;
}
int avls(const char *path)
{
	struct stat st;
	stat(path,&st);
	if(S_ISDIR(st.st_mode))
	{
		return lspath(path);
	}
	else
	{
		return lsfile(path);
	}
}
int lsfile(const char *file)
{
	char link[256]={0};
	struct stat lst;
	errno=0;
	lstat(file,&lst);
	printf("%06o %d:%d %s",lst.st_mode,lst.st_uid,lst.st_gid,file);
	if(S_ISLNK(lst.st_mode))
	{
		memset(link,0,sizeof(link));
		readlink(file,link,sizeof(link)-1);
		printf(" -> %s",link);
	}
	printf("\n");
	return errno;
}
int lspath(const char *path)
{
	char file[256]={0};
	char link[256]={0};
	DIR *dp;
	struct dirent *dirp;
	struct stat lst;
	errno=0;
	if((dp=opendir(path))==NULL)
	{
		averr("opendir");
		return errno;
	}
	while((dirp=readdir(dp))!=NULL)
	{
		sprintf(file,"%s/%s",path,dirp->d_name);
		lstat(file,&lst);
		printf("%02d %06o %d:%d %s",dirp->d_type,lst.st_mode,lst.st_uid,lst.st_gid,dirp->d_name);
		if(dirp->d_type==10) /*DT_LNK*/
		/*if(S_ISLNK(lst.st_mode)) */
		{
			memset(link,0,sizeof(link));
			readlink(file,link,sizeof(link)-1);
			printf(" -> %s",link);
		}
		printf("\n");
	}
	closedir(dp);
	return errno;
}

#endif

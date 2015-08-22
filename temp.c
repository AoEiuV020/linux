/*****************************************************
	^> File Name: temp.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/14 - 15:44:00
****************************************************/
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
void lspath(const char *);
int rdopen(const char *);
int main(int argc, char **argv)
{
        int fd;
		fd=open("/tmp/tmp",O_RDONLY|O_CREAT);
        dup2(fd,88);
        close(fd);
        lspath("/proc/self/fd");
        return 0;
}
void lspath(const char *path)
{
        char file[333]={0};
        char link[333]={0};
        DIR *dp;
        struct dirent *dirp;
        struct stat lst;
        if((dp=opendir(path))==NULL)
        {
                perror("opendir");
                return errno;
        }
        while((dirp=readdir(dp))!=NULL)
        {
                sprintf(file,"%s/%s",path,dirp->d_name);
                lstat(file,&lst);
                printf("%02d %06o %d:%d %s",dirp->d_type,lst.st_mode,lst.st_uid,lst.st_gid,dirp->d_name);
                if(dirp->d_type==10) /*DT_LNK*/
                {
                        memset(link,0,sizeof(link));
                        readlink(file,link,sizeof(link)-1);
                        printf(" -> %s",link);
                }
                printf("\n");
        }
}

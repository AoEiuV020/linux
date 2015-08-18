/*****************************************************
	^> File Name: rename.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/18 - 22:28:03
****************************************************/
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(int argc, char **argv)
{
	FILE *fi;
	const char *name1="renameA";
	const char *name2="tmp/renameB";
	if((fi=fopen(name1,"r"))!=NULL)
	{
		if(rename(name1,name2)!=0)
		{
			fprintf(stderr,"mv %s to %s error : %s\n",name1,name2,strerror(errno));
		}
		else
		{
			printf("mv %s to %s ok...\n",name1,name2);
		}
	}
	else
	{
		if((fi=fopen(name2,"r"))!=NULL)
		{
			if(rename(name2,name1)!=0)
			{
				fprintf(stderr,"mv %s to %s error : %s\n",name2,name1,strerror(errno));
			}
			else
			{
				printf("mv %s to %s ok...\n",name2,name1);
			}
		}
	}

	return 0;
}

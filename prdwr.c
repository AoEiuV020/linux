/*****************************************************
	^> File Name: prdwr.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/23 - 02:20:17
****************************************************/
#include "aoeiuv.h"
int main(int argc, char **argv)
{
	int fd;
	const char *file="/tmp/tmp";
	char string[30]="AoEiuV020";
	fd=open(file,O_RDWR);
	if(fd==-1)
	{
		if(errno==ENOENT)
		{
			creat(file,0777);
			fd=open(file,O_RDWR);
		}
		else
		{
			averr("open");
			exit(errno);
		}
	}

	pwrite(fd,string,sizeof(string),30);
	pread(fd,string,sizeof(string),33);
	avout("%s;\n",string);
	return 0;
}

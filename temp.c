/*****************************************************
	^> File Name: temp.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/14 - 15:44:00
****************************************************/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#ifdef __ANDROID__
#define FB "/dev/graphics/fb0"
#else
#define FB "/dev/fb0"
#endif
int main(int argc, char **argv)
{
	int fb;
	FILE *fp;
	unsigned char buf=1;
	int i,r;
	/*我发现读取失败的那个手机的fb0的owner是system,于是来这几句试试，但也没用，，，*/
	//setuid(1000);
	struct stat st;
	stat(FB,&st);
	setuid(st.st_uid);
	//*/
	fb=open(FB,O_RDONLY);
	fp=fopen(FB,"rb");
	fflush(stdout);
	printf("%u,%d,%p;\n",getuid(),fb,fp);
	for(i=0;i<8888;++i)
	{
		r=read(fb,&buf,1);
		if(buf!=0)
		{
			printf("%d:%d,%x,\n",i,r,buf);
		}
		r=fread(&buf,1,1,fp);
		if(buf!=0)
		{
			printf("%d:%d,%x,\n",i,r,buf);
		}
	}
	return 0;
}

/*****************************************************
	^> File Name: talk.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/11/02 - 14:01:07
****************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void usage()
{
	printf("usage: talk tty\n");
	system("who");
	exit(0);
}
void check(const char *tty)
{
	if(-1==access(tty,W_OK))
	{
		perror("access");
		exit(-1);
	}

}
void message(FILE *fptty)
{
	char mytty[266]={0};
	if(-1==readlink("/proc/self/fd/1",mytty,sizeof(mytty)-1))
	{
		sprintf(mytty,"(none)");
	}
	fprintf(fptty,"Message from %s on %s \n",getenv("USER"),mytty);
}
void talk(FILE *fptty)
{
	char buf[1024];
	while(fgets(buf,sizeof(buf),stdin))
	{
		fprintf(fptty,"%s",buf);
	}
	fprintf(fptty,"EOF");
}

int main(int argc, char const *argv[])
{
	char tty[266];
	FILE *fptty;
	if(argc<2)
	{
		usage();
	}
	setgid(getegid());
	sprintf(tty,"/dev/%s",argv[1]);
	check(tty);
	fptty=fopen(tty,"wb");
	message(fptty);
	talk(fptty);

	return 0;
}

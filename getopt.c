/*****************************************************
	^> File Name: getopt.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/12 - 23:43:32
****************************************************/
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>
void usage()
{
	printf("usage:");
}
void showopt()
{
	printf("opt:%s,%d,%d,%d;\n",optarg,optind,opterr,optopt);
}
int main(int argc, char **argv)
{
	int opt;
	char *name="AoEiuV020";
	while((opt=getopt(argc,argv,"hn:"))!=-1)
	{
		showopt();
		switch(opt)
		{
			case 'n':
				name=optarg;
				break;
			case 'h':
			default :
				usage();
				return 1;
				break;
		}
	}
	printf("Hello %s...\n",name);
	return 0;
}

/*****************************************************
	^> File Name: getoptl.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/13 - 00:23:50
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
void version()
{
	printf("optarg:%s\n",optarg);
	printf("version:v0.0.0.0.1");
}
int main(int argc, char **argv)
{
	char *name="AoEiuV020";
	int optl;
	char *shortopt="hn:v::";
	struct option longopt[]={
		{"help",no_argument/*0*/,NULL,'h'},
		{"name",required_argument/*1*/,NULL,'n'},
		{"version",optional_argument/*2*/,NULL,'v'},
		{0,0,0,0}
	};
	while((optl=getopt_long(argc,argv,shortopt,longopt,NULL))!=-1)
	{
		showopt();
		switch(optl)
		{
			case 'n':
				name=optarg;
				break;
			case 'v':
				version();
				return 0;
			case 'h':
			default:
				usage();
				return 0;
		}
	}
	printf("Hi %s...\n",name);
	return 0;
}

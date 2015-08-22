/*****************************************************
	^> File Name: conf.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/22 - 17:51:01
****************************************************/
#include "aoeiuv.h"
#include <time.h>
#include <sys/times.h>
void timetest()
{
	int conf;
	int clk;
	struct tms tm;
	int i=0;
	getchar();
	while(i++<800000000);
	system("ping -c 3 localhost >/dev/null 2>&1");
	clk=clock();
	times(&tm);
	conf=sysconf(_SC_CLK_TCK);
	printf("%d,",conf);
	printf("%f,",1.0*clk/CLOCKS_PER_SEC);
	printf("%f;\n",1.0*clk/conf);
	printf("%f,",1.0*tm.tms_utime/clk);
	printf("%f,",1.0*tm.tms_stime/clk);
	printf("%f,",1.0*tm.tms_cutime/clk);
	printf("%f;\n",1.0*tm.tms_cstime/clk);
}
int main(int argc, char **argv)
{
	//timetest();
	printf("line max=%ld,",sysconf(_SC_LINE_MAX));
	printf("\n");
	printf("%ld,",pathconf("/dev/stdin",_PC_MAX_INPUT));
	printf("%ld,",pathconf("/dev/stdin",_PC_LINK_MAX));
	printf("\n");
	printf("%ld,",fpathconf(0,_PC_MAX_INPUT));
	printf("%ld,",fpathconf(0,_PC_LINK_MAX));
	printf("\n");
	return 0;
}

/*****************************************************
	^> File Name: temp.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/14 - 15:44:00
****************************************************/
#include "aoeiuv.h"
#include <sys/param.h>
int main(int argc, char **argv)
{
	avout("%d,%d",NOFILE,sysconf(_SC_OPEN_MAX));
	return 0;
}

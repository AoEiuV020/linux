/*****************************************************
	^> File Name: ls.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/19 - 00:31:26
****************************************************/
#include "aoeiuv.h"
int main(int argc, char **argv)
{
	const char *path=".";
	if(argc>1)
	{
		path=argv[1];
	}
	avls(path);
	return 0;
}

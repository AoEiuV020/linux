/*****************************************************
	^> File Name: ln.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/22 - 19:47:22
****************************************************/

#include "aoeiuv.h"
int main(int argc, char **argv)
{
	if(argc<3)
	{
		averr("argc");
	}
	avout("%d",symlink(argv[1],argv[2]));
	return 0;
}

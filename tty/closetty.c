/*****************************************************
	^> File Name: closetty.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/02 - 18:28:42
****************************************************/
#include "../aoeiuv.h"
int main(int argc, char **argv)
{
	close(0);
	close(1);
	close(2);
	sleep(222);
	return 0;
}

/*****************************************************
	^> File Name: access.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/26 - 23:17:12
****************************************************/

#include "aoeiuv.h"
int main(int argc, char **argv)
{
	avout("%d",access(__FILE__,F_OK));
	return 0;
}

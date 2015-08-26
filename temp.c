/*****************************************************
	^> File Name: temp.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/14 - 15:44:00
****************************************************/
#include "aoeiuv.h"
int main(int argc, char **argv)
{
	avsyscall(unlink,"chmod_A");
//	avsyscall(creat,"chmod_A",0666);
	avsyscall(open,"chmod_A",O_RDWR|O_CREAT);
	return 0;
}

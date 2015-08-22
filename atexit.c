/*****************************************************
	^> File Name: atexit.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/19 - 02:31:07
****************************************************/
#include "aoeiuv.h"
#include <stdio.h>
void foo();
void fun();
int main(int argc, char **argv)
{
	atexit(foo);
	atexit(fun);
	atexit(fun);
	return 0;
}
void foo()
{
	avout("foo:exiting...");
}
void fun()
{
	avout("fun:exiting...");
}

/*****************************************************
	^> File Name: temp.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/14 - 15:44:00
****************************************************/
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int mask;
	umask(0077);
	system("bash");
	return 0;
}

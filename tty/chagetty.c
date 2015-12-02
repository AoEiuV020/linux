/*****************************************************
	^> File Name: chagetty.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/02 - 18:30:12
****************************************************/
#include "../aoeiuv.h"
#define TTY "/dev/pts/0"
int main(int argc, char **argv)
{
	close(0);
	open(TTY,O_RDONLY);
	close(1);
	open(TTY,O_WRONLY);
	close(2);
	open(TTY,O_WRONLY);
	avout("hello...");
	char str[50];
	while(~scanf("%s",str))
	{
		avout("%s",str);
	}
	return 0;
}

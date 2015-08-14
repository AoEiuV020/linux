/*****************************************************
	^> File Name: console.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/08 - 08:23:14
****************************************************/
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
void getsize(unsigned short int *row,unsigned short int *col,unsigned short int *xpixel,unsigned short int *ypixel)
{
	struct winsize size;
	ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
	*row=size.ws_row;
	*col=size.ws_col;
	*xpixel=size.ws_xpixel;
	*ypixel=size.ws_ypixel;
}
int main(int argc, char **argv)
{
	unsigned short int row,col,x,y;
	getsize(&row,&col,&x,&y);
	printf("%u,%u,%u,%u;\n",row,col,x,y);
	return 0;
}

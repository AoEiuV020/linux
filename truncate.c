/*****************************************************
	^> File Name: truncate.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/09/08 - 17:35:30
****************************************************/

#include "aoeiuv.h"
int main(int argc, char **argv)
{
	int fd;
/*	
fd= ( (((avscret=(open("temp", 02 | 0100 ,0644)))==-1)?(averr("open"),exit( (*__errno_location ())),1):0),avscret );
 ( (((avscret=(open("temp", 02 | 0100 ,0644)))==-1)?(averr("open"),exit( (*__errno_location ())),1):0),avscret );
    // */
fd=avsyscall(open,"temp",O_RDWR|O_CREAT,0644); 
printf("%d,\n",fd);
	return 0;
}

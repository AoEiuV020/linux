/*****************************************************
	^> File Name: chmod.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/27 - 03:14:11
****************************************************/

#include "aoeiuv.h"
int main(int argc, char **argv)
{
	int fd;
	avsyscall(open,"chmod_A",O_RDONLY|O_CREAT,0666);
	fd=avscret;
	avls("chmod_A");
	avsyscall(chmod,"chmod_A",0000);
	avls("chmod_A");
	avsyscall(fchmod,fd,0777);
	close(fd);
	avls("chmod_A");
	avls("/dev/fd");
	avsyscall(unlink,"chmod_A");
	return 0;
}

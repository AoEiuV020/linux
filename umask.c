/*****************************************************
	^> File Name: umask.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/26 - 23:29:03
****************************************************/

#include "aoeiuv.h"
#define UMASK(NAME) "umask_"#NAME
int main(int argc, char **argv)
{
	int mask;
	mask=umask(0022);
	mask=umask(mask);

	avout("mode=07777");
	avout("A:umask==%04o",mask);
	unlink(UMASK(A));
	avsyscall(creat,UMASK(A),07777);

	mask=umask(0000);
	avout("B:umask==%04o",0000);
	unlink(UMASK(B));
	avsyscall(creat,UMASK(B),07777);

	umask(mask);
	avout("C:umask==%04o",mask);
	unlink(UMASK(C));
	avsyscall(creat,UMASK(C),07777);

	avsystem("ls -al %s",UMASK(*));
	return 0;
}


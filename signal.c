/*****************************************************
	^> File Name: signal.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/19 - 02:44:27
****************************************************/
#include "aoeiuv.h"
static void sig(int siginfo)
{
	avout("siginfo=%d",siginfo);
}
int main(int argc, char **argv)
{
	if(signal(SIGINT,sig)==SIG_ERR)
	{
		averr("sigint");
	}
	if(signal(SIGKILL,sig)==SIG_ERR)
	{
		averr("sigkill");
	}
	if(signal(SIGQUIT,SIG_IGN)==SIG_ERR)
	{
		averr("sigquit");
	}
	if(signal(SIGTERM,sig)==SIG_ERR)
	{
		averr("sigterm");
	}
	for(;;);
	avout("OK...");
	return 0;
}

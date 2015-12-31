/*****************************************************
	^> File Name: hello.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/11/30 - 17:26:53
****************************************************/
#include <stdio.h>
#include <event.h>
void fun(int sock,short event,void *arg)
{
	static int i=4;
	printf("sock=%d,event=%hd,arg=%p...\n",sock,event,arg);
	struct timeval tv;
	tv.tv_sec=1;
	tv.tv_usec=0;
	--i&&event_add((struct event*)arg,&tv);
}
int main(int argc, char **argv)
{
	event_init();
	struct event evt;
	evtimer_set(&evt,fun,&evt);
	struct timeval tv;
	tv.tv_sec=1;
	tv.tv_usec=0;
	event_add(&evt,&tv);
	event_dispatch();
	printf("end...\n");
	return 0;
}

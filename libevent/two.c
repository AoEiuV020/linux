/*****************************************************
	^> File Name: two.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/02 - 16:00:06
****************************************************/
#include <stdio.h>
#include <event.h>
void foo(int sock,short event,void *arg)
{
	printf("foo...\n");
}
void bar(int sock,short event,void *arg)
{
	printf("bar...\n");
}

int main(int argc, char **argv)
{
	struct timeval tv;
	tv.tv_sec=0;
	tv.tv_usec=500000;
	event_init();
	struct event evt;
	evtimer_set(&evt,foo,NULL);
	event_add(&evt,&tv);
	struct event evtb;
	evtimer_set(&evtb,bar,NULL);
	tv.tv_usec=0;
	event_add(&evtb,&tv);
	event_dispatch();
	printf("end...\n");
	return 0;
}

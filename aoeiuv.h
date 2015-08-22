/*****************************************************
	^> File Name: aoeiuv.h
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/19 - 01:16:50
****************************************************/
#ifndef AOEIUV_H
#define AOEIUV_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <signal.h>

int averr(const char *format,...)
{
	va_list arg;
	int err;
	va_start(arg,format);
	err=vfprintf(stderr,format,arg);
	fprintf(stderr,": %s\n",strerror(errno));
	va_end(arg);
	return err;
}
int avout(const char *format,...)
{
	va_list arg;
	int err;
	va_start(arg,format);
	fflush(stdout);
	err=vfprintf(stdout,format,arg);
	fprintf(stdout,"\n");
	fflush(stdout);
	va_end(arg);
	return err;
}

#endif

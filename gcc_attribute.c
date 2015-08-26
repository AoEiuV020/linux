/*****************************************************
	^> File Name: gcc_attribute.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/26 - 12:56:59
****************************************************/

#include "aoeiuv.h"
inline void fun_inline() __attribute__((always_inline));
int main(int argc, char **argv)
{
	struct A
	{
		char c;
		int i;
		char c1;
		float f;
		char c3;
		double d;
		char c4;
	}__attribute__((packed))a;
	struct B
	{
		char c;
		int i;
		char c1;
		float f;
		char c3;
		double d;
		char c4;
	}b;
	avout("%d,%d;",sizeof(a),sizeof(b));
	char ca1;
	char ca2;
	char ca3;
	char ca4;
	char cb1 __attribute__((aligned(16)));
	char cb2 __attribute__((aligned(16)));
	char cb3 __attribute__((aligned(16)));
	char cb4 __attribute__((aligned(16)));
	avout("%p,%p,%p,%p",&ca1,&ca2,&ca3,&ca4);
	avout("%p,%p,%p,%p",&cb1,&cb2,&cb3,&cb4);
	return 0;
}
void fun_inline()
{
	asm("nop");
}

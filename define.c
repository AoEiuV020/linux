/*****************************************************
	^> File Name: define.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/26 - 20:52:05
****************************************************/

#include "aoeiuv.h"
#define PRINTS(NAME) printf(#NAME"\n") 
#define PRINTC(CH) printf("%c\n",'#CH') 
/*#@CH*/
#define FUN(A,B) A##B
#if __STDC_VERSION__ >= 199901L
#define FUNARG(A,...) printf("..."A,__VA_ARGS__)
#else
#define FUNARG printf
#endif
int main(int argc, char **argv)
{
	avout("__STDC_VERSION__==%ld",__STDC_VERSION__);
	PRINTS(AoEiuV);
	PRINTC(o);
	FUN(pri,ntf)("printf\n");
	FUNARG("%d\n",1234);
	return 0;
}

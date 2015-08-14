/*****************************************************
	^> File Name: framebuffer.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/14 - 14:02:12
****************************************************/
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#ifdef __ANDROID__
#define FB "/dev/graphics/fb0"
#else
#define FB "/dev/fb0"
#endif
int main(int argc, char **argv)
{
	int fb;
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	fb = open(FB, O_RDONLY);
	if(fb==-1)
	{
		printf("are you root?\n");
		return -1;
	}
	ioctl(fb, FBIOGET_FSCREENINFO, &finfo);
	ioctl(fb, FBIOGET_VSCREENINFO, &vinfo);
	printf("fb=%d\n", fb);
	printf("%u*%u=%u\n", vinfo.xres, vinfo.yres, vinfo.xres * vinfo.yres);
	printf("vinfo.bits_per_pixel=%u\n", vinfo.bits_per_pixel);
	printf("finfo.line_length=%u\n",finfo.line_length);
	printf("vinfo.xres*vinfo.bits_per_pixel/8=%u\n",vinfo.xres*vinfo.bits_per_pixel/8);
	printf("\n");
#define COLOR(C) printf(#C":%u,%u,%u;\n",vinfo.C.offset,vinfo.C.length,vinfo.C.msb_right)
	COLOR(red);
	COLOR(green);
	COLOR(blue);
	COLOR(transp);
	printf("\n");
	printf("%u*%u=%u\n", vinfo.xres_virtual, vinfo.yres_virtual, vinfo.xres_virtual * vinfo.yres_virtual);
	printf("%u*%u=%u\n", vinfo.xoffset, vinfo.yoffset, vinfo.xoffset * vinfo.yoffset);
#define VU32(MEN) printf(#MEN":%u\n",vinfo.MEN)
#define V1(x,...) VU32(x);V2(__VA_ARGS__) 
#define V2(x,...)
	VU32(grayscale);
	VU32(nonstd);
	VU32(activate);
	V1(height);
	fflush(stdout);
	return 0;
}

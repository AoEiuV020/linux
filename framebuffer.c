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
#define VARU32(MEN) printf(#MEN":%u\n",vinfo.MEN)
	VARU32(grayscale);
	VARU32(nonstd);
	VARU32(activate);
	VARU32(height);
	VARU32(width);
	VARU32(accel_flags);
	VARU32(pixclock);
	VARU32(left_margin);
	VARU32(right_margin);
	VARU32(upper_margin);
	VARU32(lower_margin);
	VARU32(hsync_len);
	VARU32(vsync_len);
	VARU32(sync);
	VARU32(vmode);
	VARU32(rotate);
	VARU32(colorspace);
	VARU32(reserved[3]);
	printf("\n");
#define FARU32(MEN) printf(#MEN":%u\n",finfo.MEN)
	printf("%s\n",finfo.id);
	FARU32(smem_len);
	FARU32(type);
	FARU32(type_aux);
	FARU32(visual);
	FARU32(xpanstep);
	FARU32(ypanstep);
	FARU32(line_length);
	FARU32(mmio_len);//
	FARU32(accel);
	FARU32(capabilities);
	FARU32(reserved[1]);
	printf("\n");
	fflush(stdout);
	return 0;
}

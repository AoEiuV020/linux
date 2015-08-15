/*****************************************************
	  ^> File Name: jpeg.c
	  ^> Author: AoEiuV020
	  ^> Mail: 490674483@qq.com
	  ^> Created Time: 2015/05/23 - 13:54:47 
 ****************************************************/
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <jpeglib.h>
#include <unistd.h>
#include <stdlib.h>
#define JPG "screen.jpg"
#ifdef __ANDROID__
#define FB "/dev/graphics/fb0"
#else
#define FB "/dev/fb0"
#endif
int main()
{
	int fb;
	fb = open(FB, O_RDONLY);
	if(fb==-1)
	{
		printf("are you root?\n");
		return -1;
	}
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	ioctl(fb, FBIOGET_FSCREENINFO, &finfo);
	ioctl(fb, FBIOGET_VSCREENINFO, &vinfo);
	printf("uid=%u,euid=%u;\n",getuid(),geteuid());
	printf("fb=%d\n", fb);
	printf("%u*%u=%u\n", vinfo.xres, vinfo.yres, vinfo.xres * vinfo.yres);
	printf("vinfo.bits_per_pixel=%u\n", vinfo.bits_per_pixel);
	printf("finfo.line_length=%u\n",finfo.line_length);
	printf("vinfo.xres*vinfo.bits_per_pixel/8=%u\n",vinfo.xres*vinfo.bits_per_pixel/8);
	fflush(stdout);
	unsigned char *screen=(unsigned char*)malloc(vinfo.yres*vinfo.xres*3);
	for(int i=0;i<vinfo.yres;++i)
	{
		for(int j=0;j<vinfo.xres;++j)
		{
			unsigned char rgb[4];
			int index=i*vinfo.xres*3+j*3;
			read(fb,rgb,4);
			screen[index]=rgb[vinfo.red.offset/8];
			screen[index+1]=rgb[vinfo.green.offset/8];
			screen[index+2]=rgb[vinfo.blue.offset/8];
			/*
			   screen[index]=0x00;
			   screen[index+1]=0x00;
			   screen[index+2]=0x00;
			 */
		}
		lseek(fb,finfo.line_length-vinfo.xres*vinfo.bits_per_pixel/8,SEEK_CUR);
	}
	struct jpeg_compress_struct jcs;
	struct jpeg_error_mgr jem;
	jcs.err = jpeg_std_error(&jem);
	jpeg_create_compress(&jcs);
	FILE *fjpg = fopen(JPG, "wb");
	jpeg_stdio_dest(&jcs, fjpg);
	jcs.image_width = vinfo.xres;
	jcs.image_height = vinfo.yres;
	jcs.input_components = 3;
	jcs.in_color_space = JCS_RGB;
	jpeg_set_defaults(&jcs);
	jpeg_start_compress(&jcs, TRUE);
	JSAMPROW row_pointer;
	while (jcs.next_scanline < jcs.image_height)
	{
		row_pointer = screen+jcs.next_scanline * jcs.image_width * 3;
		jpeg_write_scanlines(&jcs, &row_pointer, 1);
	}
	jpeg_finish_compress(&jcs);
	jpeg_destroy_compress(&jcs);
	free(screen);
	close(fb);
	return 0;
}

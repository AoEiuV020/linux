/*****************************************************
	^> File Name: jpegview.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/08/14 - 18:30:55
****************************************************/
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <jpeglib.h>
#include <unistd.h>
#include <stdlib.h>
#ifdef __ANDROID__
#define FB "/dev/graphics/fb0"
#else
#define FB "/dev/fb0"
#endif
const char *JPG="jpg.jpg";
void jpginfo(j_decompress_ptr jdp)
{
	printf("%u*%u=%u\n",jdp->image_width,jdp->image_height,jdp->image_width*jdp->image_height);
	printf("%u*%u=%u\n",jdp->output_width,jdp->output_height,jdp->output_width*jdp->output_height);
	printf("num_components:%d\n",jdp->num_components);
	printf("output_components:%d\n",jdp->output_components);
	printf("out_color_space:%d\n",jdp->out_color_space);
	printf("actual_number_of_colors:%d\n",jdp->actual_number_of_colors);
	printf("\n");
	fflush(stdout);
}
void fbinfo(struct fb_var_screeninfo vinfo,struct fb_fix_screeninfo finfo)
{
	printf("uid=%u,euid=%u;\n",getuid(),geteuid());
	printf("%u*%u=%u\n", vinfo.xres, vinfo.yres, vinfo.xres * vinfo.yres);
	printf("vinfo.bits_per_pixel=%u\n", vinfo.bits_per_pixel);
	printf("finfo.line_length=%u\n",finfo.line_length);
	printf("vinfo.xres*vinfo.bits_per_pixel/8=%u\n",vinfo.xres*vinfo.bits_per_pixel/8);
	printf("\n");
	fflush(stdout);
}
int main(int argc, char **argv)
{
	int fb;
	fb = open(FB, O_RDWR);
	if(fb==-1)
	{
		printf("are you root?\n");
		return -1;
	}
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	ioctl(fb, FBIOGET_FSCREENINFO, &finfo);
	ioctl(fb, FBIOGET_VSCREENINFO, &vinfo);
	fbinfo(vinfo,finfo);
	if(argc>1)
	{
		JPG=argv[1];
	}
	FILE *fjpg;
	fjpg=fopen(JPG,"rb");
	if(fjpg==NULL)
	{
		printf("%s exist?\n",JPG);
		return -2;
	}
	struct jpeg_decompress_struct jdinfo;
	struct jpeg_error_mgr jerr;
	jdinfo.err=jpeg_std_error(&jerr);
	jpeg_create_decompress(&jdinfo);
	jpeg_stdio_src(&jdinfo,fjpg);
	jpeg_read_header(&jdinfo,TRUE);
	jdinfo.out_color_space=JCS_RGB;
	jpeg_start_decompress(&jdinfo);
	jpginfo(&jdinfo);
	unsigned char *jpglinebuf=(unsigned char*)malloc(jdinfo.output_width*jdinfo.output_components);
	unsigned char *fblinebuf=(unsigned char*)malloc(finfo.line_length);
	int fbindex,jpgindex;
	int i,j;
	for(i=0;jdinfo.output_scanline<jdinfo.output_height;++i)
	{
		jpeg_read_scanlines(&jdinfo,&jpglinebuf,1);
		for(j=0;j<jdinfo.output_width;++j)
		{
			fbindex=j*(vinfo.bits_per_pixel/8);
			jpgindex=j*jdinfo.output_components;
			fblinebuf[fbindex+vinfo.red.offset/8]=jpglinebuf[jpgindex+0];
			fblinebuf[fbindex+vinfo.green.offset/8]=jpglinebuf[jpgindex+1];
			fblinebuf[fbindex+vinfo.blue.offset/8]=jpglinebuf[jpgindex+2];
		}
		lseek(fb,finfo.line_length*i,SEEK_SET);
		write(fb,fblinebuf,jdinfo.output_width*(vinfo.bits_per_pixel/8));
	}
	jpeg_finish_decompress(&jdinfo);
	jpeg_destroy_decompress(&jdinfo);
	return 0;
}

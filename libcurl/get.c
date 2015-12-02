/*****************************************************
	^> File Name: get.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/11/30 - 17:38:49
****************************************************/
#include <stdio.h>
#include <curl/curl.h>
int main(int argc, char **argv)
{
	CURL *curl=curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,"http://rc.sastlinux.cn");
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	return 0;
}

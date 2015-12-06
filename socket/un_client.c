/*****************************************************
	^> File Name: un_client.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/05 - 19:29:14
****************************************************/
#include "../aoeiuv.h"
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h> //inet_addr
#include <sys/select.h>
#include <event.h>
int main(int argc, char **argv)
{
	char PATH[256]="sock";
	if(argc>1)
	{
		sprintf(PATH,"%s",argv[1]);
	}
	struct sockaddr_un sau;
	sau.sun_family=AF_UNIX;
	sprintf(sau.sun_path,"%s",PATH);
	favout(stderr,"family=%x,path=%s;",sau.sun_family,sau.sun_path);
	int cfd;
	cfd=avsyscall(socket,AF_UNIX,SOCK_STREAM,0);
	favout(stderr,"cfd=%d,",cfd);
	avsyscall(connect,cfd,(const struct sockaddr *)&sau,sizeof(sau));
	
	fd_set set,readset;//socketfd,stdinfd,
	int fdmax;
	FD_ZERO(&set);
	FD_SET(STDIN_FILENO,&set);
	FD_SET(cfd,&set);
	fdmax=cfd;
	char buf[512];
	int len;
	while(1)
	{
		readset=set;
		avsyscall(select,fdmax+1,&readset,NULL,NULL,NULL);
		if(FD_ISSET(STDIN_FILENO,&readset))
		{
			if(0<(len=avsyscall(read,STDIN_FILENO,buf,sizeof(buf)-1)))
			{
				buf[len]=0;
				avsyscall(write,cfd,buf,len);
			}
			else
			{
				favout(stderr,"end of stdin...");
				FD_CLR(STDIN_FILENO,&set);
				avsyscall(close,STDIN_FILENO);
				break;
			}
		}
		if(FD_ISSET(cfd,&readset))
		{
			if(0<(len=avsyscall(read,cfd,buf,sizeof(buf)-1)))
			{
				buf[len]=0;
				avsyscall(write,STDOUT_FILENO,buf,len);
			}
			else
			{
				favout(stderr,"end of %d...",cfd);
				FD_CLR(cfd,&set);
				avsyscall(close,cfd);
				break;
			}
		}

	}

	return 0;
}

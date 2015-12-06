/*****************************************************
	^> File Name: un_server.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/06 - 17:05:55
****************************************************/
#include "../aoeiuv.h"
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
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
	int sfd;
	sfd=avsyscall(socket,AF_UNIX,SOCK_STREAM,0);
	favout(stderr,"sfd=%d,",sfd);
	int flag=1;
	avsyscall(setsockopt,sfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
	avsyscall(bind,sfd,(const struct sockaddr *)&sau,sizeof(sau));
	avsyscall(listen,sfd,3);

	fd_set set,readset;//socketfd,connectfd,
	int fdmax;
	FD_ZERO(&set);
	FD_SET(STDIN_FILENO,&set);
	FD_SET(sfd,&set);
	fdmax=sfd;
	char buf[512];
	int len;
	int newfd;
	int fdi;//index,
	struct sockaddr_in csai;
	socklen_t clen;
	while(1)
	{
		readset=set;
		avsyscall(select,fdmax+1,&readset,NULL,NULL,NULL);
		for(fdi=0;fdi<=fdmax;++fdi)
		{
			if(FD_ISSET(fdi,&readset))
			{
				if(fdi==STDIN_FILENO)
				{
					if(0<(len=avsyscall(read,STDIN_FILENO,buf,sizeof(buf)-1)))
					{
						buf[len]=0;
						if(!strcmp(buf,"exit\n"))
						{
							favout(stderr,"logout...");
							exit(0);
						}
					}
					else
					{
						favout(stderr,"end of stdin...");
						FD_CLR(STDIN_FILENO,&set);
						avsyscall(close,STDIN_FILENO);
					}
				}
				else if(fdi==sfd)
				{
					newfd=avsyscall(accept,sfd,(struct sockaddr *)&csai,&clen);
					favout(stderr,"new client,%s;",sau.sun_path);
						FD_SET(newfd,&set);
						if(newfd>fdmax)
					{
						fdmax=newfd;
					}
				}
				else
				{
					if(0<(len=avsyscall(read,fdi,buf,sizeof(buf)-1)))
					{
						buf[len]=0;
						avsyscall(write,STDOUT_FILENO,buf,len);
					}
					else
					{
						favout(stderr,"end of %d...",fdi);
						FD_CLR(fdi,&set);
						avsyscall(close,fdi);
					}
				}
			}
		}
	}
	return 0;
}

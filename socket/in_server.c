/*****************************************************
	^> File Name: in_server.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/12/04 - 21:07:15
****************************************************/
#include "../aoeiuv.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> //inet_addr
#include <sys/select.h>
#include <event.h>
int main(int argc, char **argv)
{
	char IP[30]="127.0.0.1";
	unsigned short PORT=45678;
	if(argc>1)
	{
		sprintf(IP,"%s",argv[1]);
	}
	if(argc>2)
	{
		sscanf(argv[2],"%hu",&PORT);
	}
	struct sockaddr_in sai;
	sai.sin_family=AF_INET;
	sai.sin_port=htons(PORT);
	sai.sin_addr.s_addr=inet_addr(IP);
	avout("family=%x,port=%hu,addr=%s;",sai.sin_family,ntohs(sai.sin_port),inet_ntoa(sai.sin_addr));
	int sfd;
	sfd=avsyscall(socket,AF_INET,SOCK_STREAM,0);
	avout("sfd=%d,",sfd);
	avsyscall(bind,sfd,(const struct sockaddr *)&sai,sizeof(sai));
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
							avout("logout...");
							exit(0);
						}
					}
					else
					{
						FD_CLR(STDIN_FILENO,&set);
						avsyscall(close,STDIN_FILENO);
					}
				}
				else if(fdi==sfd)
				{
					newfd=avsyscall(accept,sfd,(struct sockaddr *)&csai,&clen);
					avout("new client,%s:%hu",inet_ntoa(csai.sin_addr),ntohs(csai.sin_port));
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
						FD_CLR(sfd,&set);
						avsyscall(close,sfd);
					}
				}
			}
		}
	}
	return 0;
}

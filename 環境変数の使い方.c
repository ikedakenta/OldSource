#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(void){
	char *q,buff[30];
	q=getenv("LOGNAME");
	if(q!=NULL)printf("LOGNAME:%s\n",q);
	q=getenv("USER");
	if(q!=NULL)printf("USER:%s\n",q);
	q=getenv("PATH");
	if(q!=NULL)printf("PATH:%s\n",q);
	q=getenv("HZ");
	if(q!=NULL)printf("HZ:%s\n",q);
	q=getenv("HOME");
	if(q!=NULL)printf("HOME:%s\n",q);
	q=getenv("REMOTE_USER");
	if(q!=NULL)printf("REMOTE_USER:%s\n",q);
	q=getenv("LOGIN");
	if(q!=NULL)printf("LOGIN:%s\n",q);
	q=getenv("USERNAME");
	if(q!=NULL)printf("USERNAME:%s\n",q);
	gets(buff);
}

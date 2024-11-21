#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
int main(int argc,char *argv[])
{
	DIR *dp;
	struct dirent *dent;
	int reply;
	struct stat buff;
	dp=opendir(".");
	if(dp==NULL)
	{
		printf("Unable to open directory\n");
		return 1;
	}
	dent=readdir(dp);
	while(dent!=NULL)
	{
		reply=stat(dent->d_name,&buff);
		if(reply<0)
		printf("\nError");
		else
		printf("\n %s\t",dent->d_name);
		char *time=ctime(&buff.st_ctime);
		printf("nTime:%s",time);
		printf("Creation Month:%c%c%c\n\n",time[4],time[5],time[6]);
		dent=readdir(dp);
	}
	closedir(dp);
}
		

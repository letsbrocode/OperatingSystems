#include<stdio.h>
#include<dirent.h>
void main(){
	DIR *dir;
	char path[100];
	//Read the Folder Name
	printf("Enter Name Of Directory:");
	scanf("%s",&path);
	struct dirent *d;
	dir=opendir(path);
	while((d=readdir(dir))!=NULL)
		printf("Inode no:%d\n Folder Name:%s",d->d_ino,d->d_name);
}

#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
void main(){
	struct stat *s;
	char path[100];
	s=(struct stat *)malloc(sizeof(struct stat));
	//Read Name Of File
	printf("Enter the name of file:");
	scanf("%s",path);
	stat(path,s);
	printf("Sno: %ld\n Block size: %ld \n Mode: %d \n Uid: %d \n Dev:%ld",s->st_ino,s->st_blksize,s->st_mode,s->st_uid,s->st_dev);
}

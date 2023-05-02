#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
void main(){
	int pid;
	pid=fork();
	if(pid<0){
		printf("Error!");
		exit(1);
	}
	if(pid==0){
		printf("CHILD PROCESS \n");
		printf("Process id: %d\n", getpid());
		printf("Parent Process id: %d\n", getppid());
	}else{
		wait();
		printf("PARENT PROCESS \n");
		printf("Process id: %d\n", getpid());
		printf("Parent Process id: %d\n", getppid());
	}
}

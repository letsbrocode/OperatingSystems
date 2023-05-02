#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
void main(){
	int shmid, i=0, key;
	int *shm, *it, a[10];
	float shma=1000;
	//Read the Key
	printf("Enter the key:");
	scanf("%d", &key);
	shmid=shmget(key, shma, IPC_CREAT|0666);
	shm=shmat(shmid, NULL, 0); 
	it=shm;
	//Print 10 Numbers
	printf("The Elements Are:");
	for (i=0;i<10;i++)
		printf("%d\t", it[i]);
}

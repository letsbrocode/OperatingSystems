#include<stdio.h>
struct p{
	char name[20];
	int wt,bt,tt;
}p[20];
void main(){
	int i,n,wtsum=0,ttsum=0;
	float avgwt,avgtt;
	//Reading No: of Process
	printf("Enter No: of Process:");
	scanf("%d",&n);
	//Reading Name And Burst Time
	for(i=0;i<n;i++){
		printf("Enter Name of Process:");
		scanf("%s",p[i].name);
		printf("Enter the Burst Time:");
		scanf("%d",&p[i].bt);
		p[i].wt=0;
		p[i].tt=0;
	}
	//Print the Process Name,Burst Time,Waiting Time and Turnaround Time in Table Format By Yourself
	//Calculating Waiting Time and Turnaround Time
	for(i=0;i<n;i++){
		p[i].wt=p[i-1].wt+p[i-1].bt;
		p[i].tt=p[i].wt+p[i].bt;
		wtsum+=p[i].wt;
		ttsum+=p[i].tt;
	}
	//Print the Process Name,Burst Time,Waiting Time and Turnaround Time in Table Format By Yourself
	avgwt=(float)wtsum/n;
	avgtt=(float)ttsum/n;
	//Print Avgwt,Avgtt,Wtsum and Ttsum By Yourself
	//Printing Gantt Chart
	printf("Gantt Chart\n");
	for(i=0;i<n;i++)
		printf("%s(%d)-->",p[i].name,p[i].tt);
}

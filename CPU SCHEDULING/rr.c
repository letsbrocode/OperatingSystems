#include<stdio.h>
struct p{
	char name[20];
	int wt,bt,tt,rt;
}p[20],temp;
void main(){
	int i,j,n,wtsum=0,ttsum=0,count=0,a=0,qt;
	float avgwt,avgtt;
	//Reading No: of Process
	printf("Enter No: of Process:");
	scanf("%d",&n);
	//Reading the Time Slice
	printf("Enter the Time Slice:");
	scanf("%d",&qt);
	//Reading Name And Burst Time
	for(i=0;i<n;i++){
		printf("Enter Name of Process:");
		scanf("%s",p[i].name);
		printf("Enter the Burst Time:");
		scanf("%d",&p[i].bt);
		p[i].wt=0;
		p[i].tt=0;
		p[i].rt=p[i].bt;
	}
	//Print the Process Name,Burst Time,Waiting Time and Turnaround Time in Table Format By Yourself
	//Printing Gantt Chart and Calculating Turnaround Time
	printf("Gantt Chart\n");
	while(1){
		for(i=0;i<n;i++){
			if(p[i].rt==0){
				count++;
				continue;
			}else if(p[i].rt>qt){
				p[i].rt-=qt;
				a+=qt;
			}else{
				a+=p[i].rt;
				p[i].rt=0;
			}
			p[i].tt=a;
			printf("%s(%d)-->",p[i].name,p[i].tt);
		}
		if(count==n)
			break;
	}
	//Calculating Waiting Time
	for(i=0;i<n;i++){
		p[i].wt=p[i].tt-p[i].bt;
		wtsum+=p[i].wt;
		ttsum+=p[i].tt;
	}
	//Print the Process Name,Burst Time,Waiting Time and Turnaround Time in Table Format By Yourself
	avgwt=(float)wtsum/n;
	avgtt=(float)ttsum/n;
	//Print Avgwt,Avgtt,Wtsum and Ttsum By Yourself
}

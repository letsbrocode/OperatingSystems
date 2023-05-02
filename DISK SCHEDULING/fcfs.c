#include<stdio.h> 
#include<stdlib.h> 
void main(){ 
	int i,m,n,s[30],c[30],tssum=0;
	//Reading the Total Size
	printf("Enter the Total size:"); 
	scanf("%d",&m);
	//Reading the Sequence
	printf("Enter the sequence:"); 
	for(i=0;i<m;i++) 
		scanf("%d",&s[i]);
	//Reading the Head Position 
	printf("Enter the head position:"); 
	scanf("%d",&n);
	//Head-Starting Element of Array
	c[0]=abs(n-s[0]); 
	printf("Head moves from %d to %d seek time=%d",n,s[0],c[0]);
	//Fcfs Head Movement Logic
	for(i=1;i<m;i++){ 
		c[i]=abs(s[i]-s[i-1]); 
		printf("\nHead moves from %d to %d and seek time =%d",s[i- 1],s[i],c[i]); 
	} 
	//Calculating Total Sum
	for(i=0;i<m;i++) 
		tssum=tssum+c[i];
	//Printing Total Sum and Average 
	printf("\nTOTAL SEEK TIME=%d",tssum); 
	printf("\nAVG SEEK TIME=%d",tssum/m);
}

#include<stdio.h> 
#include<stdlib.h> 
void main(){ 
	int i,j,k,m,n,p,q,s[30],c,b[30],ts[30],tssum=0,msum=0,temp;
	//Reading Max Size
	printf("Enter the Max size:"); 
	scanf("%d",&q);
	//Reading Array Size
	printf("Enter the size:"); 
	scanf("%d",&m); 
	//Reading the Elements
	printf("Enter the sequence:"); 
	for(i=1;i<=m;i++) 
		scanf("%d",&s[i]); 
	//Reading the Current Head Position
	printf("Enter the current head position:"); 
	scanf("%d",&n); 
	s[0]=n; 
	s[m+1]=0; 
	s[m+2]=q;
	//Sorting the Sequence Using Bubble Sort
	for(i=0;i<m+2;i++){ 
		for(j=0;j<((m+2)-i-1);j++){ 
			if(s[j]>s[j+1]){ 
				temp=s[j]; 
				s[j]=s[j+1]; 
				s[j+1]=temp; 
			} 
		} 
	} 
	//Printing the Sorted Sequence and Finding Head Position Using Linear Search
	printf("Sorted sequence:"); 
	for(i=0;i<=m+2;i++){ 
		printf("%d\t",s[i]); 
		if(s[i]==n) 
			k=i; 
	}
	////Calculating Head Movement and Total Sum
	for(i=k;i<m+2;i++){ 
		c=abs(s[i]-s[i+1]); 
		printf("\nHead moves from %d to %d and seek time = %d",s[i],s[i+1],c); 
		tssum=tssum+c; 
	}
	c=abs(s[m+2]-s[0]);
	printf("\nHead moves from %d to %d and seek time = %d",s[m+2],s[0],c);
	msum=msum+c;
	for(i=0;i<k-1;i++){ 
		c=abs(s[i]-s[i+1]); 
		printf("\nHead moves from %d to %d and seek time = %d",s[i],s[i+1],c); 
		tssum=tssum+c; 
	} 
	tssum+=msum;
	printf("\nTOTAL SEEK TIME=%d",tssum); 
	printf("\nAVG SEEK TIME=%d",tssum/m);
}

#include<stdio.h> 
#include<stdlib.h> 
void main(){ 
	int i,j,m,n,p,q,s[30],tssum=0,lsum=0,temp,x,rsum=0,msum=0;
	//Reading Max Size
	printf("Enter the Max size:"); 
	scanf("%d",&q);
	//Reading the Size of Array
	printf("Enter the size:"); 
	scanf("%d",&m); 
	//Reading the Elements
	printf("Enter the sequence:"); 
	for(i=1;i<=m;i++) 
		scanf("%d",&s[i]);
	//Reading Previous Head Position 
	printf("Enter the previous head position:"); 
	scanf("%d",&p); 
	//Reading Current Head Position
	printf("Enter the current head position:"); 
	scanf("%d",&n); 
	//Setting 0th Position of Array as Current Head
	s[0]=n;
	//Setting Array Size + 1 th Position as 0 
	s[m+1]=0;
	//settimg Array Size + 2th Position as Max Size
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
	//Printing Sorted Sequence and Finding the Current Head Position Using Linear Search
	printf("Sorted sequence:"); 
	for(i=0;i<=m+2;i++){
		printf("%d\t",s[i]); 
		if(s[i]==n) 
			x=i;
	}
	//Checking If Head Moves to Left or Right And Calculating Head Movement,Seek Time and Sum of Each
	if(n<p){ 
		printf("\nHEAD MOVES TO LEFT"); 
		for(i=x;i>0;i--){ 
			lsum=abs(s[i]-s[i-1]); 
			printf("\nHead moves from %d to %d SEEK TIME:%d",s[i],s[i-1],lsum); 
			tssum=tssum+lsum; 
		} 
		msum=s[x+1]-s[0]; 
		printf("\nHead moves from %d to %d SEEK TIME:%d",s[0],s[x+1],msum); 
		for(i=x+1;i<m+1;i++){ 
			rsum=abs(s[i]-s[i+1]); 
			printf("\nHead moves from %d to %d SEEK TIME:%d",s[i],s[i+1],rsum); 
			tssum=tssum+rsum; 
		} 
	}else{ 
		printf("\nHEAD MOVES TO RIGHT"); 
		for(i=x;i<m+2;i++){ 
			rsum=abs(s[i]-s[i+1]); 
			printf("\nHead moves from %d to %d SEEK TIME:%d",s[i],s[i+1],rsum); 
			tssum=tssum+rsum; 
		} 
		msum=s[m+2]-s[x-1]; 
		printf("\nHead moves from %d to %d SEEK TIME:%d",s[m+2],s[x-1],msum); 
		for(i=x-1;i>1;i--){ 
			lsum=abs(s[i]-s[i-1]); 
			printf("\nHead moves from %d to %d SEEK TIME:%d",s[i],s[i-1],lsum); 
			tssum=tssum+lsum; 
		} 
	}
	//Calculating and Printing Total Sum and Average
	tssum=tssum+msum; 
	printf("\nTOTAL SEEK TIME:%d",tssum); 
	printf("\nAVG SEEK TIME=%d",tssum/m);
}

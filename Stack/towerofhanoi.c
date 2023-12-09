// At a time, only one disc can be moved to any tower.
// Smaller disc has to be above the larger disc.

// for n=3,
// 1,A->C 2,A->B 1,C->B 3,A->C 1,B->A 2,B->C 1,A->C  

#include<stdio.h>

void TOH(int n,char src,char dest,char aux);

int main(){

	printf("Enter the number of discs\n");
	int n;
	scanf("%d",&n);

	TOH(n,'A','C','B');

	return 0;
}

void TOH(int n,char src,char dest,char aux){

	if(n==1){
		printf("Move 1 from %c to %c\n",src,dest);
	}
	else{
		TOH(n-1,src,aux,dest);
		printf("Move %d from %c to %c\n",n,src,dest);
		TOH(n-1,aux,dest,src);
	}
}
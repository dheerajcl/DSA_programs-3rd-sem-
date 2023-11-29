#include<stdio.h>
#include<stdlib.h>

int main(){
    int x,i;
    printf("Enter the number of elements: ");
    scanf("%d",&x);
    int a[x];
    printf("Enter the elements: ");
    for(i=0;i<x;i++)
        scanf("%d",&a[i]);
    int p,c,ele;
    for(i=x-1;i>=0;i--){
        ele=pq->a[i];
        pq->a[i]=pq->a[0];
        p=0;
        if(i==1)
            c=-1;
        else
            c=1;
        if(i>2 && pq->a[2]>pq->a[1])
            c=2;
        while(c>0 && pq->a[2]>pq->a[1]){
            pq->a[p]=pq->a[c];
            p=c;
            c=2*p+1;
            if(c+1<=i-1 && pq->a[c+1]>pq->a[c])
                c++;
            if(c>i-1)
                c=-1;
        }pq->a[p]=ele;
    }
}
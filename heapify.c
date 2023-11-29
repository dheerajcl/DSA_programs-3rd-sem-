#include<stdio.h>

int main()
{
    int n=5;
    int arr[n];
    int i;
    printf("Enter the elements : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int c,p;
    int ele;
    for(i=1;i<=n-1;i++){
        c = i;
        ele = arr[c];
        p = (c-1)/2;
        while(c>0 && arr[p]<ele){
            arr[c] = arr[p];
            c = p;
            p = (c-1)/2;
        }
        arr[c] = ele;
    }

    printf("The heap is : \n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
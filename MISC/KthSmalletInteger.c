/*Write a function ‘place ()’ which accepts an array of n integers (unsorted) and returns kth smallest integer of the array. (Hint: Try using logic of partitioning done in quicksort) */

#include <stdio.h>
#include <stdlib.h>
int partition(int x[],int lb,int ub)
{
    int val=x[lb],down=lb+1,up=ub,t;
    while(down<=up)
    {
        while(down<=up && x[down]<=val)
            down++;
        while(x[up]>val)
            up--;
        if(down<up)
        {
            t=x[down];
            x[down]=x[up];
            x[up]=t;
        }
    }
    x[lb]=x[up];
    x[up]=val;
    return up;
}
int place(int x[],int n,int k)
{
    int p,lb=0,ub=n-1;
    p=partition(x,lb,ub);
    while(1)
    {
        if(p==k-1)
            return x[p];
        if(k-1<p)
            p=partition(x,lb,p-1);
        else
            p=partition(x,p+1,ub);
    }
}
void main()
{
    int i,k,n,x[50];
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("Enter k to find the kth smallest integer: ");
    scanf("%d",&k);
    printf("%d th smallest integer in the array is : %d \n",k,place(x,n,k));
}

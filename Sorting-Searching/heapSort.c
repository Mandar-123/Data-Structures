#include <stdio.h>
void display(int x[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n");
}
void heapup(int x[],int r,int b)
{
    int p,t;
    if(b>r)
    {
        p=(b-1)/2;
        if(x[p]<x[b])
        {
            t=x[p];
            x[p]=x[b];
            x[b]=t;
            heapup(x,r,p);
        }
    }
}
void heapdown(int x[],int r,int b)
{
    int lc=2*r+1,rc=2*r+2,mc,t;
    if(lc<=b)
    {
        if(lc==b)
            mc=lc;
        else if(x[lc]>x[rc])
            mc=lc;
            else mc=rc;
        if(x[r]<x[mc])
        {
            t=x[r];
            x[r]=x[mc];
            x[mc]=t;
            heapdown(x,mc,b);
        }
    }
}
void heapsort(int x[],int n)
{
    int i,t;
    for(i=0;i<n-1;i++)
    {
        heapup(x,0,i+1);
    }
    printf("\n");
    for(i=n-1;i>0;i--)
    {
        t=x[0];
        x[0]=x[i];
        x[i]=t;
        heapdown(x,0,i-1);
    }
}
void accept(int x[],int n)
{
    int i;
        for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
}

void main()
{
    int n,a[50];
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    accept(a,n);
    heapsort(a,n);
    printf("Sorted elements: ");
    display(a,n);
}
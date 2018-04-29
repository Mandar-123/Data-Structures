#include<stdio.h>
#include<limits.h>
int main()
{
    int a[50],i,sum,j,n,k,p,x,y;
    int max=INT_MIN;
    printf("Enter number of integers: ");
    scanf("%d",&n);
    printf("Enter array\n");
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((j+i)<=n)
            {
                sum=0;
                p=i;
                k=j;
            while(p!=0)
            {
                sum=sum+a[k];
                    p--;
                    k++;
            }
            if(sum>max)
            {
                max=sum;
                x=i;
                y=j;

            }
            }
        }
    }
    printf("Array with maximum sum is:\n");
    for(i=y;i<x+y;i++)
         printf("%d ",a[i]);
        return 0;
}

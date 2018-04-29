#include <stdio.h>
#include <stdlib.h>
void insertionsort(int x[],int n)
{
    int i,j,val;
    for(i=0;i<n-1;i++)
    {
        val=x[i+1];
        for(j=i;j>=0;j--)
        {
            if(val<x[j])
                x[j+1]=x[j];
            else break;
        }
        x[j+1]=val;
    }
}
void shellsort(int x[],int n)
{
    int i,j,k,inc,val;
    for(inc=n/2;inc>=1;inc=inc/2)
    {
        for(k=0;k<inc;k++)
        {
            for(i=k;i<n-inc;i=i+inc)
            {
                val=x[i+inc];
                for(j=i;j>=k;j=j-inc)
                {
                    if(val<x[j])
                        x[j+inc]=x[j];
                    else break;
                }
                x[j+inc]=val;
            }
        }
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
void display(int x[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n");
}
void main()
{
    int n,a[50],ch;
    do
    {
        printf("Enter no. of elements: ");
        scanf("%d",&n);
        printf("Enter elements: ");
        accept(a,n);
        printf("ENTER CHOICE : 1.INSERTION SORT    2.SHELLSORT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insertionsort(a,n);
                    printf("Sorted elements: ");
                    display(a,n);
                    break;
            case 2: shellsort(a,n);
                    printf("Sorted elements: ");
                    display(a,n);
                    break;
            default:printf("INVALID CHOICE\n");
        }
        printf("DO YOU WANT TO CONTINUE: 1.YES   2.NO\n");
        scanf("%d",&ch);
    }while(ch==1);
    printf("THANKYOU");
}

/*
OUTPUT:

Enter no. of elements: 7                                                                                                                                                                                                             
Enter elements: 45 12 16 9 1 34 7                                                                                                                                                                                                    
ENTER CHOICE : 1.INSERTION SORT    2.SHELLSORT                                                                                                                                                                                       
1                                                                                                                                                                                                                                    
Sorted elements: 1 7 9 12 16 34 45                                                                                                                                                                                                   
DO YOU WANT TO CONTINUE: 1.YES   2.NO                                                                                                                                                                                                
1                                                                                                                                                                                                                                    
Enter no. of elements: 8                                                                                                                                                                                                             
Enter elements: 23 15 11 60 7 4 33 10                                                                                                                                                                                                
ENTER CHOICE : 1.INSERTION SORT    2.SHELLSORT                                                                                                                                                                                       
2                                                                                                                                                                                                                                    
Sorted elements: 4 7 10 11 15 23 33 60                                                                                                                                                                                               
DO YOU WANT TO CONTINUE: 1.YES   2.NO                                                                                                                                                                                                
2                                                                                                                                                                                                                                    
THANKYOU
*/
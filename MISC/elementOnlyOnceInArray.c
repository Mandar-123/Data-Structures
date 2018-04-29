#include <stdio.h>
void main()
{
    int a[100],i=0,j,ch,l,t,ele;
    printf("Enter ARRAY"\n);
    while(1)
    {
       printf("1.Enter element    0.End array\n ");
       scanf("%d",&ch);
       if(ch==1)
       {    
            printf("Enter Element:  ");
            scanf("%d",&a[i]);
            i++;
       }
       else
            break;
    }
    l=i;
    for(i=0;i<l;i++)
    {
        for(j=0;j<l-1;j++)
        {   
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(i=0;i<l;i=i+2)
    {
        if(a[i]!=a[i+1])
        {
            ele=a[i];
            break;
        }
    }
    printf("ELEMENT THAT IS ENTERED ONLY ONCE IS: %d",ele);
}
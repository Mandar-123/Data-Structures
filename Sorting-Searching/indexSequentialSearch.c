#include<stdio.h>
#define SIZE 5
int createindex(int x[],int n,int index[])
{
	int i,j=0;
	for(i=0;i<n;i+=SIZE)
		index[j++]=x[i];
	index[j++]=x[n-1];
	return j;
}
int search(int x[],int n,int index[],int m,int ele)
{
	int i,j,k;
	if(ele<x[0]||ele>x[n-1])
		return 0;
	for(i=0;i<m;i++)
		if(ele<=index[i])
			break;
	j=i*SIZE;
	if(j>n-1)
	  	j=n-1;
	for(k=j;k>(i-1)*SIZE;k--)
		if(ele>=x[k])
			break;
	if(ele==x[k])
		return 1;
	else return 0;
}
void main()
{
	int i,x[50],n,index[10],m,ele;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	m=createindex(x,n,index);
	printf("Enter element to be searched: ");
	scanf("%d",&ele);
	if(search(x,n,index,m,ele)==1)
		printf("%d found",ele);
	else printf("%d not found",ele);
}


/*
OUTPUT:

Enter number of elements: 9                                                                                                                                                                                                          
Enter elements: 5 12 17 22 30 32 39 44 60                                                                                                                                                                                            
Enter element to be searched: 39                                                                                                                                                                                                     
39 found               

Enter number of elements: 12                                                                                                                                                                                                         
Enter elements: 16 25 30 40 62 70 78 88 95 102 111 150                                                                                                                                                                               
Enter element to be searched: 90                                                                                                                                                                                                     
90 not found
*/
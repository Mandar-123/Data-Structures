#include<stdio.h>
# define Max 4
int q[Max];
int f=0,r=-1;
int isempty()
{
	if(f==r+1)
		return 1;
	else	return 0;
}
void insert(int ele)
{
	if(r==Max-1)
		printf("Queue Overflow\n");
	else
	{
		r++;
		q[r]=ele;
	}
}
void display()
{
	int i;
	if(isempty())
	{	
		printf("Queue Empty\n");
		
	}
	else
	{
		for(i=f;i<=r;i++)
		{
			printf("%d ",q[i]);
		}
		printf("\n");
	}
}	
int queuefront()
{
	int z,m,i,pos;
	if(isempty())
	{
		printf("Queue Empty\n");
		return -1;
	}
	m=q[f];
	for(i=f+1;i<=r;i++)
	{
		if(q[i]>m)
		 {
			m=q[i];
		 	pos=i;
		 }
 	}
                z=q[pos];
	return z;
}
int delete1()
{
	int m,i,z,pos=f;
	m=q[f];
	for(i=f+1;i<=r;i++)
	{
		if(q[i]>m)
		 {
			m=q[i];
		 	pos=i;
		 }
 	}
                z=q[pos];
	for(i=pos;i<=r;i++)
	{
		q[i]=q[i+1];
	}
	r--;
	return z;
}
void main()
{
	int ch,ele;
	while(1)
	{
	printf("Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit\n");
	scanf("%d",&ch);
	if(ch==5)
	{
		printf("Thankyou\n");
		break;
}
	switch(ch)
	{
		case 1: if(r==Max-1)
			{
				printf("Queue overflow\n");
				break;
			}
			printf("Enter element to be inserted: ");
			scanf("%d",&ele);
			insert(ele);
			printf("Updated queue\n");
			display();
			break;
		case 2:if(isempty())
			{
				printf("Queue Underflow\n");
				break;
			}
			ele=delete1();
			printf("Deleted element is:%d\n",ele);
			break;
		case 3:if(isempty())
			{
				printf("Queue Empty\n");
				break;
			}
			ele=queuefront();
			printf("frontmost element of queue is: %d\n",ele);
			break;
		case 4:printf("Queue is ");
			if(f==r+1)
				printf("empty\n");
			else
				display();
			break;
		default:printf("INVALID CHOICE\n");
	}
}
}


/*

OUTPUT:

Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
1                                                                                                                                                                                                             
Enter element to be inserted: 12                                                                                                                                                                              
Updated queue                                                                                                                                                                                                 
12                                                                                                                                                                                                            
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
1                                                                                                                                                                                                             
Enter element to be inserted: 16                                                                                                                                                                              
Updated queue                                                                                                                                                                                                 
12 16                                                                                                                                                                                                         
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
1                                                                                                                                                                                                             
Enter element to be inserted: 25                                                                                                                                                                              
Updated queue     
12 16 25                                                                                                                                                                                                      
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
1                                                                                                                                                                                                             
Enter element to be inserted: 23                                                                                                                                                                              
Updated queue                                                                                                                                                                                                 
12 16 25 23                                                                                                                                                                                                   
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
1                                                                                                                                                                                                             
Queue overflow                                                                                                                                                                                                
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
2                                                                                                                                                                                                             
Deleted element is:25                                                                                                                                                                                         
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
2                                                                                                                                                                                                             
Deleted element is:23       
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
3                                                                                                                                                                                                             
frontmost element of queue is: 16                                                                                                                                                                             
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
4                                                                                                                                                                                                             
Queue is 12 16                                                                                                                                                                                                
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
2                                                                                                                                                                                                             
Deleted element is:16                                                                                                                                                                                         
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
2                                                                                                                                                                                                             
Deleted element is:12                                                                                                                                                                                         
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
2                                                                                                                                                                                                             
Queue Underflow          
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                 
4                                                                                                                                                                                                             
Queue is empty                                                                                                                                                                                                Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                             5                                                                                                                                                                                                           Thankyou  

*/

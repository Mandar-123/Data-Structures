#include<stdio.h>
# define Max 4
int q[Max];
int f=0,r=-1;
int count=0;
int isempty()
{
	if(count==0)
		return 1;
	else	return 0;
}
void insert(int ele)
{
	if(count==Max)
		printf("Queue Overflow\n");
	else
	{
		r=(r+1)%Max;
		q[r]=ele;
		count++;
	}
}		
int delete1()
{
	int z;
	if(isempty())
	{	
		printf("Queue Underflow\n");
		return -1;
	}
	count--;
	z=q[f];
	f=(f+1)%Max;
	return z;
}
int queuefront()
{
	int z;
	if(isempty())
	{
		printf("Queue Empty\n");
		return -1;
	}
	z=q[f];
	return z;
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
		i=f;
		while(1)
		{
			printf("%d ",q[i]);
			if(i==r)
				break;
			i=(i+1)%Max;
		}
		printf("\n");
	}
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
		case 1: if(count==Max)
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
		case 4:printf("Queue is: ");
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
Enter element to be inserted: 25                                                                                                                                                                                                      
Updated queue                                                                                                                                                                                                                         
25                                                                                                                                                                                                                                    
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
1                                                                                                                                                                                                                                     
Enter element to be inserted: 56                                                                                                                                                                                                      
Updated queue                                                                                                                                                                                                                         
25 56                                                                                                                                                                                                                                 
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
1                                                                                                                                                                                                                                     
Enter element to be inserted: 89                                                                                                                                                                                                      
Updated queue                                                                                                                                                                                                                         
25 56 89                                                                                                                                                                                                                              
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit     
1                                                                                                                                                                                                                                     
Enter element to be inserted: 65                                                                                                                                                                                                      
Updated queue                                                                                                                                                                                                                         
25 56 89 65                                                                                                                                                                                                                           
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
1                                                                                                                                                                                                                                     
Queue overflow                                                                                                                                                                                                                        
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
2                                                                                                                                                                                                                                     
Deleted element is:25                                                                                                                                                                                                                 
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
2                                                                                                                                                                                                                                     
Deleted element is:56                                                                                                                                                                                                                 
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
2                        
Deleted element is:89                                                                                                                                                                                                                 
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
2                                                                                                                                                                                                                                     
Deleted element is:65                                                                                                                                                                                                                 
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
3                                                                                                                                                                                                                                     
Queue Empty                                                                                                                                                                                                                           
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
1                                                                                                                                                                                                                                     
Enter element to be inserted: 12          
Updated queue                                                                                                                                                                                                                         
12                                                                                                                                                                                                                                    
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
3                                                                                                                                                                                                                                     
frontmost element of queue is: 12                                                                                                                                                                                                     
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
4                                                                                                                                                                                                                                     
Queue is: 12                                                                                                                                                                                                                          
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
2                                                                                                                                                                                                                                     
Deleted element is:12                                                                                                                                                                                                                 
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                         
5                                                                                                                                                                                                                                     
Thankyou  

*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *start=NULL;
int delete()
{
    int z;
    if(start==NULL)
    {
        printf("priority queue underflow\n");
        return -1;
    }
    z=start->data;
    start=start->next;
    return z;
}
void insert(int ele)
{
    node *p,*q;
    p=(node*)malloc(sizeof(node));
    p->data=ele;
    p->next=NULL;
    if(start==NULL || ele>(start->data) )
    {
        p->next=start;
        start=p;
        return;
    }

    q=start;
    while(q->next!=NULL && ele<(q->next->data))
        q=q->next;
    p->next=q->next;
    q->next=p;
    return;
}
int queuefront()
{
    if(start==NULL)
    {
        printf("priority queue empty");
        return -1;
    }
    return start->data;
}
void display()
{
    node *q=start;
    if(start==NULL)
    {
        printf("priority queue empty\n");
        return;
    }
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
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
            case 1: printf("Enter element to be inserted: ");
                    scanf("%d",&ele);
                    insert(ele);
                    printf("Updated queue\n");
                    display();
                    break;
            case 2:if(start==NULL)
                    {
                        printf("Queue Underflow\n");
                        break;
                    }
                    ele=delete();
                    printf("Deleted element is: %d\n",ele);
                    printf("Updated queue : ");
                    display();
                    break;
            case 3:if(start==NULL)
                    {
                        printf("Queue Empty\n");
                        break;
                    }
                    ele=queuefront();
                    printf("frontmost element of queue is: %d\n",ele);
                    break;
            case 4:printf("Queue is ");
                    if(start==NULL)
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
2                                                                                                                                                                                                                                    
Queue Underflow                                                                                                                                                                                                                      
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
1                                                                                                                                                                                                                                    
Enter element to be inserted: 22                                                                                                                                                                                                     
Updated queue                                                                                                                                                                                                                        
22                                                                                                                                                                                                                                   
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
1                                                                                                                                                                                                                                    
Enter element to be inserted: 1                                                                                                                                                                                                      
Updated queue                                                                                                                                                                                                                        
22 1                                                                                                                                                                                                                                 
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit
1                                                                                                                                                                                                                                    
Enter element to be inserted: 33                                                                                                                                                                                                     
Updated queue                                                                                                                                                                                                                        
33 22 1                                                                                                                                                                                                                              
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
3                                                                                                                                                                                                                                    
frontmost element of queue is: 33                                                                                                                                                                                                    
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
4                                                                                                                                                                                                                                    
Queue is 33 22 1                                                                                                                                                                                                                     
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
2                                                                                                                                                                                                                                    
Deleted element is: 33                                                                                                                                                                                                               
Updated queue : 22 1                                                                                                                                                                                                                 
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
2                                                                                                                                                                                                                                    
Deleted element is: 22                                                                                                                                                                                                               
Updated queue : 1                                                                                                                                                                                                                    
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
2                                                                                                                                                                                                                                    
Deleted element is: 1                                                                                                                                                                                                                
Updated queue : priority queue empty                                                                                                                                                                                                 
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
3                                                                                                                                                                                                                                    
Queue Empty                                                                                                                                                                                                                          
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
1                                                                                                                                                                                                                                    
Enter element to be inserted: 55                                                                                                                                                                                                     
Updated queue                                                                                                                                                                                                                        
55                  
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
1                                                                                                                                                                                                                                    
Enter element to be inserted: 44                                                                                                                                                                                                     
Updated queue                                                                                                                                                                                                                        
55 44                                                                                                                                                                                                                                
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
4                                                                                                                                                                                                                                    
Queue is 55 44                                                                                                                                                                                                                       
Enter Choice: 1:insert 2:delete 3:queuefront 4:display 5:exit                                                                                                                                                                        
5                                                                                                                                                                                                                                    
Thankyou
*/
#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
}node;
node *start=NULL;
void insertbeg(int ele)
{
node *p;
p=(node*)malloc(sizeof(node));
p->data=ele;
p->next=start;
start=p;
}
void insertend(int ele)
{
node *p,*q;
p=(node*)malloc(sizeof(node));
p->data=ele;
p->next=NULL;
if(start==NULL)
start=p;
else
{
q=start;
while(q->next!=NULL)
q=q->next;
q->next=p;
}
}
void display()
{
node *q;
if(start==NULL)
{
printf(" Linked list EMPTY\n");
return;
}
q=start;
while(q!=NULL)
{
printf("%d ",q->data);
q=q->next;
}
printf("\n");
}
void deleteele(int ele)
{
node *z,*q;
if(start==NULL)
{
printf("Linked list EMPTY\n");
return;
}
if(start->data==ele)
{
start=start->next;
return;
}
q=start;
while(q->next!=NULL)
{
z=q->next;
if(z->data==ele)
break;
else
 q=q->next;
}
if(q->next==NULL)
printf("%d is not found\n",ele);
else
{
z=q->next;
q->next=z->next;
}
}
int count()
{
node *q;
int c=0;
q=start;
while(q!=NULL)
{
c++;
q=q->next;
}
return c;
}	
void reverse()
{
node *p=start;
node *q=NULL,*r;
while(p!=NULL)
{
r=p->next;
p->next=q;
q=p;
p=r;
}
start=q;
}
int search(int ele)
{
node *q=start;
while(q!=NULL)
{
if(q->data==ele)
return 1;
q=q->next;
}
return 0;
}
void main()
{
int ch,ele;
while(1)
{
printf("Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count
6.reverse 7.search 8:exit\n");
scanf("%d",&ch);
if(ch==8)
{
printf("Thankyou\n");
break;
}
switch(ch)
{
case 1: printf("Enter element to be inserted: ");
scanf("%d",&ele);
insertbeg(ele);
printf("Updated linked list\n");
display();
break;
case 2: printf("Enter element to be inserted: ");
scanf("%d",&ele);
insertend(ele);
printf("Updated linked list\n");
display();
break;
case 3:if(start==NULL)
{
printf("LINKED LIST UNDERFLOW \n");
break;
}
printf("Enter Element TO Delete:");
scanf("%d",&ele);
deleteele(ele);
printf("Updated linked list\n");
display();
break;
case 4: if(start==NULL)
{
printf("Linked list Empty\n");
break;
}
printf("Linked list is: ");
display();
break;
case 5:printf("Number of elements = %d\n",count());
break;
case 6:reverse();
if(start==NULL)
{
printf("Linked list Empty\n");
break;
}
printf("Updated linked list\n");
display();
break;
case 7:printf("Enter element to search: ");
scanf("%d",&ele);
if(search(ele)==1)	
printf("Element Found\n");
else
printf("Element not found\n");
break;
default:printf("INVALID CHOICE\n");
}
}
}


/*

OUTPUT:

Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count 6.reverse 7.search 8:exit                                                                                                                                   
1                                                                                                                                                                                                                                    
Enter element to be inserted: 12                                                                                                                                                                                                     
Updated linked list                                                                                                                                                                                                                  
12                                                                                                                                                                                                                                   
Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count 6.reverse 7.search 8:exit                                                                                                                                   
2                                                                                                                                                                                                                                    
Enter element to be inserted: 23                                                                                                                                                                                                     
Updated linked list                                                                                                                                                                                                                  
12 23                                                                                                                                                                                                                                
Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count 6.reverse 7.search 8:exit                                                                                                                                   
1                                                                                                                                                                                                                                    
Enter element to be inserted: 56                                                                                                                                                                                                     
Updated linked list     
   56 12 23                                                                                                                                                                                                                             
Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count 6.reverse 7.search 8:exit                                                                                                                                   
3                                                                                                                                                                                                                                    
Enter Element TO Delete:12                                                                                                                                                                                                           
Updated linked list                                                                                                                                                                                                                  
56 23                                                                                                                                                                                                                                
Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count 6.reverse 7.search 8:exit                                                                                                                                   
2                                                                                                                                                                                                                                    
Enter element to be inserted: 45                                                                                                                                                                                                     
Updated linked list                                                                                                                                                                                                                  
56 23 45                                                                                                                                                                                                                             
Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count 6.reverse 7.search 8:exit                                                                                                                                   
4                                                                                                                                                                                                                                    
Linked list is: 56 23 45                                                                                                                                                                                                             
Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count 6.reverse 7.search 8:exit                                                                                                                                   
5  
  Number of elements = 3                                                                                                                                                                                                               
Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count 6.reverse 7.search 8:exit                                                                                                                                   
6                                                                                                                                                                                                                                    
Updated linked list                                                                                                                                                                                                                  
45 23 56                                                                                                                                                                                                                             
Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count 6.reverse 7.search 8:exit                                                                                                                                   
7                                                                                                                                                                                                                                    
Enter element to search: 56                                                                                                                                                                                                          
Element Found                                                                                                                                                                                                                        
Enter Choice: 1:insertbeg 2:insertend 3:delete element 4:display 5.count 6.reverse 7.search 8:exit                                                                                                                                   
8                                                                                                                                                                                                                                    
Thankyou
*/
#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *start=NULL;
void insert(int ele)
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
void checkloop()
{

    node *p,*q;
    p=q=start;
    while(q!=NULL && q->next!=NULL)
    {
        p=p->next;
        q=q->next->next;
        if(p==q)
            break;
    }
    if(q==NULL || q->next==NULL)
        printf("linked list is not looped\n");
    else
        printf("linked list is looped\n");
}
void makeloop(int ele)
{
    node *q=start;
    node *p=start;
    while(q->next!=NULL)
        q=q->next;
    while(p!=NULL)
    {
        if(p->data==ele)
            break;
        p=p->next;
    }
    if(p==NULL)
    {
        printf("element not found\n");
        return;
    }
    q->next=p;
    printf("linked list looped\n");
}
void main()
{
    int ch,ele;
	while(1)
	{
        printf("Enter Choice: 1:insert 2:make loop 3:check loop 4:exit\n");
        scanf("%d",&ch);
        if(ch==4)
        {
            printf("Thankyou\n");
            break;
        }
        switch(ch)
        {
            case 1: printf("Enter element to be inserted: ");
                    scanf("%d",&ele);
                    insert(ele);
                    printf("Updated linked list\n");
                    display();
                    break;

            case 2: if(start==NULL)
                         {
                 	  printf("Linked list empty\n");
                	  break;
                          }
                    printf("Enter the element where you want to attach the last node?\n");
                    scanf("%d",&ele);
                    makeloop(ele);
                    break;
            case 3: if(start==NULL)
            	          {
                     	   printf("Linked list empty\n");
            	                 break;
                         }
                    checkloop();
                    break;
            default:printf("INVALID CHOICE\n");
        }
    	}
}
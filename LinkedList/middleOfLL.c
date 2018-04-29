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
void middle()
{
    node *q,*p,*z;
    q=start;
    p=start;
    while(1)
    {
        if(start==NULL)
        {
            printf("linked list empty\n");
            return;
        }
        if(q==NULL)
        {
            printf("number of elements is even middle does not exist\n");
            return;
        }
        else if(q->next==NULL)
        {
            printf("middle element is:%d\n",p->data);
            return;
        }
        z=q->next;
        q=z->next;
        p=p->next;
    }
}
void main()
{
    int ch,ele;
	while(1)
	{
        printf("Enter Choice: 1:insert 2:display 3:middle of list 4:exit\n");
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
                        printf("Linked list Empty\n");
                        break;
                    }
                    printf("Linked list is: ");
                    display();
                    break;

            case 3:middle();
                    break;
            default:printf("INVALID CHOICE\n");
        }
             }
}
#include <stdio.h>
#include <stdlib.h>
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
void acceptsoldier(int n)
{
    int i,id;
    for(i=0;i<n;i++)
    {
        printf("Enter id of soldier %d:",i+1);
        scanf("%d",&id);
        insert(id);
    }
}
void findsoldier(int k)
{
    int count=1;
    node *p,*q;
    q=start;
    while(q->next!=NULL)
        q=q->next;
    p=start;
    q->next=p;
    while(1)
    {
        while(1)
        {
            if(count==k)
            {
                q->next=p->next;
                p=p->next;
                count=1;
                break;
            }
            count++;
            p=p->next;
            q=q->next;
        }
        if(p==q)
        {
            printf("%d is the id of soldier which has to go near enemy camp",p->data);
            break;
        }
    }
}
void main()
{
    int n,k;
    printf("Enter no. of soldiers: ");
    scanf("%d",&n);
    acceptsoldier(n);
    printf("Enter the random number to eliminate soldiers one at a time :");
    scanf("%d",&k);
    findsoldier(k);
}
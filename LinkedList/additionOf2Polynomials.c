#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coef,deg;
    struct node *next;
}node;
int min=0,max=0;
node *start1=NULL;
node *start2=NULL;
node *start=NULL;
void insert(int coeficient,int degree,int poly)
{
    node *p,*q;
    p=(node*)malloc(sizeof(node));
    p->coef=coeficient;
    p->deg=degree;
    p->next=NULL;
    q=start1;
    if(poly==1 && start1==NULL)
    {
            start1=p;
            return;
    }
    else if(poly==2 && start2==NULL)
    {
            start2=p;
            if(start1==NULL)
            {
                insert(0,0,1);
                q=start1;
            }
    }
    else if(poly==3 && start==NULL)
    {
            start=p;
            if(start2==NULL)
                insert(0,0,2);
    }
    while(q->next!=NULL)
            q=q->next;
        q->next=p;
}
void display(node *p,node*q)
{
    while(p!=q)
    {
        printf("+ %d x^%d  ",p->coef,p->deg);
        p=p->next;
    }
    printf("\n");
}
void add()
{
    node *q;
    int i,coeficient;
    for(i=max;i>=min;i--)
    {
        coeficient=0;
        q=start1;
        while(q!=start)
        {
            if(q->deg==i)
                coeficient=coeficient+(q->coef);
            q=q->next;
        }
        if(coeficient!=0)
        {
            insert(coeficient,i,3);
        }
  }
}
void accept(int i)
{
    int coeficient,degree,ch;
    while(1)
    {
        printf("1.Enter new term 0.end polynomial  :");
        scanf("%d",&ch);
        if(ch==0)
            break;
        else
        {
            printf("Enter coeficient: ");
            scanf("%d",&coeficient);
            printf("Enter degree: ");
            scanf("%d",&degree);
            insert(coeficient,degree,i);
            if(degree>max)
                max=degree;
            if(degree<min)
                min=degree;
        }
    }
}
void main()
{
    printf("Enter 1st polynomial\n");
    accept(1);
    printf("Enter 2nd polynomial\n");
    accept(2);
    add();
    printf("Polynomial 1:  ");
    display(start1,start2);
    printf("Polynomial 2:  ");
    display(start2,start);
    printf("Addition result:  ");
    display(start,NULL);
}
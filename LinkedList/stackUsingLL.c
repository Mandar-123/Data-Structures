#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *next;
    int data;
}node;
node *start=NULL;
void push(int ele)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->data=ele;
    p->next=start;
    start=p;
}
int pop()
{
    if(start==NULL)
    {
        printf("stack underflow\n");
        return -1;
    }
    int z=start->data;
    start=start->next;
    return z;
}
int stacktop()
{
    if(start==NULL)
    {
        printf("stack empty\n");
        return -1;
    }
    return(start->data);
}
void display()
{
    node *q=start;
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}
void main ()
{
    int ch,ele;
    while(1)
    {
         printf("Enter choice: 1:PUSH, 2:POP, 3:DISPLAY, 4:STACK TOP, 5:EXIT \n");
         scanf("%d", &ch);
         if (ch==5)
         {
            printf("Thank you");
            break;
         }
         else
         {
              switch(ch)
               {
                    case 1 :printf("Enter element to push \n");
                            scanf("%d",&ele);
                            push(ele);
                            printf("Updated stack: \n");
                            display();
                            break;
                    case 2 :if(start==NULL)
                            {
                                printf("Stack underflow\n");
                                break;
                            }
                            ele= pop();
                            printf("Popped Element is : %d \n",ele);
                            printf("Updated Stack: \n");
                            display();
                            break;
                    case 3 :if(start==NULL)
                            {
                                printf("Stack empty\n");
                                break;
                            }
                            printf("Stack is: \n");
                            display();
                            break;
                    case 4 :if(start==NULL)
                            {
                                printf("Stack empty\n");
                                break;
                            }
                            ele= stacktop();
                            printf("Stack top is: %d \n",ele);
                            break;
                }
          }
     }
}

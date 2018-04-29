#include<stdio.h>

#define max 10
int tos1= -1;
int tos2=-1;
int s1[max],s2[max];
void push1(int ele)
{
	  tos1++;
 	  s1[tos1]=ele;
}
int isempty1()
 {
	if(tos1==-1)
      	return 1;
	else return 0;
}
int pop1()
{ 
    int z;
    z=s1[tos1];
	tos1--;
	return z;
} 
void push2(int ele)
{
      tos2++;
 	  s2[tos2]=ele;
}
int isempty2()
 {
	if(tos2==-1)
    	return 1;
	else return 0;
}
int pop2()
{ 
    int z;
	z=s2[tos1];
	tos2--;
	return z;
} 
void enqueue(int ele)
{
    push2(ele);
}
int dequeue()
{
    int z;
    if(isempty2()==1)
    {
        while(isempty1()==0)
        {
            push2(pop1());
        }
    }
    if(isempty2())
    {
        printf("QUEUE EMPTY\n");
        return -1;
        
    }
    z=pop2();
    return (z);
}
void display()
{   
    int i;
    for(i=tos2;i>=0;i--)
    {
        printf("%d",s2[i]);
    }
    for(i=0;i<=tos1;i++)
    {
        printf("%d  ",s1[i]);
    }
    printf("\n");
}
void main ()
{
 int ch,ele;
	
while(1)
{
 printf("Enter choice: 1:ENQUEUE, 2:DEQUEUE, 3:DISPLAY, 4:EXIT \n");
        scanf("%d", &ch);
 if (ch==4)
 {
  printf("Thank you");
  break;
 }
else
 {
  switch(ch)
   { 
	case 1 : printf("Enter element to enqueue\n");
		 scanf("%d",&ele);
		 enqueue(ele);
		 printf("Updated queue: \n");
		 display();
		 break;
	case 2 : ele= dequeue();
		 printf("deleted element is : %d \n",ele);
		 printf("Updated queue: \n");
		 display();
		 break;
	case 3 : printf("queue is is: \n");
		 display();
		 break;
    }	 
  }		
 }
} 
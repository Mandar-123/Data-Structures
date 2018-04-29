/*Write a program which accepts symbols of a message with their codes and encoded message. The program should perform decoding and display the original message.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node
{
    char code[10];
    char symbol;
    struct node *next;
}node;
node *start=NULL;
void acceptnode(char s,char c[])
{
    int i;
    node *q;
    node *p;
    p=(node*)malloc(sizeof(node));
    p->symbol=s;
    for(i=0;i<strlen(c);i++)
        p->code[i]=c[i];
    p->code[i]='\0';
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
char decode(char t[])
{
    node *q=start;
    while(q!=NULL)
    {
        if(strcmp(q->code,t)==0)
            return q->symbol;
        q=q->next;
    }
}
void main()
{
    int n,i,l,k,j,p=0;
    char c[100],temp[10],decodearray[100];
    char s;
    printf("Enter no. of Symbols: ");
    scanf("%d",&n);
    for(i=0;i<10;i++)
        if(n<=pow(2,i))
            break;
    l=i;
    printf("PLEASE ENTER FIXED LENGTH CODES OF LENGTH %d\n",l);
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        printf("Enter Symbol: ");
        scanf("%c",&s);
        printf("Enter code: ");
        scanf("%s",c);
        acceptnode(s,c);
    }
    printf("Enter encoded message:");
    scanf("%s",c);
    for(i=0;i<=strlen(c)-l;i=i+l)
    {
        j=0;
        for(k=i;k<i+l;k++)
            temp[j++]=c[k];
        temp[j]='\0';
        decodearray[p++]=decode(temp);
    }
    decodearray[p]='\0';
    printf("DECODED MESSAGE : ");
    puts(decodearray);
}
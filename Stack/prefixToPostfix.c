#include <stdio.h>
#include <string.h>
#define MAX 100
#define flag '#'
int tos=-1;
char s[MAX];
void push(char ele)
{
    s[++tos]=ele;
}
char pop()
{
    return s[tos--];
}
int isempty()
{
    if(tos==-1)
        return 1;
    return 0;
}
char stacktop()
{
    return s[tos];
}
int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}
void main()
{
    int i,j=0,l;
    char prefix[MAX],postfix[MAX],clearflag;
    printf("Enter the prefix expression-->  ");
    gets(prefix);
    l=strlen(prefix);
    for (i=0;i<l;i++)
    {
        if(isOperator(prefix[i]))
        {
            push(prefix[i]);
        }
        else
        {
            postfix[j++]=prefix[i];
            while(isempty()==0 && stacktop()==flag)
            {
                clearflag=pop();
                postfix[j++]=pop();
            }
            push(flag);
        }
    }
    postfix[j]='\0';
    printf("Postfix expression is --> %s",postfix);
}
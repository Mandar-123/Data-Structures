#include <stdio.h>
#define MAX 50
char s[MAX];
int tos=-1;
void push(char ele)
{
    s[++tos]=ele;
}
char pop()
{
    return(s[tos--]);
}
int isempty()
{
    if(tos==-1)
        return 1;
    return 0;
}
int check(char a[])
{
    int i,l=strlen(a);
    char ele;
    for(i=0;i<l;i++)
    {
        if(a[i]=='{' || a[i]=='(')
            push(a[i]);
        else if(a[i]==')' || a[i]=='}')
            {
                if(isempty())
                    return 0;
                ele=pop();
                if((a[i]=='}' && ele!='{'))
                    return 0;
                if((a[i]==')' && ele!='('))
                    return 0;
            }
    }
    if(!isempty())
        return 0;
    return 1;
}
void main()
{
    char exp[50];
    printf("Enter expression :");
    gets(exp);
    if(check(exp)==1)
        printf("Expression is valid");
    else printf("INVALID expression");
}

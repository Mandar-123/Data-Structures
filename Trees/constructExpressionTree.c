#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
int tos=-1;
char a[50];
typedef struct node
{
    char data;
    struct node *left,*right;
}node;
node* s[MAX];
node *root=NULL;
void push(node *ele)
{
    s[++tos]=ele;
}
node* pop()
{
    return s[tos--];
}
int isoperand(char x)
{
    if((x>='A' && x<='Z') || (x>='a' && x<='z'))
        return 1;
    return 0;
}
void tree()
{
    int i,l=strlen(a);
    node *p;
    for(i=0;i<l;i++)
    {
        p=(node *)malloc(sizeof(node));
        p->data=a[i];
        p->left=p->right=NULL;
        if(isoperand(a[i]))
            push(p);
        else
        {
            p->right=pop();
            p->left=pop();
            push(p);
        }
    }
  root=pop();
}
void inorder(node *x)
{
    if(x!=NULL)
    {
       inorder(x->left);
       printf("%c",x->data);
       inorder(x->right);
    }
}
void preorder(node *x)
{
    if(x!=NULL)
    {
       printf("%c",x->data);
       preorder(x->left);
       preorder(x->right);
    }
}
void postorder(node *x)
{
    if(x!=NULL)
    {
       postorder(x->left);
       postorder(x->right);
       printf("%c",x->data);
    }
}
void main()
{
    printf("Enter postfix Expression :");
    gets(a);
    tree(a);
    printf("Given postfix Expreesion: ");
    printf("%s \n",a);
    printf("Inorder Expression: ");
    inorder(root);
    printf("\nPostorder Expression:  ");
    postorder(root);
    printf("\nPreorder Expression : ");
    preorder(root);
}

/*
OUTPUT:
Enter postfix Expression :ABC*+D+                                                                                                                                                                                                    
Given postfix Expreesion: ABC*+D+                                                                                                                                                                                                    
Inorder: A+B*C+D                                                                                                                                                                                                                     
Postorder ABC*+D+           
Preorder: ++A*BCD                                                                                                                                                                                                         
*/
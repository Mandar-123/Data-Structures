#include<stdio.h>
#include<string.h>
#define max 50
int tos= -1;
char s[max];
void push(char ele)
{
         tos++;
 	 s[tos]=ele;
}

void display(char a[])
{
	int i;

	int l=strlen(a);

	for(i=0;i<l;i++)

		printf("%c",a[i]);

	printf("\n");

}
int isempty()
{
	if(tos==-1)
    	     return 1;
        else return 0;
}
char stacktop()
{
 	return s[tos];
}
char pop()
{
        char z;
    	z=s[tos];
	tos--;
        return z;
}
int ipr(char ele)
{
       switch(ele)
       {
          case '(':return 3;
          case '*':
          case '%':

          case '/':return 2;
          case '+':
          case '-': return 1;
       }
       return -1;

}
int rpr(char ele)
{
       switch(ele)
       {
          case '(':return 0;
          case '*':
          case '%':

          case '/':return 2;
          case '+':
          case '-': return 1;
       }
       return -1;

}
int isoperand(char ele)
{
	if ((ele>= 'a' && ele<= 'z')|| (ele>= 'A' && ele<= 'Z'))
      		return 1;
	return 0;
}
void convert(char in[] , char post[])
{
    	int i,l,k=0;
    	char ele;

	l=strlen(in);
   	for(i=0;i<l;i++)
    	{


	     if(isoperand (in[i]) )
       	     {
    	    	 post[k++]=in[i];
       	     }
    	     else if(in[i]=='(')
                  	push(in[i]);
               	  else if(in[i]==')')
    	    	       {
    		 		while(1)
    		 		{
    		  		ele=pop();
    		        	if(ele=='(')
    		    		break;
    		  		post[k++]=ele;
    				}
 		    	}
 		        else if(isempty())
		 	     	push(in[i]);
			     else if(ipr(in[i])>rpr(stacktop()))
				  	push(in[i]);
				  else
				  	{
						while(ipr(in[i])<=rpr(stacktop()))
						{
							 ele=pop();
    		  					 post[k++]=ele;
    		  				}
    		  				push(in[i]);
    		  		    	 }
	}

		while(isempty()==0)

		{

			 post[k++]=pop();

	        }

	        post[k]='\0';

}
void main()
{
    char infix[50],postfix[50];
    printf("Enter Expression\n");
    gets(infix);
    convert(infix,postfix);
    printf("postfix expression: ");

    display(postfix);

}


/*
OUTPUT:
1.Enter Expression
  M*(A+B)
  postfix expression: MAB+*

2.Enter Expression
  K-M*(N/(G-F)*D)-A*W
  postfix expression: KMNGF-/D**-AW*-
*/

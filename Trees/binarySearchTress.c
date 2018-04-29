#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}node;
node *root=NULL;
node* father(node *p)
{
    node *q;
    if(p==root)
        return NULL;
    q=root;
    while(q!=NULL)
    {
        if(q->left==p || q->right==p)
            return q;
        if(p->data<=q->data)
            q=q->left;
        else q=q->right;
    }
    return NULL;
}
node* findmax(node *r)
{
    if(r->right==NULL)
        return r;
    else return(findmax(r->right));
}
void insert(int ele)
{
    node *p,*q;
    p=(node *)malloc(sizeof(node));
    p->data=ele;
    p->left=p->right=NULL;
    if(root==NULL)
    {
        root=p;
        return;
    }
    q=root;
    while(q!=NULL)
    {
        if(ele<=q->data)
        {
            if(q->left==NULL)
            {
                q->left=p;
                return;
            }
            else q=q->left;
        }
        else
        {
            if(q->right==NULL)
            {
                q->right=p;
                return;
            }
            else q=q->right;
        }
    }
}
int search(int ele)
{
    node *q=root;
    while(q!=NULL)
    {
        if(ele==q->data)
            return 1;
        if(ele<=q->data)
            q=q->left;
        else q=q->right;
    }
    return 0;
}

void delete1(int ele)
{
    node *q;
    if(root==NULL)
    {
        printf("BST Empty\n");
        return;
    }
    q=root;
    while(q!=NULL)
    {
        if(ele==q->data)
            break;
        if(ele<=q->data)
            q=q->left;
        else q=q->right;
    }
    if(q==NULL)
    {
        printf("%d is not found in BST");
        return;
    }
    if(q->left==NULL && q->right==NULL)
    {
        if(q==root)
        {
            root=NULL;
            return;
        }
        if(father(q)->left==q)
            father(q)->left=NULL;
        else father(q)->right=NULL;
        return;
    }
    if(q->left!=NULL)
    {
        int val;
        node *max=findmax(q->left);
        val=max->data;
        delete1(max->data);
        q->data=val;
        return;
    }
    if(q==root)
    {
        root=root->right;
        return;
    }
    if(father(q)->left==q)
        father(q)->left=q->right;
    else father(q)->right=q->right;
}
void inorder(node *x)
{
    if(x!=NULL)
    {
       inorder(x->left);
       printf("%d ",x->data);
       inorder(x->right);
    }
}
void preorder(node *x)
{
    if(x!=NULL)
    {
       printf("%d ",x->data);
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
       printf("%d ",x->data);
    }
}
void main()
{
    int ch,ele;
    while(1)
    {
            printf("Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit\n");
            scanf("%d",&ch);
            if(ch==7)
            {
                printf("THANKYOU");
                break;
            }
            switch(ch)
            {
                case 1 :printf("Enter element to insert: ");
                        scanf("%d",&ele);
                        insert(ele);
                        break;
                case 2 :if(root==NULL)
                        {
                            printf("BST EMPTY\n");
                            break;
                        }
                        printf("Enter element to delete: ");
                        scanf("%d",&ele);
                        delete1(ele);
                        break;
                case 3 :if(root==NULL)
                        {
                            printf("BST EMPTY\n");
                            break;
                        }
                        printf("Enter element to search: ");
                        scanf("%d",&ele);
                        if(search(ele))
                            printf("Element is present in BST\n");
                        else printf("Element is not present in BST\n");
                        break;
                case 4 :printf("Inorder: ");
                        inorder(root);
                        printf("\n");
                        break;
                case 5 :printf("preorder: ");
                        preorder(root);
                        printf("\n");
                        break;
                case 6 :printf("postorder: ");
                        postorder(root);
                        printf("\n");
                        break;
                default :printf("INVALID CHOICE\n");
            }
    }
}





/*

OUTPUT:

Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
1                                                                                                                                                                                                                                    
Enter element to insert: 49                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
1                                                                                                                                                                                                                                    
Enter element to insert: 23                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
1                                                                                                                                                                                                                                    
Enter element to insert: 56                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
1                                                                                                                                                                                                                                    
Enter element to insert: 21                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
1                                                                                                                                                                                                                                    
Enter element to insert: 51                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
1                  
      Enter element to insert: 30                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
4                                                                                                                                                                                                                                    
Inorder: 21 23 30 49 51 56                                                                                                                                                                                                           
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
1                                                                                                                                                                                                                                    
Enter element to insert: 65                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
2                                                                                                                                                                                                                                    
Enter element to delete: 23                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
5                                                                                                                                                                                                                                    
preorder: 49 21 30 56 51 65                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
3    
    Enter element to search: 30                                                                                                                                                                                                          
Element is present in BST                                                                                                                                                                                                            
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
2                                                                                                                                                                                                                                    
Enter element to delete: 21                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
6                                                                                                                                                                                                                                    
postorder: 30 51 65 56 49                                                                                                                                                                                                            
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
2                                                                                                                                                                                                                                    
Enter element to delete: 51                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
4                                                                                                                                                                                                                                    
Inorder: 30 49 56 65                                                                                                                                                                                                                 
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit
2                                                                                                                                                                                                                                    
Enter element to delete: 49                                                                                                                                                                                                          
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
4                                                                                                                                                                                                                                    
Inorder: 30 56 65                                                                                                                                                                                                                    
Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder  7.Exit                                                                                                                                               
7                                                                                                                                                                                                                                    
THANKYOU 
*/
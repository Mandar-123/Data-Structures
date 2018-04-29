#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}node;
node *root=NULL;
int count,leaf,nleaf;
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
            printf("Element Deleted\n");
            return;
        }
        if(father(q)->left==q)
            father(q)->left=NULL;
        else father(q)->right=NULL;
        printf("Element Deleted\n");
        return;
    }
    if(q->left!=NULL)
    {
        int val;
        node *max=findmax(q->left);
        val=max->data;
        delete1(max->data);
        q->data=val;
        printf("Element Deleted\n");
        return;
    }
    if(q==root)
    {
        root=root->right;
        printf("Element Deleted\n");
        return;
    }
    if(father(q)->left==q)
        father(q)->left=q->right;
    else father(q)->right=q->right;
    printf("Element Deleted\n");
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
void ascending(node *x)
{
    if(x!=NULL)
    {
       ascending(x->left);
       printf("%d ",x->data);
       ascending(x->right);
    }
}
void descending(node *x)
{
    if(x!=NULL)
    {
       descending(x->right);
       printf("%d ",x->data);
       descending(x->left);
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
int count_nodes(node *x)
{
    if(x!=NULL)
    {
        count_nodes(x->left);
        count_nodes(x->right);
        return ++count;
    }
}
int count_leaf(node *x)
{
    if(x!=NULL)
    {
        count_leaf(x->left);
        count_leaf(x->right);
        if(x->left==NULL && x->right==NULL)
            return ++leaf;
        else return leaf;
    }
}
int count_nonleaf(node *x)
{
    if(x!=NULL)
    {
        count_nonleaf(x->left);
        count_nonleaf(x->right);
        if(x->left!=NULL || x->right!=NULL)
            return ++nleaf;
        else return nleaf;
    }
}
node* copy(node* x)
{
    if(x==NULL)
        return x;
    node* p=(node*)malloc(sizeof(node));
    p->data=x->data;
    p->left=copy(x->left);
    p->right=copy(x->right);
    return p;
}
void main()
{
    int ch,ele;
    while(1)
    {
            printf("Enter choice: 1.insert  2.Delete  3.search  4.inorder  5.preorder  6.postorder 7.total nodes  8.leaf nodes  9.nonleaf nodes 10.ascending 11.descending  12.create copy of BST\n");
            scanf("%d",&ch);
            if(ch==13)
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
                case 7 :count=0;
                        printf("Total number of nodes=%d \n",count_nodes(root));
                        break;
                case 8 :leaf=0;
                        printf("Total number of leaf nodes=%d \n",count_leaf(root));
                        break;
                case 9 :nleaf=0;
                        printf("Total number of non-leaf nodes=%d \n",count_nonleaf(root));
                        break;
                case 10:printf("Elements in ascending order: ");
                        ascending(root);
                        printf("\n");
                        break;
                case 11:printf("Elements in descending order: ");
                        descending(root);
                        printf("\n");
                        break;
                case 12:printf("copy of tree created\n");
                        node* p=copy(root);
                        printf("inorder representation of copied tree: ");
                        inorder(p);
                        printf("\n");
                        break;
                default:printf("INVALID CHOICE\n");
            }
    }
}
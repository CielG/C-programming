#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}*root; //root always save the address of root node

//To create a new BST node
struct tree* New(int n)
{
    struct tree*newnode=(struct tree*)malloc(sizeof(struct tree));
    newnode->data=n;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void inorder(struct tree *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%d \n", p->data);
        inorder(p->right);
    }
}
struct tree* insert(struct tree *treep,int n)
{
    if(treep==NULL)
    {
        return New(n);
    }
    if(n<= treep->data)
    {
        treep->left=insert(treep->left,n);
    }
    else
    {
        treep->right=insert(treep->right,n);
    }
    return treep;
}

int main()
{
    struct tree* root =NULL; //Initialize the tree
    int n,i,a;
    printf("Enter the number of the element of your BST\n");
    scanf("%d",&n);
    printf("Enter the element\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        root=insert(root,a);
    }
   inorder(root);// print inoder traversal of the BST
   return 0;
}


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
struct tree *search(struct tree* Root,int key)
{
    if(Root == NULL)
    {
        printf("Not found\n");
        return NULL;
    }
    if(key < Root->data)
    {
        return search(Root->left,key);
    }
    else if(key > Root->data)
    {
        return search(Root->right,key);
    }
    else
    {
        printf("key found\n");
        return Root;
    }
}

int main()
{
    struct tree* root =NULL; //Initialize the tree
    int n,i,a,b;
    printf("Enter the number of the element of your BST\n");
    scanf("%d",&n);
    printf("Enter the element\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        root=insert(root,a);
    }
   inorder(root);// print inoder traversal of the BST
   printf("Enter the element you wanna search\n");
   scanf("%d",&b);
   search(root,b);
   return 0;
}

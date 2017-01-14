#include<stdio.h>
#include<stdlib.h>
struct node
{
    unsigned int data;
    struct node* next;
}*head;

void add(struct node** Node,unsigned int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=*Node;
    *Node=temp;
}

void split(struct node* Node,struct node **front,struct node **back)
{
    struct node* a;
    struct node* b;
    if(Node==NULL || Node->next==NULL)
    {
        *front=Node;
        *back=NULL;
    }
    else
    {
        a=Node;
        b=Node->next;
        while(b != NULL)
        {
            b=b->next;
            if(b!= NULL)
            {
                a=a->next;
                b=b->next;
            }
        }
        *front=Node;
        *back =a->next;
        a->next= NULL;
    }
}
struct node* merge(struct node *a,struct node *b)
{
    struct node* list=NULL;
    if(a==NULL)
    {
        return b;
    }
    else if(b==NULL)
    {
        return a;
    }
    if(a->data > b->data)
    {
        list=b;
        list->next=merge(a,b->next);
    }
    else
    {
        list=a;
        list->next=merge(a->next,b);
    }
    return list;
}
void mergesort(struct node** Node)
{
    head=*Node;
    struct node* a=NULL;
    struct node* b=NULL;

    if(head==NULL || head->next== NULL)
    {
        return;
    }
    split(head,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *Node=merge(a,b);
}

void Free(struct node *head)
{
    struct node*temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    head=NULL;
}

void display()
{
    struct node* temp=head;
    printf("current list is");
    while(temp != NULL)
    {
        printf("%d,",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int i;
    unsigned int num;
    head=NULL;
    for(i=0;i<100;i++)
    {
        num=rand();
        add(&head,num);
    }
    display();
    mergesort(&head);
    printf("\n");
    display();
    Free(head);
    return 0;
}










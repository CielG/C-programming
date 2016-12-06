#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int data;
    struct Node* next; //store the address of the next node
}* head;//point to the first node in the linked list

void Display();
void Put(int x);
void Free(struct Node*head);

int main()
{
    head=NULL; //empty list
    int n,i,x;
    printf("enter the number of your list\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("enter your element\n");
        scanf("%d",&x);
        Put(x);
        Display();
    }
    Free(head);
}

void Put(int x)
{
    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));//create a node
    temp->data=x;//put in the data
    temp->next=head;//make next node as head
    head=temp;//let head point to the next node
}
void Display()
{
    struct Node* temp=head;
    printf("Current list is ");
    while(temp !=NULL)//traversal the linked list
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void Free(struct Node*head)
{
    struct Node*temp;
    while(head != NULL)//traverse entire list
    {
        temp=head;//save head pointer
        head=head->next; //advance to next
        free(temp);//free the saved one
    }
    head=NULL;//mark as empty list
}

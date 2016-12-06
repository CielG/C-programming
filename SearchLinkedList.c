#include<stdlib.h>
#include<stdio.h>
struct Node
{
    int data;
    struct Node* next; //store the address of the next node
}* head;//point to the first node in the linked list

void Display();
void Put(int x);
void Search(int n);
void Free(struct Node*head);

void main()
{
    int n,i;
    head=NULL; //empty list
    Put(2);
    Put(4);
    Put(7);
    Put(9);
    Display();
    printf("enter the element you wanna Search\n");
    scanf("%d",&n);
    Search(n);
    Free(head);
}
void Put(int x)
{
    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));//create a node
    temp->data=x;//put in the data
    temp->next=head;//make next node as head
    head=temp;//let head point to the next node
}
void Search(int n)
{
    while(head != NULL)
    {
        if(head ->data == n)
        {
            printf("element found\n");
            return;
        }
        head =head->next;
    }
    printf("element don't exist in this list");
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
    head=NULL;
}

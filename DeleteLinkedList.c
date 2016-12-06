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
void Delete(int n);
int main()
{
    int n,i;
    head=NULL; //empty list
    Put(2);
    Put(4);
    Put(7);
    Put(9);
    Display();
    printf("enter the position of element you wanna delete\n");
    scanf("%d",&n);
    Delete(n);
    Display();
    Free(head);
}
void Delete(int n)
{
    struct Node* temp1=head; // temp points to what head points
    if(n==1)
    {
        head=temp1->next; //break the link,head now points to next node
        free(temp1);  //delete
        return;
    }
    int i;
    for(i=0; i<n-2; i++)
    {
        temp1=temp1->next;//points to (n-1)th node
    }
    struct Node*temp2 = temp1-> next; //nth Node
    temp1->next = temp2->next; //(n+1)th Node
    free(temp2); //delete
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
    head=NULL;
}

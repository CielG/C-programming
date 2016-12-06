#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next; //store the address of the next node
}* head;
void Display();
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
void Display()
{
    struct Node* temp=head;
    //printf("Current list is ");
    while(temp !=NULL)//traversal the linked list
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void Insert(int data,int n)
{
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
    temp1->data=data;
    temp1->next=NULL;
    if(n == 1)
    {
        temp1->next=head;//make temp1 points to whatever the head points
        head=temp1;//break original link, make head points to new node
        return;
    }
    struct Node* temp2=(struct Node*)malloc(sizeof(struct Node));
    temp2=head;
    int i;
    for(i=0; i<n-2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

int main()
{
    head=NULL; //empty list
    int n,k,i,sum;
    Insert(2,1);//Create an original linked list
    Insert(4,2);
    Insert(5,1);
    printf("Origin linked list is\n");
    Display();
    printf("How many numbers you wanna insert?\n");
    scanf("%d",&sum);

    for(i=0;i<sum;i++) //Insert numbers you want
    {
        printf("Enter the position you wanna insert\n");
        scanf("%d",&n);
        if(n>3+sum)
        {
            printf("Wrong position\n");
        }
        else{
            printf("Enter the number you wanna insert\n");
            scanf("%d",&k);
            Insert(k,n);
            Display();
        }
    }
      Free(head);
}



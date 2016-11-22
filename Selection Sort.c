#include<stdio.h>
void Selection_sort(int A[],int n);

void main()
{   int i,n;
    int a[20];

    printf("Enter the size of your array\n");
    scanf("%d",&n);

    printf("Enter your list\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    Selection_sort(a,n);

    for(i=0;i<n;i++)
    {
      printf("%d\n",a[i]);
    }

}

void Selection_sort(int A[],int n)
{
    int i,j,min,temp;
    for (i=0;i<n-1;i++)
    {
        min=i;
        for (j=i+1;j<n;j++)
        {
        if (A[min]>A[j])
           min=j;
        }
         temp=A[i];
         A[i]=A[min];
         A[min]=temp;
    }
}

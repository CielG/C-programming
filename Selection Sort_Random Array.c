#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand((unsigned)time(NULL));
    int i,a[20];
    int size=sizeof (a)/sizeof (a[0]);
    for(i=0;i<size;i++)
    {
        a[i]=rand()%100+1;
    }

    printf("The original array:\n");
    for (i=0;i<size;i++)
    {
        printf("%d\n",a[i]);
    }
    Selection_sort(a,size);

    printf("The sorted array:\n");
    for (i=0;i<size;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
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

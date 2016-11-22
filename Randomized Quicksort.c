#include<stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int A[],int l, int r)
{
    int i,j,pivot;
    pivot=A[r];
    i=l-1;
    for(j=l; j<=r-1; j++)
    {
        if (A[j]<pivot)
        {
            i=i+1;
            swap(&A[i],&A[j]);
        }

    }
    swap(&A[i+1],&A[r]);
    return i+1;
}
void quicksort(int A[],int l, int r)
{
    if (l<r)
    {
        int key=partition(A,l,r);
        quicksort(A,l,key-1);
        quicksort(A,key+1,r);
    }
}

void main()
{
    int n,i,j,a[100];

    printf("Enter the size of your array \n");
    scanf("%d",&n);

    printf("Enter your array \n");
    for (i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    srand((unsigned)time(NULL)); //random_shuffle
    for (i=0; i<n; i++)
    {
        j= rand() %n;
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }

    quicksort(a,0,n-1);

    for (i=0; i<n; i++)
    {
        printf("%d\n",a[i]);

    }
}

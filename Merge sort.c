#include<stdio.h>
void merge(int A[],int T[],int start,int mid,int end)
{
    int i=start,j=mid+1;
    int k=0;
    while(i<=mid && j<=end)
    {
        if(A[i]<=A[j])
        {
            T[k++]=A[i++];
        }
        else
        {
            T[k++]=A[j++];
        }
    }
    while(i<=mid)
    {
        T[k++]=A[i++];
    }
    while(j<=end)
    {
        T[k++]=A[j++];
    }
    for(i=start,k=0;i<=end;i++,k++)
    {
        A[i]=T[k];
    }
}
void mergesort(int a[],int T[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergesort(a,T,start,mid);
        mergesort(a,T,mid+1,end);
        merge(a,T,start,mid,end);
    }
}

int main()
{
    int n,i,a[100],t[100];

    printf("Enter the size of your array \n");
    scanf("%d",&n);

    printf("Enter your array \n");

    for (i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,t,0,n-1);
    for (i=0; i<n; i++)
    {
        printf("%d\n",a[i]);

    }
    return 0;
}

#include<stdio.h>

void max_heapify(int A[],int i,int len)
{
  int max=i;
  int temp=0;
  int l=2*i+1;
  int r=2*i+2;
  if(l<len && A[l]>A[max])
    {
       max=l;
    }
  if(r<len && A[r]>A[max])
    {
       max=r;
    }
  if(max != i)
    {
      temp=A[i];
      A[i]=A[max];
      A[max]=temp;
      max_heapify(A,max,len);
    }
}
void build_max_heap(int A[],int len)
{
  int i;
  for(i=(len/2)-1;i>=0;i--)
    {
      max_heapify(A,i,len);
    }
}
void heapsort1(int A[],int len)
{
  int i,temp;
  build_max_heap(A,len);
  for(i=len-1;i>=0;i--)
    {
      temp=A[0];
      A[0]=A[i];
      A[i]=temp;
     max_heapify(A,0,i);
    }
}
int main()
{
  int i,n,a[20];
  printf("enter the size of your array\n");
  scanf("%d",&n);

  printf("enter your array \n");
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
  heapsort1(a,n);
  for(i=0;i<n;i++)
    {
      printf("%d\n",a[i]);
    }
  return 0;
}

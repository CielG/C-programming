#include<stdio.h>
void Insertion_sort(int A[],int n);

int main()
{
  int i,n;
  int a[20];

  printf("Enter the size of your array\n");
  scanf("%d",&n);
  printf("Enter your array \n");
	
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
	
  Insertion_sort(a,n);
  for(i=0;i<n;i++)
    {
      printf("%d\n",a[i]);
    }
  return 0;

}
void Insertion_sort (int A[],int n)
{
  int i,j,key,temp;
  for(i=1; i<n; i++)
    {
      j=i;
      key=A[i];
      while(j>0 && A[j-1]>A[j])
	{
	  temp=A[j];
	  A[j]=A[j-1];
	  A[j-1]=temp;
	  j--;
	}
      A[j]=key;
    }
}

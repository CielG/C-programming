#include<stdio.h>

void heapsort(int a[],int n)
{
  int i,max,root,j;
  i=n/2;

  while(1)
    {
      if(i>0)
	{
	  i--;
	  max=a[i];
	}
      else
	{
	  n--;
	  if(n==0)
	    {
	      return;
	    }
	  max=a[n];
	  a[n]=a[0];
	}

    root=i;
    j=i*2;

      while(j<n)
	{
	  if(j+1<n && a[j+1]>a[j])
	    {
	      j++;
	    }
	  if(a[j]>max)
	    {
	      a[root]=a[j];
	      root=j;
	      j=root*2+1;
	    }
	  else
	    {
	      break;
	    }
	  a[root]=max;
	}
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
    heapsort(a,n);
    for(i=0;i<n;i++)
      {
	printf("%d\n",a[i]);
      }
    return 0;
  }


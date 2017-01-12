#include<stdio.h>
#include<stdlib.h>
struct array
{
  int *data;
  int capacity;
  int size;
};
void initialize(struct array *p)
{
   p->capacity=1;
   p->data=(int*)malloc(p->capacity*sizeof(int));
   p->size=0;
}
void FREE(struct array *p)
{
  free(p->data);
  p->size=0;
  p->capacity=1;
}
void expand(struct array *p,int a)
{
  if(p->size == p->capacity)
    {
      p->capacity=p->capacity*2;
      p->data=realloc(p->data,p->capacity*sizeof(int));
    }
  p->data[p->size++]=a;
}
int main()
{
  struct array a;
  int i,x;
  initialize(&a);
  printf("Enter the number\n");
  while(1)
    {
     
      if(scanf("%d",&x) == EOF)
	{
	  printf("End of input\n");
	  break;
	}
      else
	expand(&a,x);	
    }
  for(i=0;i<a.size;i++)
   {
     printf("%d",a.data[i]);
   }
  FREE(&a);
  return 0;
}

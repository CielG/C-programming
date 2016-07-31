#include<stdio.h>
#include<stdlib.h>

struct info
{
  int ID;
  char name[10];
  float salary;
}emp[5]={
    {01,"Dean",12337},
    {02,"Caroline",11100},
    {03,"Klaus",28659},
    {04,"Charlotte",23897},
    {05,"Carson",46086},

};

int sort (int sum,int i)
{   int j;
    sum=5;
    struct info temp;
    for ( i=0; i< sum-1; i++)
    {
      for( j=0; j<sum-1-i; j++)
	{
	  if(emp[j].salary>emp[j+1].salary)
	    {
	      temp=emp[j];
	      emp[j]=emp[j+1];
	      emp[j+1]=temp;
	    }
	}
    }
    return sum;
}

int main()
{
  int sort (int sum,int i);
  int i,sum;
  i=0,sum=0;
  printf("sum is %d    ID         name              salary \n",sort(sum,i));
  for( i=0; i<5; i++)
    {
      printf("%14d%15s%24f\n",emp[i].ID,emp[i].name,emp[i].salary);
    }
}

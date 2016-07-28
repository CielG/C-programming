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

int main()
{
  int sum=5;
  int i,j;
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
  printf("sum is %d    ID    name          salary \n",sum);
  for( i=0; i<5; i++)
    {
      printf("             %d      %s          %f \n",emp[i].ID,emp[i].name,emp[i].salary);
    }
}

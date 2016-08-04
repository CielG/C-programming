#include<stdio.h>
#include<math.h>
int count (int y,int m,int d)
{
  int f;

  int s[10]={0,31,61,92,122,153,184,214,245,275};

  if ( m>=3 )
    {
      f=y*365+y/4-y/100+y/400+s[m-3]+d;
    }
  else if ( 0<m && m<3)
    {
      f=(y-1)*365+(y-1)/4-(y-1)/100+(y-1)/400+306+31*(m-1)+d;
    }

  return f;
}
int main(void)
{
  int y1,m1,d1,y2,m2,d2;
  int diff;
  diff=0;
 
      printf("start date:\n");
      scanf("%d%d%d",&y1,&m1,&d1);
      printf("end date:\n");
      scanf("%d%d%d",&y2,&m2,&d2);

      diff =count(y2,m2,d2)-count(y1,m1,d1);
      diff =abs(diff);
      
      printf("%d\n",diff);
    

  return 0;
}


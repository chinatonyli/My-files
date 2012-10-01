#include <stdio.h>
#include <math.h>
int main( void )
{
  int m=5;
  int a[5]={1,3,5,7,9};
  int b[5]={3,4,5,6,7};
  int c[5]={0};
  int d[10]={0};
  int k=0;
  int l=0;
  int isSame;

  for (int i=0;i<m;i++)
  {   isSame=0;
      d[i]=b[i];
      for (int j=0;j<m;j++)
      {
          if (a[i]==b[j])
          {
              c[k]=a[i];//求交集
              isSame =1;
              printf("c[%d]=%d\n",k,c[k]);
              k++;
          }
      }
      if (isSame==0)
      {
          d[m+l]=a[i];//求并集
          printf("d[%d]=%d\n",m+l,d[m+l]);
          l++;
      }
  }

return 1;
}

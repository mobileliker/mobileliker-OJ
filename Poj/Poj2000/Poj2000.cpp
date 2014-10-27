#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int main()
{
    int a,b;
    int i;
    int sum;
    scanf("%d",&a);
    while(a!=0)
    {
       sum=0;
       b=(sqrt(8*a+1)-1)/2;
       for(i=1;i<=b;i++)
       {
          sum+=i*i;
       }
       sum+=(b+1)*(a-b*(b+1)/2);
       printf("%d %d\n",a,sum);
       scanf("%d",&a);
    }
    return 0;
}
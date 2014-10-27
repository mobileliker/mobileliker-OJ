#include "stdio.h"
//#include "stdlib.h"
#define NUM 200
int aa[NUM];
int main()
{
    int t,n;
    int i,j,k;
    int a,b;
    int tmp;
    int max;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
       for(j=0;j<NUM;j++) aa[j]=0;
       scanf("%d",&n);
       for(j=0;j<n;j++)
       {
          scanf("%d%d",&a,&b);
          if(a>b){tmp=a;a=b;b=tmp;}
          for(k=(a-1)/2;k<=(b-1)/2;k++) aa[k]++;
       }
       max=-1;
       for(int j=0;j<NUM;j++){if(aa[j]>max)max=aa[j];}
       printf("%d\n",max*10);
       
    }
    //system("pause");
    return 0;
}
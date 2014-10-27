#include "stdio.h"
//#include "stdlib.h"
#define N 26
int b[2][N];
int Partition(int a[],int p,int r)
{
    int tmp = a[p];
    while(p<r)
    {
        while(p<r && a[r]>=tmp) r--;
        a[p]=a[r];
        while(p<r && a[p]<=tmp) p++;
        a[r]=a[p];
    }
    a[p]=tmp;
    return p;
}
void qsort(int a[],int p,int r)
{
   int q=0;
   if(p<r)
   {
      q=Partition(a,p,r);
      qsort(a,p,q-1);
      qsort(a,q+1,r);
   }
}
int main()
{
    int i,j;
    char ch;
    for(i=0;i<2;i++)
    {
        while((ch=getchar())!='\n') b[i][ch-'A']++;
        qsort(b[i],0,N-1);
    }
    //for(i=0;i<N;i++) printf("%d ",b[0][i]);
    //for(i=0;i<N;i++) printf("%d ",b[1][i]);
    for(i=0;i<N;i++) if(b[0][i]!=b[1][i]) break;
    if(i>=N) printf("YES\n");
    else printf("NO\n");
    //system("pause");
    return 0;
}

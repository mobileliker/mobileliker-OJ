#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include <time.h>
#define N 10002
using namespace std;
int a[N];
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
int RandomizePartition(int a[],int p,int r)
{
    int i = rand()%(r-p+1)+p;
    int tmp=a[i];
    a[i]=a[p];
    a[p]=tmp;
    return Partition(a,p,r);
}

int RandomizedSelect(int a[],int p,int r,int k)
{
    if(p==r) return a[p];
    int i = RandomizePartition(a,p,r),j = i-p+1;
    if(k<=j) return RandomizedSelect(a,p,i,k);
    else return RandomizedSelect(a,i+1,r,k-j);
}
int main()
{
    srand(time(NULL));//初始化随机数生成器
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    //qsort(a,0,n-1);
    //printf("%d\n",a[n/2]);
    printf("%d\n",RandomizedSelect(a,0,n-1,(n+1)/2));
    system("pause");
    return 0;
}

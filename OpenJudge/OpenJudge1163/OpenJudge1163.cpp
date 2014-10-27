#include "stdio.h"
//#include "stdlib.h"
#define N 102
int a[N][N];
int main()
{
    int count;
    int i,j;
    scanf("%d",&count);
    for(i = 0 ;i <count;i++)
    {
       for(j=0;j<=i;j++)
       {
           scanf("%d",&a[i][j]);
       }
    }
    for(i = count -2;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            a[i][j] += ((a[i+1][j]>a[i+1][j+1])?a[i+1][j]:a[i+1][j+1]);
        }
    }
    printf("%d",a[0][0]);
    //system("pause");
    return 1;
} 
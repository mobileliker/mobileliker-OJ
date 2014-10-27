#include "stdio.h"
//#include "stdlib.h"
#include <math.h>

int main()
{
    int m;
    scanf("%d",&m);
    int k = (int)((sqrt((float)(1)+8*m)+1)/2);
    while((k*k+k-2*m)%4!=0)
    {
        k++;
    }
    printf("%d",k);
    //system("pause");
    return 0;
}
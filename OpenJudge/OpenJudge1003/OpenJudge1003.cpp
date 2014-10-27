#include "stdio.h"
//#include "stdlib.h"
int main()
{
    float a,sum;
    int i;
    scanf("%f",&a);
    while(a!=0)
    {
        i = 2;
        sum = 0;
        while(sum < a)
        {
            sum += ((float)1/i); 
            i++;
        }
        printf("%d card(s)\n",i-2);
        scanf("%f",&a);
    }
    //system("pause");
    return 1;
}
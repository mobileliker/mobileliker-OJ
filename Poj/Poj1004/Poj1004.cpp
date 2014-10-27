#include "stdio.h"
//#include "stdlib.h"
int main()
{
    int i=0;
    float tmp=0,sum=0;
    for(i=0;i<12;i++)
    {
       scanf("%f",&tmp);
       sum+=tmp;
    }
    printf("$%.2f",sum/12);
    //system("pause");
	return 0;
}
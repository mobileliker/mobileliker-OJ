#include "stdio.h"
#include "stdlib.h"

int f(char input[],int start)
{
    int ans=0;
    int i;
    for(i=0;i<8;i++)
    {
       ans=ans*2+(input[i+start]-'0');
    }
    return ans;
}
int main()
{
    int a,b,c,d;
    int n;
    int i;
    char input[34];
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        gets(input);
        a=f(input,0);
        b=f(input,8);
        c=f(input,16);
        d=f(input,24);
        printf("%d.%d.%d.%d\n",a,b,c,d);
    }
    //system("pause");
    return 0;
}
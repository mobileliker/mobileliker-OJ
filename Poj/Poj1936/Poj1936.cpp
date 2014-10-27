#include "stdio.h"
//#include "stdlib.h"
#include "string.h"
#define NUM 100002
char s[NUM],t[NUM];
int main()
{
    int i,j;
    int len_s,len_t;
    while(scanf("%s%s",s,t) != EOF)
    {
        len_s=strlen(s);
        len_t=strlen(t);
        i=0;j=0;
        while(i<len_s && j<len_t)
        {
           if(s[i]==t[j]) i++;
           j++;
        }
        //printf("%s%s\n",s,t);
        if(i>=len_s) printf("Yes\n");
        else printf("No\n");
    }
    //system("pause");
    return 0;
}
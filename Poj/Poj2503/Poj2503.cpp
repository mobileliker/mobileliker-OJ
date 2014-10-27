#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

#define MAX_LENGTH 11
#define MAX_CONTENT 100002

struct dic
{
   char key[MAX_LENGTH];
   char value[MAX_LENGTH];
}a[MAX_CONTENT];

int mycmp(const void *x,const void *y)
{
    return strcmp(((dic*)x)->key,((dic*)y)->key);
}

int mycmp_bsearch(const void *x,const void *y)
{
    return strcmp((char*)x,((dic*)y)->key);
}


int main()
{
    char key[MAX_LENGTH],value[MAX_LENGTH];
    dic* result;
    int i=0;
    while((value[0]=getchar())!='\n')
    {
        scanf("%s %s",value+1,key);
        strcpy(a[i].key,key);
        strcpy(a[i++].value,value);
        getchar();
    }
    
    qsort(a,i,sizeof(dic),mycmp);
    
    while(scanf("%s",key)!=EOF)
    {
        result=(dic*)bsearch(key,a,i,sizeof(dic),mycmp_bsearch);
        if(result==NULL) printf("eh\n");
        else printf("%s\n",result->value);
    }
    //system("pause");
    return 0;
}

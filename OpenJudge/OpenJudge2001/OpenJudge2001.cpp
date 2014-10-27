//2010-05-09
//create by wuzhihui
#include<iostream>
#include <cstdio>
#include <cstdlib>


using namespace std;

#define chars 26
#define MAXCONTENT 1002
#define MAXLENGTH 21


typedef struct TrieNode
{
    int num;
    TrieNode *next[chars];
}TrieNode,*TrieTree;
char str[MAXCONTENT][MAXLENGTH];

TrieTree root=NULL;

void insert(char *s)
{
     int k=0;
     
     if(root==NULL)
     {
         root=(TrieTree)malloc(sizeof(TrieNode));
         root->num=0;
         for(k=0;k<chars;k++) root->next[k]=NULL;
     }
     TrieTree p=root;
     
     int i=0;
     int index;
     while(s[i]!='\0')
     {
        index=s[i]-'a';
        if(p->next[index]==NULL) 
        {
            p->next[index]=(TrieTree)malloc(sizeof(TrieNode));
            p->next[index]->num=0;
            for(k=0;k<chars;k++) p->next[index]->next[k]=NULL;
        }
        p=p->next[index];
        p->num++;
        i++;
     }
}

void search(char *s)
{
     int i=0,index;
     TrieTree p=root;
     while(s[i]!='\0')
     {
          index=s[i]-'a';
          p=p->next[index];
          putchar(s[i]);
          if(p->num==1) break;
          i++;
     }
     putchar('\n');
}
int main()
{
    int size=0,i;
    //int n=12;
    while(scanf("%s",str[size])!=EOF)
    //while(n-- && scanf("%s",str[size])!=EOF)
    {
         insert(str[size]);
         size++;
    }
    for(i=0;i<size;i++)
    {
       printf("%s ",str[i]);
       search(str[i]);
    }
    //system("pause");
    return 0;
}
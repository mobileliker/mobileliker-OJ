#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n,m;
int map[30][30];
int reg[100];
int in[30],out[30];
char ans[30];
int stack[30];
void fun()
{
     int i,j;
     for(i='A',j=1;i<='Z';i++,j++)reg[i]=j;
}
void toposort(char *ans)
{
    int i,top=0,u,s=0;
    for(i=1;i<=n;i++)
     if(in[i]==0)stack[top++]=i;
    while(top!=0)
    {
       u=stack[--top];
       ans[s++]=u+64;
       for(i=1;i<=n;i++)
       {
         if(map[u][i])
         {
            in[i]--;
            if(!in[i])stack[top++]=i;
         }
       }
    }
    ans[s]=0;
}
int main()
{
    int i,j,x,y,k,flag1,flag2,flag;
    fun();
    char ch[5];
    while(1)
    {
      flag1=flag2=0;
      memset(map,0,sizeof(map));
      scanf("%d%d",&n,&m);
      if(n==0&&m==0)break;
      for(i=1;i<=m;i++)
      {
         flag=1;
         scanf("%s",ch);
         x=reg[ch[0]];
         y=reg[ch[2]];
         map[x][y]=1;
         if(x==y)flag1=i;
         memset(in,0,sizeof(in));
         memset(out,0,sizeof(out));
         if(!flag1&&!flag2)
         for(j=1;j<=n;j++)
          for(k=1;k<=n;k++)
          {
             if(j!=x&&k!=y)map[j][k]=map[j][k]||(map[j][x]&&map[y][k]);
             if(j==x&&k!=y)map[j][k]=map[j][k]||map[y][k];
             if(j!=x&&k==y)map[j][k]=map[j][k]||map[j][x];
             if(map[j][k])
             {
               out[j]++;
               in[k]++;
             }
          }
         j=1;
         if(!flag1)
         for(j=1;j<=n;j++)
         {
           if(map[j][j])flag1=i;
           if(in[j]+out[j]!=n-1)flag=0;
         }
         if(flag&&!flag2&&j>n){flag2=i;toposort(ans);}
      }
      if(flag2)
      {
         printf("Sorted sequence determined after %d relations: %s.\n",flag2,ans);
         continue;
      }
      if(flag1)
      {
         printf("Inconsistency found after %d relations.\n",flag1);
         continue;
      }
      printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
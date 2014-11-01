#include<iostream>
#include<queue>
using namespace std;
#define MAX 10002
//#define MAX 102
int a[MAX];
int b[MAX];
int main()
{
    int n,m;
    int i,j;
    int x,y;
    int k;
    queue<int> q;
    a[2]=0; 
    for(i=4;i<MAX;i+=2) a[i]=1; 
    for(i=3;i<=MAX/2;i++)
    {
        if(a[i]==0)
        {
           for(j=i;j<MAX/i;j+=2)
           {
               a[i*j]=1;     
           }
        }
    }
    //验证素数表的正确性
    /*for(i=2;i<MAX;i++)
    {
       if(a[i]==1) printf("%d是素数\n",i);
       else printf("%d不是素数\n",i);
    }*/ 
    cin>>n;
    for(int ii=0;ii<n;ii++)
    {
        cin>>x>>y;
        for(j=0;j<MAX;j++) b[j]=-1;
        while(!q.empty()) q.pop();
        q.push(x);
        b[x]=0;
        while(!q.empty())
        {
            m=q.front();
            if(m==y) break;
            else
            {
                for(i=0;i<4;i++)
                {
                    k=1;
                    for(j=0;j<i;j++) k=k*10;
                    for(j=-9;j<=9;j++)
                    {
                        if(((m/(k*10))==((m+j*k)/(k*10)))&&(a[m+j*k]==0)&&(b[m+j*k]==-1)&&(m+j*k)>=1000)
                        {
                             //printf("perfect");
                             b[m+j*k]=b[m]+1;
                             q.push(m+j*k);
                        }
                    }
                }
            }
            q.pop();
        }
        cout<<b[y]<<endl;   
    }
    //system("pause");
    return 1;
}
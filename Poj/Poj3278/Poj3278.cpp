#include<iostream>
#include<queue>

using namespace std;

//(0 ¡Ü N ¡Ü 100,000)
#define MAX 200002
int a[MAX];
int main()
{
    int i,j;
    int x,y;
    int m,n;
    cin>>x>>y;
    queue<int> q;
    a[x]=1;
    q.push(x);
    while(!q.empty())
    {
        m=q.front();
        if(m==y) {cout<<a[m]-1;break;}
        else
        {
            n=m-1;
            if(n>=0&&n<MAX&&a[n]==0)
            {
                a[n]=a[m]+1;
                q.push(n);
            }
            n=m+1;
            if(n>=0&&n<MAX&&a[n]==0)
            {
               a[n]=a[m]+1;
               q.push(n);
            }
            n=m*2;
            if(n>=0&&n<MAX&&a[n]==0)
            {
               a[n]=a[m]+1;
               q.push(n);
            }
        }
        q.pop();
    }
    //system("pause");
    return 0;
}
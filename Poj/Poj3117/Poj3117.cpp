#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int i;
    int t,n;
    int num,a;
    char ch[12];
    while((cin>>t>>n)&&(t!=0||n!=0))
    {
       num=0;
       for(i=0;i<t;i++)
       {  
           scanf("%s",ch);
           cin>>a;
           num+=a;
       }
       cout<<(3*n-num)<<endl;
    }
    //system("pause");
    return 0;
}
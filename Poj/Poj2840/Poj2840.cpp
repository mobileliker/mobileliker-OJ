#include<iostream>
#include <cstdio>

using namespace std;

int main()
{
    int i,n;
    int a,b;
    cin>>n;
    for(i=0;i<n;i++)
    {
        scanf("%d:%d",&a,&b);
        if(b!=0) cout<<0<<endl;
        else
        {
            if(a<=12) cout<<(a+12)<<endl;
            else cout<<(a-12)<<endl;
        }
    }
    //system("pause");
    return 0;
}
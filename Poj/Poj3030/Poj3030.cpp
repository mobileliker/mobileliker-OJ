#include<iostream>
using namespace std;
int main()
{
    int i,n;
    int r,e,c;
    int result;
    cin>>n;
    for(i=0;i<n;i++)
    {
       cin>>r>>e>>c;
       result=e-c-r;
       if(result>0) cout<<"advertise"<<endl;
       else if(result<0) cout<<"do not advertise"<<endl;
       else cout<<"does not matter"<<endl;
    }
    //system("pause");
    return 1;
    
}
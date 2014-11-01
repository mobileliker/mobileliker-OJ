#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double x,y,z;
    double a,b,c;
    double p,q,r;
    while(cin>>x>>y>>z)
    {
        a=(z-2*y+x)/2;
        b=2*y-3*x/2-z/2;
        c=x;
        //cout<<a<<" "<<b<<" "<<c<<endl;
        p=a*3*3+b*3+c;
        q=a*4*4+b*4+c;
        r=a*5*5+b*5+c;
        printf("%.0lf %.0lf %.0lf\n",p,q,r);
    }
    //system("pause");
    return 0;
}
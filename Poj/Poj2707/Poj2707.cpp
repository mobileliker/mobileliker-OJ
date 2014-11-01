#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    int temp;
    int e,f;
    while((cin>>a>>b>>c>>d)&&!(a==0&&b==0&&c==0&&d==0))
    {
       if(a<b)
       {
          temp=a;
          a=b;
          b=temp;
       }
       if(c<d)
       {
          temp=c;
          c=d;
          d=temp;
       }
       e=c*100/a;
       f=d*100/b;
       if(e<f)
       {
          if(e>100) e=100;
          cout<<e<<"%"<<endl;
       }
       else
       {
           if(f>100) f=100;
           cout<<f<<"%"<<endl;
       }
    }
    //system("pause");
    return 0;
}
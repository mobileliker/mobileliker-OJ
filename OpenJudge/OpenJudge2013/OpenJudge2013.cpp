#include<iostream>
#include<cstdio>
#include <cstring>
using namespace std;
char a[16][26];
int main()
{
   int i,count=1,n;
   while(scanf("%d",&n)!=EOF&&n)
   {
       memset(a, 0, sizeof(a)); 
       for(i=0;i<n;i++) cin>>a[i];
       printf("SET %d\n",count);
       count++;
       for(i=0;i<n;i+=2) cout<<a[i]<<endl;
       for(i=n-1-(n%2);i>=1;i-=2) cout<<a[i]<<endl;
   }
   //system("pause");
   return 1;
}
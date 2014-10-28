/*代码一：构造法*/

//Memory Time 
//188K   16MS 

#include<iostream>
#include<cmath>
using namespace std;

int main(int i)
{
	int n;  //皇后数
	while(cin>>n)
	{
		if(!n)
			break;

		if(n%6!=2 && n%6!=3)
		{
			if(n%2==0)  //n为偶数
			{
				for(i=2;i<=n;i+=2)
					cout<<i<<' ';
				for(i=1;i<=n-1;i+=2)
					cout<<i<<' ';
				cout<<endl;
			}
			else   //n为奇数
			{
				for(i=2;i<=n-1;i+=2)
					cout<<i<<' ';
				for(i=1;i<=n;i+=2)
					cout<<i<<' ';
				cout<<endl;
			}
		}
		else if(n%6==2 || n%6==3)
		{
			if(n%2==0)  //n为偶数
			{
				int k=n/2;
				if(k%2==0)  //k为偶数
				{
					for(i=k;i<=n;i+=2)
						cout<<i<<' ';
					for(i=2;i<=k-2;i+=2)
						cout<<i<<' ';
					for(i=k+3;i<=n-1;i+=2)
						cout<<i<<' ';
					for(i=1;i<=k+1;i+=2)
						cout<<i<<' ';
					cout<<endl;
				}
				else  //k为奇数
				{
					for(i=k;i<=n-1;i+=2)
						cout<<i<<' ';
					for(i=1;i<=k-2;i+=2)
						cout<<i<<' ';
					for(i=k+3;i<=n;i+=2)
						cout<<i<<' ';
					for(i=2;i<=k+1;i+=2)
						cout<<i<<' ';
					cout<<endl;
				}
			}
			else   //n为奇数
			{
				int k=(n-1)/2;
				if(k%2==0)  //k为偶数
				{
					for(i=k;i<=n-1;i+=2)
						cout<<i<<' ';
					for(i=2;i<=k-2;i+=2)
						cout<<i<<' ';
					for(i=k+3;i<=n-2;i+=2)
						cout<<i<<' ';
					for(i=1;i<=k+1;i+=2)
						cout<<i<<' ';
					cout<<n<<endl;
				}
				else  //k为奇数
				{
					for(i=k;i<=n-2;i+=2)
						cout<<i<<' ';
					for(i=1;i<=k-2;i+=2)
						cout<<i<<' ';
					for(i=k+3;i<=n-1;i+=2)
						cout<<i<<' ';
					for(i=2;i<=k+1;i+=2)
						cout<<i<<' ';
					cout<<n<<endl;
				}
			}
		}
	}
	return 0;
}
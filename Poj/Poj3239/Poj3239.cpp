/*����һ�����취*/

//Memory Time 
//188K   16MS 

#include<iostream>
#include<cmath>
using namespace std;

int main(int i)
{
	int n;  //�ʺ���
	while(cin>>n)
	{
		if(!n)
			break;

		if(n%6!=2 && n%6!=3)
		{
			if(n%2==0)  //nΪż��
			{
				for(i=2;i<=n;i+=2)
					cout<<i<<' ';
				for(i=1;i<=n-1;i+=2)
					cout<<i<<' ';
				cout<<endl;
			}
			else   //nΪ����
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
			if(n%2==0)  //nΪż��
			{
				int k=n/2;
				if(k%2==0)  //kΪż��
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
				else  //kΪ����
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
			else   //nΪ����
			{
				int k=(n-1)/2;
				if(k%2==0)  //kΪż��
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
				else  //kΪ����
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
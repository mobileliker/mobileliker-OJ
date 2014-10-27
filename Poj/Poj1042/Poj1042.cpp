//2010-04-22
//v0.1 create by wuzhihui
#include<iostream>
using namespace std;

int ti[194];//ti (0 < ti <=192
int fi[194];
int fi2[194];
int di[194];
int a[194];
int maxa[194];
int main()
{
	int i,j;
	int h,h2;//hour between 1<=h<=16
	int n;//lake 2 <= n <= 25
	int fishes;
	int maxfishes,temp;
	int max;
	while((cin>>n)&&n!=0)
	{
		cin>>h;
		for(i=0;i<n;i++) cin>>fi[i];
		for(i=0;i<n;i++) cin>>di[i];
		for(i=0;i<n-1;i++) cin>>ti[i];
		max=-1;
		for(j=0;j<n;j++) a[j]=0;
		for(i=0;i<n;i++)
		{
			h2=h*12;
			//memset(a,0,sizeof(a));
			for(j=0;j<n;j++) a[j]=0;
			fishes=0;
			for(j=0;j<n;j++) fi2[j]=fi[j];
			for(j=0;j<=i-1;j++) h2-=ti[j];
			while(h2>0)
			{
				maxfishes=-1;
				for(j=0;j<=i;j++)
				{
					if(fi2[j]>maxfishes)
					{
						maxfishes=fi2[j];
						temp=j;
					}//if
				}//for_j
				fishes+=maxfishes;
				a[temp]++;
				if(fi2[temp]<di[temp]) fi2[temp]=0;
				else fi2[temp]-=di[temp];
				h2--;
			}//while_h2
			if(max<fishes)
			{
				max=fishes;
				for(j=0;j<n;j++) maxa[j]=a[j];
			}//if
		}//while_n
		cout<<(maxa[0]*5);
		for(i=1;i<n;i++) cout<<", "<<(maxa[i]*5);
		cout<<endl;
		cout<<"Number of fish expected: "<<max<<endl<<endl;
	}
	

	return 1;
}
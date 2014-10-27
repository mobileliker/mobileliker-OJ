#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a,b;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a>=b) cout<<"MMM BRAINS"<<endl;
		else cout<<"NO BRAINS"<<endl;
	}
	//system("pause");
	return 0;
}
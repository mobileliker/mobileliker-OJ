#include <iostream>

using namespace std;

int f(int a)
{
	if(a == 1 || a == 2) return 1;
	else return f(a - 1) + f(a - 2);
}

int main()
{
	int n;
	cin>>n;

	int a;
	while(n--)
	{
		cin>>a;
		cout<<f(a)<<endl;
	}

	return 0;
}
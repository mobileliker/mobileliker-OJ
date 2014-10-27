#include <iostream>
#include <cstdio>

using namespace std;

int f(int s,int a)
{
	int i;
	int res = 1;
	for(i = s; i * i <= a; ++i)
	{
		if(a % i == 0) res += f(i,a / i);
	}
	return res;
}

int main()
{
	//freopen("C://input.txt","r",stdin);

	int n;
	cin >> n;

	int a;
	while(n--)
	{
		cin >> a;
		cout << f(2,a) << endl;
	}

	return 0;
}
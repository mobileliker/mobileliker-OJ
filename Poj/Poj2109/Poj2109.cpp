#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	freopen("D://input.txt","r",stdin);
	
	double p,n;
	
	while(cin >> n >> p)
	{
		cout << pow(p,1.0/n) << endl;
	}
	
	return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int arr[8][8];
vector<int> v_res;

void f(int res,int i)
{
	int j = 0;
	for(j = 0; j < 8; ++j)
	{
		if(arr[i][j] == 0)
		{
			if(i == 7)
			{
				v_res.push_back(
			}
		}
	}
}

int main()
{
	freopen("C://input.txt","r",stdin);

	f(0);

	int i,j;

	int n;
	cin >> n;

	int b;
	while(n--)
	{
		cin>>b;
	}
	return 0;
}
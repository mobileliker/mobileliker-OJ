#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	//freopen("C://input.txt","r",stdin);

	int n;//1 <= n <= 1000
	cin >> n;

	int i,j;

	int *arr = new int[n];
	int *dp = new int[n];

	for(i = 0; i < n; ++i) cin >> arr[i];

	//dp
	dp[0] = 1;
	for(i = 1; i < n; ++i)
	{
		dp[i] = 1;
		for(j = 0; j < i; ++j) if(arr[j] < arr[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
	}

	int max = 1;
	for(i = 0; i < n; ++i) if(dp[i] > max) max = dp[i];
	cout << max << endl;

	return 0;
}
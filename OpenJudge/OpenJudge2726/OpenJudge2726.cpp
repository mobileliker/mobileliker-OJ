#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	//freopen("C://input.txt","r",stdin);

	int i,j;

	int t,m;
	cin >> t >> m;

	int *arr_time = new int[m];
	int *arr_value = new int[m];

	for(i = 0;i < m; ++i) cin >> arr_time[i] >> arr_value[i];

	int *dp = new int[t + 1];
	memset(dp,0,sizeof(int) * (t + 1));

	for(i = m - 1; i >= 0; --i)
	{
		for(j = t; j >= arr_time[i]; --j) dp[j] = dp[j] > (dp[j - arr_time[i]] + arr_value[i]) ? dp[j] : (dp[j - arr_time[i]] + arr_value[i]);
	}

	int max = 0;
	for(j = 0; j <= t; ++j) if(max < dp[j]) max = dp[j];
	
	cout << max << endl;

	delete [] dp;

	delete [] arr_time;
	delete [] arr_value;

	return 0;
}
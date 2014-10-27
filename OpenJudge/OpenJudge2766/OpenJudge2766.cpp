#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	//freopen("C://input.txt","r",stdin);

	int i,j,k;

	int n;
	cin >> n;

	int **arr_matrix = new int*[n];
	for(i = 0; i < n; ++i) arr_matrix[i] = new int[n];


	for(i = 0;i < n; ++i)
	{
		for(j = 0;j < n; ++j)
		{
			cin >> arr_matrix[i][j];
		}
	}

	int *arr_temp = new int[n];

	int *dp = new int[n];

	int max_sum = arr_matrix[0][0];
	for(k = 0; k < n; ++k)
	{
		memset(arr_temp,0,sizeof(int) * n);
		for(j = 0; j < n; ++j)
		{
			for(i = 0; i < k; ++i) arr_temp[j] += arr_matrix[i][j];
		}

		for(i = k; i < n; ++i)
		{
			for(j = 0; j < n; ++j) arr_temp[j] += arr_matrix[i][j];

			memset(dp,0,sizeof(int) * n);
			dp[0] = arr_temp[0];
			for(j = 1; j < n; ++j)
			{
				dp[j] = ((dp[j - 1] + arr_temp[j]) > arr_temp[j]) ? (dp[j - 1] + arr_temp[j]) : arr_temp[j];
				if(max_sum < dp[j]) max_sum = dp[j];
			}

			for(j = 0; j < n; ++j) arr_temp[j] -= arr_matrix[i - k][j];
		}
	}

	cout << max_sum << endl;

	delete [] dp;

	delete [] arr_temp;

	for(i = 0; i < n; ++i) delete [] arr_matrix[i];
	delete [] arr_matrix;

	return 0;
}
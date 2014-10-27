#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxDiff = 400;

int cmp(const void* a,const void *b)
{
	int int_a = *((int *)a);
	int int_b = *((int *)b);

	return int_a - int_b;
}

int main()
{
	//freopen("C://input.txt","r",stdin);

	int i,j,k;
	int temp;
	int temp_path,temp_diff;

	int n,m;
	cin >> n >> m;

	int count = 1;
	while(n != 0 || m != 0)
	{
		int *arr_sum = new int[n];
		int *arr_diff = new int[n];
 
		bool *arr_used = new bool[n];
		memset(arr_used,0,sizeof(bool) * n);

		int int_a,int_b;
		for(i = 0; i < n; ++i)
		{
			cin >> int_a >> int_b;
			arr_sum[i] = int_a + int_b;
			arr_diff[i] = int_a - int_b;
		}

		int **dp = new int*[m];
		for(i = 0; i < m; ++i)
		{
			dp[i] = new int[maxDiff * 2 + 1];
			for(j = 0; j <= maxDiff * 2; ++j) dp[i][j] = -1;
		}

		int **path = new int*[m];
		for(i = 0; i < m; ++i) path[i] = new int[maxDiff * 2 + 1];

		for(i = 0; i < n; ++i)
		{
			temp = arr_diff[i] + maxDiff;
			if(dp[0][temp] < arr_sum[i])
			{
				dp[0][temp] = arr_sum[i];
				path[0][temp] = i;
			}

			//cout << "dp[0][" << temp << "]="  << dp[0][temp] << "path[0][" << temp << "]=" << path[0][temp] << endl;
		}


		for(i = 1; i < m; ++i)
		{
			for(j = 0; j <= maxDiff * 2; ++j)
			{
				if(dp[i - 1][j] != -1)
				{

					temp_diff = j;
					for(k = i - 1; k >= 0; --k)
					{
						temp_path = path[k][temp_diff];
						arr_used[temp_path] = true;
						temp_diff = temp_diff - arr_diff[temp_path];
					}

					for(k = 0; k < n; ++k)
					{
						if(!arr_used[k])
						{
							temp = j + arr_diff[k];
							if(dp[i][temp] == -1 || (dp[i][temp] < dp[i - 1][j] + arr_sum[k]))
							{
								dp[i][temp] = dp[i - 1][j] + arr_sum[k];
								path[i][temp] = k;
							}
						}
					}


					temp_diff = j;
					for(k = i - 1; k >= 0; --k)
					{
						temp_path = path[k][temp_diff];
						arr_used[temp_path] = false;
						temp_diff = temp_diff - arr_diff[temp_path];
					}
				}
			}

		}

		int res_idx;
		for(i = 0; i <= maxDiff; ++i)
		{
			if(dp[m - 1][maxDiff - i] != -1 || dp[m - 1][maxDiff + i] != -1)
			{
				if(dp[m - 1][maxDiff - i] == -1) res_idx = i;
				else if(dp[m - 1][maxDiff + i] == -1) res_idx = - i;
				else
				{
					res_idx = (dp[m - 1][maxDiff + i] > dp[m - 1][maxDiff - i] ? i : (-i));
				}
				break;
			}
		}

		cout << "Jury #" << count++ << endl;
		cout << "Best jury has value " << (dp[m - 1][res_idx + maxDiff] + res_idx) / 2<< " for prosecution and value " << (dp[m - 1][res_idx + maxDiff] - res_idx) / 2<< " for defence:" << endl;

		temp_diff = res_idx + maxDiff;
		int *arr_res = new int[m];
		for(i = m - 1; i >= 0; --i)
		{
			temp_path = path[i][temp_diff];
			arr_res[i] = temp_path + 1;
			temp_diff = temp_diff - arr_diff[temp_path];
		}
		qsort(arr_res,m,sizeof(int),cmp);

		for(i = 0; i < m; ++i) cout << " " << arr_res[i];
		cout << endl;

		delete [] arr_res;

		cout << endl;

		delete [] arr_sum;
		delete [] arr_diff;
		
		for(i = 0; i < m; ++i) delete [] dp[i];
		delete [] dp;

		for(i = 0; i < m; ++i) delete [] path[i];
		delete [] path;

		cin >> n >> m;
	}

	return 0;
}
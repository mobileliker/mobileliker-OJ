#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct FLAT
{
	int x[2];
	int h;
};

int cmp(const void* a,const void* b)
{
	FLAT flat1 = *((FLAT *)a);
	FLAT flat2 = *((FLAT *)b);

	return flat1.h - flat2.h;
}

int main()
{
	//freopen("C://input.txt","r",stdin);

	int t;
	cin >> t; // 0 <= t <= 20

	int i,j,k;

	int n,x,y,max;
	while(t--)
	{
		//1 <= N <= 1000£¬-20000 <= X, X1[i], X2[i] <= 20000£¬0 < H[i] < Y <= 20000£¨i = 1..N£©
		cin >> n >> x >> y >> max;

		FLAT *arr_flat = new FLAT[n];

		for(i = 0; i < n; ++i) cin >> arr_flat[i].x[0] >> arr_flat[i].x[1] >> arr_flat[i].h;
		qsort(arr_flat,n,sizeof(FLAT),cmp);

		//for(i = 0; i < n; ++i) cout << arr_flat[i].x[0] << " " << arr_flat[i].x[1] << " " << arr_flat[i].h << endl;

		int m;
		for(m = n - 1; m >= 0; --m)
		{
			if(y - arr_flat[m].h <= max && x >= arr_flat[m].x[0] && arr_flat[m].x[1] >= x) break; 
		}
		if(m < 0)
		{
			cout << y << endl;
			continue;
		}

		//dp
		int **dp = new int*[m + 1];
		for(i = 0; i <= m; ++i) dp[i] = new int[2];

		dp[0][0] = arr_flat[0].h;
		dp[0][1] = arr_flat[0].h;

		for(i = 1; i <= m; ++i)
		{
			for(j = 0; j < 2; ++j)
			{
				int flag = 0;
				for(k = i - 1; k >= 0; --k)
				{
					if(arr_flat[i].h - arr_flat[k].h > max) break;
					else
					{
						if(arr_flat[k].x[0] <= arr_flat[i].x[j] && arr_flat[k].x[1] >= arr_flat[i].x[j])
						{
							flag = 1;
							break;
						}
					}
				}
				if(flag == 0)
				{
					if(arr_flat[i].h < max) dp[i][j] = arr_flat[i].h;
					else dp[i][j] = -1;
				}
				else
				{
					if(dp[k][0] == -1 && dp[k][1] == -1) dp[i][j] = -1;
					else if(dp[k][0] == -1) dp[i][j] = dp[k][1] + (arr_flat[i].h - arr_flat[k].h) + (arr_flat[k].x[1] - arr_flat[i].x[j]);
					else if(dp[k][1] == -1) dp[i][j] = dp[k][0] + (arr_flat[i].h - arr_flat[k].h) + (arr_flat[i].x[j] - arr_flat[k].x[0]);
					else
					{
						int temp1 = dp[k][0] + (arr_flat[i].h - arr_flat[k].h) + (arr_flat[i].x[j] - arr_flat[k].x[0]);
						int temp2 = dp[k][1] + (arr_flat[i].h - arr_flat[k].h) + (arr_flat[k].x[1] - arr_flat[i].x[j]);
						dp[i][j] = temp1 < temp2 ? temp1 : temp2;
					}
				}
			}
		}

		if(dp[m][0] == -1) cout << dp[m][1] + (arr_flat[m].x[1] - x) + (y - arr_flat[m].h) << endl;
		else if(dp[m][1] == -1) cout << dp[m][0] + (x - arr_flat[m].x[0]) + (y - arr_flat[m].h) << endl;
		else
		{
			int temp1 = dp[m][1] + (arr_flat[m].x[1] - x) + (y - arr_flat[m].h);
			int temp2 = dp[m][0] + (x - arr_flat[m].x[0]) + (y - arr_flat[m].h);
			cout << (temp1 < temp2 ? temp1 : temp2) << endl;
		}


		for(i = 0; i <= m; ++i) delete [] dp[i];
		delete [] dp;

		delete [] arr_flat;
	}


	return 0;
}
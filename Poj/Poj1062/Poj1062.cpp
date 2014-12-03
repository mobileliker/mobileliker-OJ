#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits>

using namespace std;

const int intMax = numeric_limits<int>::max();

int main()
{
	//freopen("D://input.txt","r",stdin);

	int i,j,k,LL;

	int m,n;
	cin >> m >> n;

	//cout << "m=" << m << endl;
	//cout << "n=" << n << endl;

	int **arr_map = new int*[n];
	for(j = 0; j < n; ++j)
	{
		arr_map[j] = new int[n];
		//memset(arr_map[j],0,sizeof(int) * n);
	}
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j) arr_map[i][j] = intMax;
	}

	int *arr_L = new int[n];
	int *arr_p = new int[n];

	int p,L,x;
	//int L0;
	for(i = 0; i < n; ++i)
	{
		cin >> p >> L >> x;
		//cout << p << " " << L << " " << x << endl;
		arr_p[i] = p;
		//if(0 == i) L0 = L;
		arr_L[i] = L;

		int t,v;
		for(j = 0; j < x; ++j)
		{
			cin >> t >> v;
			//cout << t << " " << v << endl;

			//if(abs(L0 - L) <= m)
			//{
				arr_map[i][t - 1] = v;
				arr_map[t - 1][i] = v;
			//}
		}
	}

	//for(i = 1; i < n; ++i)
	//{
	//	if(abs(arr_L[0] - arr_L[i]) > m)
	//	{
	//		for(j = 0; j < n; ++j) 
	//		{
	//			arr_map[i][j] = intMax;
	//			arr_map[j][i] = intMax;
	//		}
	//	}
	//}

	//for(i = 0; i < n; ++i)
	//{
	//	for(j = 0; j < n; ++j)
	//	{
	//		cout << arr_map[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	
	//for(i = 0; i < n; ++i) cout << arr_p[i] << " ";
	//cout << endl;

	//for(i = 0; i < n; ++i) cout << arr_L[i] << " ";
	//cout << endl;

	int *arr_d = new int[n];
	bool *arr_m = new bool[n];

	int min_p = arr_p[0];

	int L_top,L_bottom;
	for(LL = 0; LL <= m; ++LL)
	{
	L_top = arr_L[0] + LL;
	L_bottom = arr_L[0] - m + LL;

	for(i = 1; i < n; ++i)
	{
		if(arr_L[i] > L_top || arr_L[i] < L_bottom) continue;

		memset(arr_m,0,sizeof(bool) * n);
		//memcpy(arr_d,arr_map[i],sizeof(int) * n);
		for(j = 0; j < n; ++j)
		{
			if(arr_L[j] >= L_bottom && arr_L[j] <= L_top) arr_d[j] = arr_map[i][j];
		}
		arr_d[i] = 0;
		arr_m[i] = true;

		
		//for(k = 0; k < n; ++k) cout << arr_d[k] << " ";
		//cout << endl;

		for(j = 1; j < n; ++j)
		{
			int min_d = intMax;
			int idx_d;
			for(k = 0; k < n; ++k)
			{
				if(!arr_m[k] && arr_L[k] >= L_bottom && arr_L[k] <= L_top && min_d > arr_d[k])
				{
					min_d = arr_d[k];
					idx_d = k;
				}
			}
			if(min_d == intMax) break;
			arr_m[idx_d] = true;
			for(k = 0; k < n; ++k)
			{
				if(!arr_m[k] && arr_map[idx_d][k] != intMax && arr_L[k] >= L_bottom && arr_L[k] <= L_top && min_d + arr_map[idx_d][k] < arr_d[k])
				{
					arr_d[k] = min_d + arr_map[idx_d][k];
				}
			}

			//for(k = 0; k < n; ++k) cout << arr_d[k] << " ";
			//cout << endl;
		}

		if(arr_d[0] != intMax && min_p > arr_d[0] + arr_p[i]) min_p = arr_d[0] + arr_p[i];

	}

	}//LL

	cout << min_p << endl;

	delete [] arr_p;
	delete [] arr_L;

	for(j = 0; j < n; ++j) delete [] arr_map[j];
	delete [] arr_map;

	return 0;
}
#include <iostream>
#include <cmath>
#include <limits>
#include <cstdio>

using namespace std;

const double doubleMax = numeric_limits<double>::max();

struct Point
{
	int x;
	int y;
};

int main()
{
	//freopen("D://input.txt", "r", stdin);

	int i, j;

	int n;
	cin >> n;
	int count = 1;

	int x,y;
	while(n)
	{
		//clog << n << endl;
		double res = 0;

		double **arr_map = new double*[n];
		for(i = 0; i < n; ++i)
		{
			arr_map[i] = new double[n];
			for(j = 0; j < n; ++j) arr_map[i][j] = doubleMax;
		}

		Point *arr_p = new Point[n];

		for(i = 0; i < n; ++i)
		{
			cin >> x >> y;
			//clog << x << " " << y << endl;

			arr_p[i].x = x;
			arr_p[i].y = y;

			for(j = 0; j < i; ++j)
			{
				arr_map[i][j] = (arr_p[j].x - x) * (arr_p[j].x - x) + (arr_p[j].y - y) * (arr_p[j].y - y);
				arr_map[j][i] = (arr_p[j].x - x) * (arr_p[j].x - x) + (arr_p[j].y - y) * (arr_p[j].y - y);
			}
		}

		//for(i = 0; i < n; ++i)
		//{
		//	for(j = 0; j < n; ++j)
		//	{
		//		clog << arr_map[i][j] << " ";
		//	}
		//	clog << endl;
		//}
		//clog << endl;

		//init
		double min_map = doubleMax;
		int idx_map;
		for(i = 0; i < n; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				if(i != j && min_map > arr_map[i][j])
				{
					min_map = arr_map[i][j];
					idx_map = i;
				}
			}
		}

		int *arr_idx = new int[n];
		double *arr_cost = new double [n];

		for(i = 0; i < n; ++i)
		{
			arr_cost[i] = arr_map[idx_map][i];
			arr_idx[i] = idx_map;
		}
		arr_cost[idx_map] = 0;

		//for(i = 0; i < n; ++i) clog << arr_cost[i] << " " << arr_idx[i] << endl;
		//clog << endl;


		for(i = 1; i < n; ++i)
		{
			double min_cost = doubleMax;
			int idx_cost;
			for(j = 0; j < n; ++j)
			{
				if(arr_cost[j] != 0 && min_cost > arr_cost[j])
				{
					min_cost = arr_cost[j];
					idx_cost = j;
				}
			}

			if(res < arr_cost[idx_cost]) res = arr_cost[idx_cost];
			arr_cost[idx_cost] = 0;

			for(j = 0; j < n; ++j)
			{
				if(arr_cost[j] > arr_map[idx_cost][j])
				{
					arr_cost[j] = arr_map[idx_cost][j];
				}
			}

			if(idx_cost == 1)
			{
				if(0 != arr_cost[0]) res = arr_map[0][1] * arr_map[0][1];
				break;
			}
		}

		//cout << res << endl;

		//cout << "Scenario #" << count << endl;
		//cout.setf(ios::fixed);
		//cout.precision(3);
		//cout << "Frog Distance = " << res << endl;
		//cout << endl;
		printf("Scenario #%d\n", count);
		printf("Frog Distance = %.3f\n\n", sqrt(res)); 



		delete [] arr_cost;
		delete [] arr_idx;


		delete [] arr_p;

		for(i = 0; i < n; ++i) delete [] arr_map[i];
		delete [] arr_map;

		cin >> n;
		count++;
	}
	return 0;
}
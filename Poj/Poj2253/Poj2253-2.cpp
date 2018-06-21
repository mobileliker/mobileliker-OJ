#include <iostream>
#include <cmath>
#include <limits>
#include <cstring>
#include <iomanip>

using namespace std;

const double doubleMax = numeric_limits<double>::max();

struct STONES // (0 <= xi,yi <= 1000)
{
	int x;
	int y;
};

double distance(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
	int n; //2<=n<=200
	int i, j;
	cin >> n;
	int t = 1;

	while(n != 0)
	{
		STONES *stones = new STONES[n];

		double **arr_dis = new double*[n];
		for(i = 0; i < n; ++i)
		{
			arr_dis[i] = new double[n];
			for(j = 0; j < n; ++j) arr_dis[i][j] = doubleMax;
		}

		for(i = 0; i < n; ++i)
		{
			int x,y;
			cin >> x >> y;
			stones[i].x = x;
			stones[i].y = y;
		}

		for(i = 0; i < n; ++i)
		{
			for(j = 0; j < i; ++j)
			{
				arr_dis[i][j] = distance(stones[i].x, stones[i].y, stones[j].x, stones[j].y);
				arr_dis[j][i] = arr_dis[i][j];
			}
			arr_dis[i][i] = 0;
		}

		double *min_dis = new double[n];
		for(int i = 0; i < n; ++i) min_dis[i] = arr_dis[0][i];

		int *visited = new int[n];
		memset(visited, 0, sizeof(int) * n);
		visited[0] = 1;

		for(i = 1; i < n; ++i)
		{
			double min = doubleMax;
			int min_idx;
			for(j = 0; j < n; ++j)
			{
				if(visited[j] == 0 && min > min_dis[j])
				{
					min = min_dis[j];
					min_idx = j;
				}
			}
			visited[min_idx] = 1;

			for(j = 0; j < n; ++j)
			{
				if(arr_dis[min_idx][j] != doubleMax)
				{
					//if(min_dis[min_idx] < min_dis[j] && arr_dis[min_idx][j] < min_dis[j])
					if(min_dis[min_idx] < min_dis[j] && arr_dis[min_idx][j] < min_dis[j])
					{
						if(min_dis[min_idx] > arr_dis[min_idx][j]) min_dis[j] = min_dis[min_idx];
						else min_dis[j] = arr_dis[min_idx][j];
					}
				}
			}
		}

		//for(i = 0; i < n; ++i) cout << min_dis[i] << " ";
		//cout << endl;

		cout << "Scenario #" << t << endl;
		cout << fixed << setprecision(3) << "Frog Distance = " << min_dis[1] << endl;
		cout << endl;

		delete [] visited;
		delete [] min_dis;

		
		for(i = 0; i < n; ++i) delete [] arr_dis[i];
		delete [] arr_dis;

		delete [] stones;
		cin >> n;
		t++;
	}
	return 0;
}
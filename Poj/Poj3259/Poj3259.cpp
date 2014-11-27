#include <iostream>
#include <cstring>

using namespace std;

//const int Max_d = 0;

struct Road
{
	int s;
	int e;
	int t;
};

int main()
{
	//freopen("D://input.txt","r",stdin);

	int i,j;

	int ff;
	cin >> ff;

	int n,m,w;
	while(ff--)
	{
		cin >> n >> m >> w;

		Road *arr_road = new Road[m * 2 + w];

		int s,e,t;
		for(i = 0; i < m; ++i)
		{
			cin >> s >> e >> t;
			
			arr_road[i * 2].s = s;
			arr_road[i * 2].e = e;
			arr_road[i * 2].t = t;

			arr_road[i * 2 + 1].s = e;
			arr_road[i * 2 + 1].e = s;
			arr_road[i * 2 + 1].t = t;
		}
		for(i = 0; i < w; ++i)
		{
			cin >> s >> e >> t;

			arr_road[m * 2 + i].s = s;
			arr_road[m * 2 + i].e = e;
			arr_road[m * 2 + i].t = -t;
		}

		//for(i = 0; i < m * 2 + w; ++i)
		//{
		//	cout << i << " " << arr_road[i].s << " " << arr_road[i].e << " " << arr_road[i].t << endl;
		//}
		//cout << endl;

		int *arr_d = new int[n];
		//for(i = 0; i < n; ++i) arr_d[i] = Max_d;
		memset(arr_d,0,sizeof(int) * n);

		//Bellman-Ford
		bool flag;
		for(i = 0; i < n - 1; ++i)
		{
			flag = false;
			for(j = 0; j < 2 * m + w; ++j)
			{
				if(arr_d[arr_road[j].e] > arr_d[arr_road[j].s] + arr_road[j].t)
				{
					arr_d[arr_road[j].e] = arr_d[arr_road[j].s] + arr_road[j].t;
					flag = true;
				}
			}
			if(!flag) break;
		}

		for(j = 0; j < 2 * m + w; ++j)
		{
			if(arr_d[arr_road[j].e] > arr_d[arr_road[j].s] + arr_road[j].t) break;
		}

		if(j < 2 * m + w) cout << "YES" << endl;
		else cout << "NO" << endl;

		delete [] arr_d;
		delete [] arr_road;
	}

	return 0;
}
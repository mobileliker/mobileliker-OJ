#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
double n,m;
double dist[40][40];

int floyd()
{
	for(int k = 0; k < n; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(dist[i][j] < dist[i][k] * dist[k][j])
				{
					dist[i][j] = dist[i][k] * dist[k][j];
				}
			}
		}
	}
}

int init()
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			dist[i][j] = 0;
		}
		dist[i][i] = 1;
	}
}

int main()
{
	int t = 1; //1<=n<=30
	int i, j, k;
	map<string, int> map_name;
	cin >> n;
	while(n != 0)
	{
		init();
		string name;
		for(i = 0; i < n; ++i)
		{
			cin >> name;
			map_name[name] = i;
		}
		
		cin >> m;
		
		
		string name1, name2;
		double rate;
		for(i = 0; i < m; ++i)
		{
			
			cin >> name1 >> rate >> name2;
			dist[map_name[name1]][map_name[name2]] = rate;
		}
		
		
//		for(int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < n; ++j)
//			{
//				cout << dist[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
		
		floyd();
		
//		for(int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < n; ++j)
//			{
//				cout << dist[i][j] << " ";
//			}
//			cout << endl;
//		}
		
		cout << "Case " << t << ": ";
		
		for(i = 0; i < n; ++i)
		{
			if(dist[i][i] > 1) break;
		}
		if(i >= n) cout << "No" << endl;
		else cout << "Yes" << endl;

		t++;
		cin >> n;
	}
	
	return 0;
}

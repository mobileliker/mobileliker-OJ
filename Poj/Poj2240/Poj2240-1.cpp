#include<cstdio>  
#include<cstring>  
#include<string>  
#include<algorithm>  
#include<iostream>  
#include<vector>  
#include<map>  
  
using namespace std;

struct Edge
{
	int st;
	int ed;
	double w;
};

vector<Edge> edges; 
int n; //顶点数 
int m; //边数 

map<string, int> map_name;

double dist[40][40];

int bellman_ford()
{
	for(int k = 0; k < n; ++k)  //对第k个顶点 
	{
		for(int i = 0; i < n; ++i) dist[k][i] = 0;
		dist[k][k] = 1;
		
		for(int i = 0; i < n; ++i) //n-1次松弛 
		{
			int flag = 0;
			for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); ++it)
			{
				Edge edge2 = (Edge)*it;
				if(dist[k][edge2.st] * edge2.w > dist[k][edge2.ed]){
					flag = 1;
					dist[k][edge2.ed] = dist[k][edge2.st] * edge2.w;
					if(edge2.ed == k && dist[k][k] > 1) return 0;
				}
			} 
//			for(int j = 0; j < n; ++j) cout << dist[k][j] << " ";
//			cout << endl;
			if(flag == 0) break;
		}
	}
}

int main()
{
	//freopen("D://input.txt","r",stdin);
	
	int t = 1; 
	
	cin >> n;
	while(n != 0)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				dist[i][j] = 0;
			}
			dist[i][i] = 1;
		}
		edges.clear();
		string name;
		for(int i = 0; i < n; ++i)
		{
			cin >> name;
			map_name[name] = i;
		}
		
		cin >> m;
		string name1, name2;
		double rate;
		for(int i = 0; i < m; ++i)
		{
			cin >> name1 >> rate >> name2;
			Edge edge;
			edge.st = map_name[name1];
			edge.ed = map_name[name2];
			edge.w = rate;
			edges.push_back(edge);
		} 
		
//		for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); ++it)
//		{
//			Edge edge2 = *it;
//			cout << edge2.st << " " << edge2.ed << " " << edge2.w << endl;
//		}

		bellman_ford();
		
		int i;
		for(i = 0; i < n; ++i)
		{
			if(dist[i][i] > 1) break;
		}
		cout << "Case " << t << ": ";
		if(i >= n) cout << "No" << endl;
		else cout << "Yes" << endl; 
		
		t++;
		cin >> n;
	}
	return 0;
}

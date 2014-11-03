#include <iostream>
#include <cstring>

using namespace std;

//N,E,S,W
const int idx_x[] = {0,1,0,-1};
const int idx_y[] = {-1,0,1,0};
const char idx_ch[] = {'N','E','S','W'};
const int num_d = 4;

int main()
{
	//freopen("D://input.txt","r",stdin);

	int y,x;
	int i;

	int w,h,s;
	cin >> h >> w >> s;

	while(h != 0 || w != 0 || s != 0)
	{
		int **arr_d = new int*[h];
		for(y = 0; y < h; ++y) arr_d[y] = new int[w];

		char ch;
		for(y = 0; y < h; ++y)
		{
			for(x = 0; x < w; ++x)
			{
				cin >> ch;
				for(i = 0; i < num_d; ++i) if(idx_ch[i] == ch) break;
				arr_d[y][x] = i;
			}
		}

		//for(y = 0; y < h; ++y)
		//{
		//	for(x = 0; x < w; ++x)
		//	{
		//		cout << arr_d[y][x] << " ";
		//	}
		//	cout << endl;
		//}

		int **arr_mark = new int*[h];
		for(y = 0; y < h; ++y)
		{
			arr_mark[y] = new int[w];
			memset(arr_mark[y],0,sizeof(int) * w);
		}

		y = 0;
		x = s - 1;
		int path = 0;
		int nx,ny;
		while(!arr_mark[y][x])//loop
		{
			nx = x;
			ny = y;
			arr_mark[y][x] = ++path;

			x = nx + idx_x[arr_d[ny][nx]];
			y = ny + idx_y[arr_d[ny][nx]];

			if(y < 0 || y >= h || x < 0 || x >= w) break;//exit
		}

		if(y < 0 || y >= h || x < 0 || x >=w)
		{
			cout << path << " step(s) to exit" << endl;
		}
		else
		{
			cout << (arr_mark[y][x] - 1) << " step(s) before a loop of " << (arr_mark[ny][nx] - arr_mark[y][x] + 1) << " step(s)" << endl;
		}

		//for(y = 0; y < h; ++y)
		//{
		//	for(x = 0; x < w; ++x) cout << arr_mark[y][x] << " ";
		//	cout << endl;
		//}

		for(y = 0; y < h; ++y) delete [] arr_mark[y];
		delete [] arr_mark;

		for(y = 0; y < h; ++y) delete [] arr_d[y];
		delete [] arr_d;

		cin >> h >> w >> s;
	}

	//fclose(stdin);

	return 0;
}
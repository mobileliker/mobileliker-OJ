#include <iostream>
#include <cstring>

using namespace std;

struct Point
{
	int x;
	int y;
	int d;//direction
};

const int idx_x[] = {0,1,0,-1};
const int idx_y[] = {1,0,-1,0};
const char arr_d[] = {'N','E','S','W'};
const int num_d = 4;

int main()
{
	//freopen("D://input.txt","r",stdin);

	int i,j;

	int k;
	cin >> k;
	
	int flag;

	while(k--)
	{
		flag = 1;

		int w,h; //a,b use w,h clearly
		cin >> w >> h;

		int m,n;
		cin >> n >> m;

		Point *arr_point = new Point[n];

		int **arr_mark = new int*[h];
		for(i = 0; i < h; ++i)
		{
			arr_mark[i] = new int[w];
			memset(arr_mark[i], 0, sizeof(int) * w);
		}

		char ch;
		for(i = 0; i < n; ++i)
		{
			cin >> arr_point[i].x >> arr_point[i].y;
			cin.get();
			cin >> ch;

			arr_mark[arr_point[i].y - 1][arr_point[i].x - 1] = i + 1;

			for(j = 0; j < num_d; ++j) if(arr_d[j] == ch) break;
			arr_point[i].d = j;
		}

		//for(i = 0; i < n; ++i)
		//{
		//	cout << "Point " << i << ":" << endl;
		//	cout << arr_point[i].x << endl;
		//	cout << arr_point[i].y << endl;
		//	cout << arr_point[i].d << endl;
		//}
		
		//for(int y = 0; y < h; ++y)
		//{
		//	for(int x = 0; x < w; ++x) cout << arr_mark[y][x] << " ";
		//	cout << endl;
		//}

		for(i = 0; i < m; ++i)
		{
			int robot,repeat;
			char action;

			cin >> robot;
			cin.get();
			cin >> action >> repeat;

			//cout << robot << " " << action << " " << repeat << endl;	

			if(flag)
			{
				switch(action)
				{
				case 'L':
					arr_point[robot - 1].d = (arr_point[robot - 1].d - repeat + num_d * repeat) % num_d;
					break;
				case 'R':
					arr_point[robot - 1].d = (arr_point[robot - 1].d + repeat) % num_d;
					break;
				case 'F':
					for(j = 0; j < repeat; ++j)
					{
						arr_mark[arr_point[robot - 1].y - 1][arr_point[robot - 1].x - 1] = 0;
						arr_point[robot - 1].y += idx_y[arr_point[robot - 1].d];
						arr_point[robot - 1].x += idx_x[arr_point[robot - 1].d];

						if((arr_point[robot - 1].y - 1) < 0 || (arr_point[robot - 1].y - 1) >= h
							|| (arr_point[robot - 1].x - 1) < 0 || (arr_point[robot - 1].x - 1) >= w)
						{
							cout << "Robot " << robot << " crashes into the wall" << endl;
							flag = 0;
							break;
						}
						else if(arr_mark[arr_point[robot - 1].y - 1][arr_point[robot - 1].x - 1])
						{
							cout << "Robot " << robot << " crashes into robot " << arr_mark[arr_point[robot - 1].y - 1][arr_point[robot - 1].x - 1] << endl;
							flag = 0;
							break;
						}
					}
					if(j >= repeat)
					{
						arr_mark[arr_point[robot - 1].y - 1][arr_point[robot - 1].x - 1] = robot;
					}
					break;
				}
			}

		}

		if(flag)
		{
			cout << "OK" << endl;
		}

		for(i = 0; i < h; ++i) delete [] arr_mark[i];
		delete [] arr_mark;

		delete [] arr_point;
	}

	//fclose(stdin);

	return 0;
}
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct POINT
{
	int x;
	int y;
	int direction;
	int turn_count;

	friend bool operator<(POINT p1,POINT p2)
	{
		return p1.turn_count > p2.turn_count;
	}

};

int idx_x[] = {-1,0,0,1};
int idx_y[] = {0,-1,1,0};

int main()
{
	freopen("C://input.txt","r",stdin);

	int i,j;

	int w,h;
	cin >> w >> h;

	int n = 1;
	while(w != 0 || h != 0)
	{
		cout << "Board #" << n++ << ":" << endl;

		cin.get();
		bool **arr = new bool*[h + 2];
		bool **arr_save = new bool*[h + 2];
		for(i = 0; i <= h + 1; ++i)
		{
			arr[i] = new bool[w + 2];
			arr_save[i] = new bool[w + 2];
			memset(arr_save[i],0,sizeof(bool) * (w + 2));
		}

		char ch;
		for(i = 1; i <= h; ++i)
		{
			for(j = 1; j <= w; ++j)
			{
				ch = cin.get();
				if(ch == 'X') arr_save[i][j] = true;
			}
			cin.get();
		}

		/*for(i = 1; i <= h; ++i)
		{
			for(j = 1; j <= w; ++j)
			{
				cout << arr_save[i][j] << " ";
			}
			cout << endl;
		}*/

		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int m = 1;
		while(x1 != 0 || y1 != 0 || x2 != 0 || y2 != 0)
		{
			cout << "Pair " << m++ << ": ";

			priority_queue<POINT> pq_point;

			for(i = 0; i <= h + 1; ++i) memcpy(arr[i],arr_save[i],sizeof(bool) * (w + 2));

	
			for(i = 0; i < 4; ++i)
			{
				POINT point;
				point.x = x1;
				point.y = y1;
				point.direction = i;
				point.turn_count = 0;

				pq_point.push(point);
			}
			//arr[y1][x1] = true;
			arr[y2][x2] = false;

			int flag = -1;
			while(!pq_point.empty())
			{

				POINT point = pq_point.top();
				pq_point.pop();
				arr[y1][x1] = true;

				//cout << "(" << point.x << "," << point.y << "," << point.direction << "," << point.turn_count << ")"<< endl;

				if(point.x == x2 && point.y == y2) {flag = point.turn_count; break;}

				for(i = 0; i < 4; ++i)
				{
					int temp_x = point.x + idx_x[i];
					int temp_y = point.y + idx_y[i];

					if(temp_x < 0 || temp_x > w + 1 || temp_y < 0 || temp_y > h + 1) continue;
					if(arr[temp_y][temp_x]) continue;

					POINT p2;
					p2.x = temp_x;
					p2.y = temp_y;
					p2.direction = i;
					if(i == point.direction) p2.turn_count = point.turn_count;
					else p2.turn_count = point.turn_count + 1;
					pq_point.push(p2);
					//arr[temp_y][temp_x] = true;
				}
			}

			if(flag == -1) cout << "impossible." << endl;
			else cout << flag << " segments." << endl;

			cin >> x1 >> y1 >> x2 >> y2;
		}

		for(i = 0; i <= h + 1; ++i)
		{
			delete [] arr[i];
			delete [] arr_save[i];
		}
		delete [] arr;
		delete [] arr_save;

		cin >> w >> h;
	}

	return 0;
}
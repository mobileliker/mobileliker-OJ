#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct PATH
{
	int x;
	int y;
	int height;
};

int cmp(const void* a,const void *b)
{
	PATH *p1 = (PATH *) a;
	PATH *p2 = (PATH *) b;
	return p2->height - p1->height;
}

int main()
{
	//freopen("C://input.txt","r",stdin);

	int r,c;
	cin >> r >> c;

	int i,j;

	int **arr_height = new int*[r];
	for(i = 0; i < r; ++i) arr_height[i] = new int[c];

	int **arr_mark = new int*[r];
	for(i = 0; i < r; ++i)
	{
		arr_mark[i] = new int[c];
		memset(arr_mark[i],0,sizeof(int) * c);
	}

	PATH *arr_path = new PATH[r * c];

	for(i = 0; i < r; ++i)
	{
		for(j = 0; j < c; ++j)
		{
			cin >> arr_height[i][j];
			arr_path[i * c + j].x = j;
			arr_path[i * c + j].y = i;
			arr_path[i * c + j].height = arr_height[i][j];
		}
	}

	qsort(arr_path,r * c,sizeof(PATH),cmp);

	int idx_x[] = {-1,1,0,0};
	int idx_y[] = {0,0,1,-1};

	int res = 0;
	for(i = 0; i < r * c; ++i)
	{
		//cout << arr_path[i].height << " " << arr_path[i].x << " " << arr_path[i].y << endl;

		int max = 0;
		for(j = 0; j < 4; ++j)
		{
			int temp_x = arr_path[i].x + idx_x[j];
			int temp_y = arr_path[i].y + idx_y[j];

			if(temp_x < 0 || temp_x >= c || temp_y < 0 || temp_y >= r) continue;

			if(arr_height[temp_y][temp_x] > arr_height[arr_path[i].y][arr_path[i].x] && max < arr_mark[temp_y][temp_x])
			{
				max = arr_mark[temp_y][temp_x];
			}
		}

		arr_mark[arr_path[i].y][arr_path[i].x] = max + 1;
		if(res < max + 1) res = max + 1;
	}

	cout << res << endl;

	delete [] arr_path;

	for(i = 0; i < r; ++i) delete [] arr_height[i];
	delete [] arr_height;

	for(i = 0; i < r; ++i) delete [] arr_mark[i];
	delete [] arr_mark;

	return 0;
}
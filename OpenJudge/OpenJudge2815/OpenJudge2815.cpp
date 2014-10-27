#include <iostream>
#include <cstdio>

using namespace std;

int idx_x[] = {-1,0,1,0};
int idx_y[] = {0,-1,0,1};

int m,n;

int f(int **arr,int i,int j)
{
	//cout << "f(" << i << "," << j << ")" << endl;
	
	/*for(int y = 0; y < m; ++y)
	{
		for(int x = 0; x < n; ++x)
		{
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}*/

	if(i < 0 || i >= m || j < 0 || j >= n || arr[i][j] == -1) return 0;
	int value = arr[i][j];

	int res = 1;
	int k;
	arr[i][j] = -1;
	for(k = 0; k < 4; ++k)
	{
		if(value % 2 == 0) res += f(arr,i + idx_y[k],j + idx_x[k]);
		value /= 2;
	}
	return res;
}

int main()
{
	//freopen("C://input.txt","r",stdin);

	int i,j;

	//int m,n;
	cin >> m >> n;

	int **arr = new int*[m];
	for(i = 0; i < m; ++i) arr[i] = new int[n];

	for(i = 0; i < m; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}


	int count = 0;
	int max = 0;
	int num;
	for(i = 0; i < m; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			if(arr[i][j] != -1)
			{
				num = f(arr,i,j);
				//cout << "num=" << num << endl;
				if(max < num) max = num;
				++count;
			}
		}
	}
	cout << count << endl;
	cout << max << endl;

	for(i = 0; i < m; ++i) delete [] arr[i];
	delete [] arr;

	return 0;
}
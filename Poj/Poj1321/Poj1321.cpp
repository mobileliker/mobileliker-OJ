#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int **arr;
int n;
int res;

void dfs(int m,int k)
{
	int i,j;

	if(k == 0) { res++; return; }

	if(m < n)
	{
		if(n - m < k) return;//剪枝一，剩余的行数少于需要摆放的棋盘，则不符合要求

		dfs(m + 1,k);

		for(i = 0; i < n; ++i)
		{
			if(arr[m][i] == 0)
			{
				for(j = m + 1; j < n; ++j) if(arr[j][i] != -1) ++arr[j][i];
				dfs(m + 1,k - 1);
				for(j = m + 1; j < n; ++j) if(arr[j][i] != -1) --arr[j][i];

			}
		}
	}
}


int main()
{
	//freopen("C://input.txt","r",stdin);

	int i,j;

	int k; // n <= 8 , k <= n
	cin >> n >> k;

	while(n != -1 || k != -1)
	{
		arr = new int*[n];
		for(i = 0; i < n; ++i) {arr[i] = new int[n];memset(arr[i],0,sizeof(int) * n);}
		
		char ch;
		for(i = 0;i < n; ++i)
		{
			for(j = 0;j < n; ++j)
			{
				cin >> ch;
				if(ch == '.') arr[i][j] = -1;
			}
		}

		/*for(i = 0;i < n; ++i)
		{
			for(j = 0;j < n; ++j)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}*/
		
		res = 0;

		dfs(0,k);

		cout << res << endl;

		for(i = 0; i < n; ++i) delete [] arr[i];
		delete [] arr;

		cin >> n >> k;
	}


	return 0;
}
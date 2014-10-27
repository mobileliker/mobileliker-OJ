#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n,k;
		cin>>m>>n>>k;
		int *arr = new int[m*n];
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin>>arr[i * n + j];
			}
		}
		int sum = 0,ni=0,nj;
		int max,maxi,maxj;
		k -= 2;
		int flag = 1;
		do
		{
			max = -1;
			for(int i = 0; i < m; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(max < arr[i * n + j])
					{
						max = arr[i * n + j];
						maxi = i;
						maxj = j;
					}
				}
			}
			if(flag) {nj = maxj;flag = 0;}
			int step = abs(maxi - ni) + abs(maxj - nj) + 1;
			if(step + maxi > k) break;
			else
			{
				k -= step;
				sum += max;
				ni = maxi;
				nj = maxj;
				arr[maxi * n + maxj] = 0;
			}

		}while(1);
		cout<<sum<<endl;
		delete [] arr;
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	//freopen("C://input.txt","r",stdin);

	int i;
	
	int n,k;
	cin >> n >> k;

	int sum; //sum of stick length

	int *arr_len = new int[n];
	memset(arr_len , 0, sizeof(int) * n);

	sum = 0;
	for(i = 0; i < n; ++i)
	{
		cin >> arr_len[i];
		sum += arr_len[i];
	}

	int max_len = sum / k;
	int min_len = 1;
	int mid_len;

	int count_k;
	int max = 0;

	while(min_len <= max_len)
	{
		mid_len = (max_len + min_len) / 2;

		count_k = 0;
		for(i = 0; i < n; ++i)
		{
			count_k += (arr_len[i] / mid_len);
		}

		if(count_k >= k)
		{
			if(max < mid_len) max = mid_len;
			min_len = mid_len + 1;
		}
		else
		{
			max_len = mid_len - 1;
		}
	}

	cout << max << endl;

	delete [] arr_len;

	return 0;
}
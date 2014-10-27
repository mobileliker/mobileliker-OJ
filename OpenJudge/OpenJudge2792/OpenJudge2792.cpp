#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	//freopen("C://input.txt","r",stdin);

	int temp,i;

	int n;
	cin >> n;

	while(n--)
	{
		int s,a,b;

		cin >> s;

		int *arr_a = new int[s];
		int *arr_b = new int[s];

		memset(arr_a,0,sizeof(int) * s);
		memset(arr_b,0,sizeof(int) * s);

		cin >> a;
		while(a--)
		{
			cin >> temp;
			if(temp <= s) ++(arr_a[temp - 1]);
		}

		cin >> b;
		while(b--)
		{
			cin >> temp;
			if(temp <= s) ++(arr_b[temp - 1]);
		}

		int count = 0;
		for(i = 0; i < s; ++i)
		{
			count += arr_a[i] * arr_b[s - i - 2];
		}

		cout << count << endl;

		delete [] arr_a;
		delete [] arr_b;
	}

	return 0;
}
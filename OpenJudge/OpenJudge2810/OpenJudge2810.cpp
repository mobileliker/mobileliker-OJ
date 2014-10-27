#include <iostream>
#include <cstdio>

#define START_N 2

using namespace std;

int main()
{
	int n;
	cin>>n;

	int *arr_cube = new int[n];

	int i,j,k,p;
	for(i = START_N; i <= n; ++i)
	{
		arr_cube[i - START_N] = i * i * i;
		for(j = START_N; j <= i; ++j)
		{
			for(k = j; k <= i; ++k)
			{
				for(p = k; p <= i; ++p)
				{
					if(arr_cube[i - START_N] == arr_cube[j - START_N]
						+ arr_cube[k - START_N] + arr_cube[p - START_N])
					{
						cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<p<<")"<<endl;
					}
				}
			}
		}

	}


	delete [] arr_cube;
	return 0;
}
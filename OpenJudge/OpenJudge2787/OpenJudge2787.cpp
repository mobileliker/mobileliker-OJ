#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;


double a[4];
bool used[4];
bool f(int k)
{
	int i,j;
	if(k == 1)
	{
		for(i = 0; i < 4; ++i)
		{
			if(!used[i])
			{
				if(fabs(a[i] - 24) < 0.0001) return true;
				else return false;
			}
		}
		return false;
	}
	else
	{
		for(i = 0; i < 4; ++i)
		{
			if(!used[i])
			{
				for(j = i + 1; j < 4; ++j)
				{
					if(!used[j])
					{
						double v1 = a[i];
						double v2 = a[j];
						used[j] = true;

						a[i] = v1 + v2;
						if(f(k - 1)) return true;

						a[i] = v1 * v2;
						if(f(k - 1)) return true;

						a[i] = v1 - v2;
						if(f(k - 1)) return true;

						a[i] = v2 - v1;
						if(f(k - 1)) return true;

						a[i] = v1 / v2;
						if(f(k - 1)) return true;

						a[i] = v2 / v1;
						if(f(k - 1)) return true;

						a[i] = v1;
						used[j] = false;
					}
				}
			}

		}
	}
	return false;
}

int main()
{
	//freopen("C://input.txt","r",stdin);


	cin >> a[0] >> a[1] >> a[2] >> a[3];
	while(a[0] != 0 || a[1] != 0 || a[2] != 0 || a[3] != 0)
	{
		memset(used,0,sizeof(bool) * 4);

		if(f(4)) cout << "YES" << endl;
		else cout << "NO" << endl;

		cin >> a[0] >> a[1] >> a[2] >> a[3];
	}

	return 0;
}
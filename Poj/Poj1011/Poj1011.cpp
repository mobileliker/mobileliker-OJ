#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int cmp(const void *a,const void *b)
{
	int ia = *((int *)a);
	int ib = *((int *)b);

	return ib - ia;
}

int k;
int L;

bool f(int *sticks,int left_L,int left_n)
{

	int i;
	int flag = true;

	//cout<< "f(" << "," << left_L << "," << left_n << ")" <<endl;
	//for(i = 0; i < k; ++i) cout << sticks[i] << " ";
	//cout << endl;

	for(i = 0; i < k; ++i)
	{

		if(sticks[i] != 0)
		{
			flag = false;
			int temp;
			if(sticks[i] == left_L)
			{
				temp = sticks[i];
				sticks[i] = 0;
				if(f(sticks,L,left_n - 1)) return true;
				sticks[i] = temp;
			}
			else if(sticks[i] < left_L)
			{
				temp = sticks[i];
				sticks[i] = 0;
				if(f(sticks,left_L - temp,left_n)) return true;
				sticks[i] = temp;
			}
			else continue;

			if(left_L == L || sticks[i] == left_L) break;//Less 1
		}
	}

	if(flag && left_n == 0) return true;
	else return false;
}


int main()
{
	//freopen("C://input.txt","r",stdin);

	int i;

	while(cin>>k)
	{
		if(k == 0) break;

		int *sticks = new int[k];
		memset(sticks,0,sizeof(k));

		for(i = 0; i < k; ++i) cin >> sticks[i];

		qsort(sticks,k,sizeof(int),cmp);

		int sum = 0;
		for(i = 0; i < k; ++i) sum += sticks[i];

		int n;
		for(L = sticks[0]; L <= sum; ++L)
		{
			if(sum % L != 0) continue;

			n = sum / L;
			if(f(sticks,L,n))
			{
				cout << L << endl;
				break;
			}
		}
	}
	return 0;
}
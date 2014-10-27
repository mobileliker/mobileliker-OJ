#include <iostream>
#include <cstdio>
#include <cstring>

#define ESIZE 4 

using namespace std;

int main()
{
	//freopen("D://input.txt","r",stdin);
	
	int i,j,k;
	
	int res[ESIZE][ESIZE];
	memset(res,0,sizeof(int) * ESIZE * ESIZE);
	
	char ch;
	for(i = 0; i < ESIZE; ++i)
	{
		for(j = 0; j < ESIZE; ++j)
		{
			cin >> ch;
			if(ch == '+')
			{
				for(k = 0; k < ESIZE; ++k)
				{
					res[i][k] = 1 - res[i][k];
					res[k][j] = 1 - res[k][j];
				}
				res[i][j] = 1 - res[i][j];
			}		 
		}
	}
	
	int count = 0;
	for(i = 0; i < ESIZE; ++i)
	{
		for(j = 0; j < ESIZE; ++j)
		{
			count += res[i][j];
		}
	}
	cout << count << endl;
	
	for(i = 0; i < ESIZE; ++i)
	{
		for(j = 0; j < ESIZE; ++j)
		{
			if(res[i][j]) cout << (i + 1) << " " << (j + 1) << endl;
		}
	} 
	
	
	return 0;
} 

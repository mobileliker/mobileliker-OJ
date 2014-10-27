#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

#define MAX_NUM 1000000

using namespace std;

int main()
{
	//freopen("D://input.txt","r",stdin);
	
	int i,j;
	
	bool * arr_prime = new bool[MAX_NUM + 1];
	
	for(i = 3; i <= MAX_NUM; i += 2) arr_prime[i] = true;
	for(i = 4; i <= MAX_NUM; i += 2) arr_prime[i] = false;
	arr_prime[2] = true;
	
	int sqrt_mn = sqrt(MAX_NUM);
	for(i = 3; i <= sqrt_mn; i += 2)
	{
		if(arr_prime[i])
		{
			for(j = i + i; j <= MAX_NUM; j += i) arr_prime[j] = false;
		}
	}
	
	int a;
	cin >> a;
	
	while(a != 0)
	{
		
		if(a % 2 == 0 && arr_prime[a - 2])
		{
			cout << a << " = " << "2" << " + " << (a - 2) << endl; 
		}
		else
		{
			for(i = 3; i <= a / 2; i += 2)
			{
				if(arr_prime[i]  && arr_prime[a - i])
				{
					cout << a << " = " << i << " + " << (a - i) << endl;
					break; 
				}
			}
		}
		 
		cin >> a;
	}
		
	return 0;
} 

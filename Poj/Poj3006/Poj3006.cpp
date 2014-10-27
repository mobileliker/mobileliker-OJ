#include<iostream>
#include<cstdio>
#include<cmath>

#define MAX_NUM 1000000

using namespace std;

int main()
{
	//freopen("D://input.txt","r",stdin);
	
	int i,j;
	
	bool arr_prime[MAX_NUM + 1];
	
	for(i = 3; i <= MAX_NUM; i += 2) arr_prime[i] = true;
	for(i = 4; i <= MAX_NUM; i += 2) arr_prime[i] = false;
	arr_prime[2] = true;
	
	arr_prime[1] = false; //!!
	
	int sqrt_mn = sqrt(MAX_NUM);
	for(i = 3; i <= sqrt_mn; i += 2)
	{
		if(arr_prime[i])
		{
			for(j = i + i; j <= MAX_NUM; j += i) arr_prime[j] = false;
		}
	}
	
	int a,d,n;
	cin >> a >> d >> n;
	
	while(a != 0 || d != 0 || n != 0)
	{
		while(n)
		{
			if(arr_prime[a]) --n;
			a += d;
		}
		cout << a - d << endl;
		
		cin >> a >> d >> n;
	} 
	
	return 0;
} 

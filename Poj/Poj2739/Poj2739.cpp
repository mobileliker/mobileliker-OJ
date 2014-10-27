#include <iostream>
#include <cstdio>
#include <cstring> 
#include <cmath>
#include <vector> 

#define MAX_NUM 10000

using namespace std;

int main()
{
	//freopen("D://input.txt", "r", stdin);
	
	int i,j;
	
	//prime
	bool * arr_prime = new bool[MAX_NUM + 1];
	
	for(i = 3; i <= MAX_NUM; i += 2) arr_prime[i] = true;
	for(i = 4; i <= MAX_NUM; i += 2) arr_prime[i] = false;
	arr_prime[2] = true;
	
	int sqrt_mn = sqrt(MAX_NUM);
	
	for(i = 3; i < sqrt_mn; i += 2)
	{
		if(arr_prime[i])
		{
			for(j = i + i; j <= MAX_NUM; j += i) arr_prime[j] = false;
		}
	}
	
	int *arr_res = new int[MAX_NUM + 1];
	memset(arr_res, 0, sizeof(int) * (MAX_NUM + 1));
	
	vector<int> v_sum;
	for(i = 2; i <= MAX_NUM; ++i)
	{
		if(arr_prime[i])
		{
			v_sum.push_back(i);
			vector<int>::size_type v_i;
			for(v_i = 0; v_i != v_sum.size() - 1; ++v_i)
			{
				v_sum[v_i] += i;
			}
			
			for(v_i = 0; v_i != v_sum.size(); ++v_i)
			{
				if(v_sum[v_i] <= MAX_NUM)
				{
					++(arr_res[v_sum[v_i]]);
					//cout << v_sum[v_i] << endl;
				}
			}			
		}
	}
	
	int a;
	cin >> a;
	while(a != 0)
	{
		cout << arr_res[a] << endl;
		
		cin >> a;
	}
	
	
	delete [] arr_res;
	
	delete [] arr_prime;
	 
	return 0;
}
 

#include <iostream>
#include <cstdio>

#define MAX 1000000
#define MODE_NUM 32767

using namespace std;


int arr_pell[MAX];

int main()
{
	//freopen("C://input.txt","r",stdin);

	int i;

	arr_pell[0] = 1;
	arr_pell[1] = 2;
	for(i = 2; i < MAX; ++i) arr_pell[i] = (2 * arr_pell[i - 1] + arr_pell[i - 2]) % MODE_NUM;

	int n;
	cin >> n;

	int k;
	while(n--)
	{
		cin >> k;
		cout << arr_pell[k - 1] << endl;
	}

	return 0;
}
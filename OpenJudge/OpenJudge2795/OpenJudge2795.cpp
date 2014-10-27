#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

struct METAL
{
	double price;
	int total;
	int weight;
};

int cmp(const void* a,const void *b)
{
	METAL metal_a = *((METAL *)a);
	METAL metal_b = *((METAL *)b);

	if(metal_b.price > metal_a.price) return 1;
	else if(metal_b.price == metal_b.price) return 0;
	else return -1;
}

int main()
{
	//freopen("C://input.txt","r",stdin);

	int i;

	int k;
	cin >> k;

	while(k--)
	{
		int w;
		int s;
		cin >> w >> s;

		METAL *arr_metal = new METAL[s];


		for(i = 0; i < s; ++i)
		{
			cin >> arr_metal[i].weight >> arr_metal[i].total;
			arr_metal[i].price = arr_metal[i].total * 1.0 / arr_metal[i].weight;
		}

		qsort(arr_metal,s,sizeof(METAL),cmp);

		//for(i = 0; i < s; ++i) cout << arr_metal[i].price << " " << arr_metal[i].weight << endl;

		double sum = 0.0;
		for(i = 0; i < s; ++i)
		{
			if(w > arr_metal[i].weight) {sum += arr_metal[i].total;w -= arr_metal[i].weight;}
			else {sum += w * arr_metal[i].price; break;}
		}
		
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << sum << endl;

		delete [] arr_metal;
	}

	return 0;
}
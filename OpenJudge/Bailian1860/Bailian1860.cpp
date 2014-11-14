#include <iostream>
#include <cstring>

using namespace std;

struct Exchange
{
	int a;
	int b;
	double r;
	double c;
};

int main()
{
	//freopen("D://input.txt","r",stdin);

	int i,j;

	int n,m,s;
	double v;

	//while(cin >> n >> m >> s >> v)
	//{
	cin >> n >> m >> s >> v;

		Exchange *arr_ec = new Exchange[m * 2];

		int a,b;
		double rab,cab,rba,cba;
		for(i = 0; i < m; ++i)
		{
			cin >> a >> b >> rab >> cab >> rba >> cba;
			
			arr_ec[i * 2].a = a - 1;
			arr_ec[i * 2].b = b - 1;
			arr_ec[i * 2].r = rab;
			arr_ec[i * 2].c = cab;

			arr_ec[i * 2 + 1].a = b - 1;
			arr_ec[i * 2 + 1].b = a - 1;
			arr_ec[i * 2 + 1].r = rba;
			arr_ec[i * 2 + 1].c = cba;
		}

		//for(i = 0; i < m * 2; ++i) cout << arr_ec[i].a << " " << arr_ec[i].b << " " << arr_ec[i].r << " " << arr_ec[i].c << endl;

		double *d = new double[n];
		memset(d, 0, sizeof(double) * n);
		d[s - 1] = v;

		//for(i = 0; i < n; ++i) cout << d[i] << " ";

		//Bellman-Ford
		int flag;
		for(i = 1; i <= n - 1; ++i)
		{
			flag = 0;
			for(j = 0; j < 2 * m; ++j)
			{
				if(d[arr_ec[j].b] < (d[arr_ec[j].a] - arr_ec[j].c) * arr_ec[j].r)
				{
					d[arr_ec[j].b] = (d[arr_ec[j].a] - arr_ec[j].c) * arr_ec[j].r;
					flag = 1;
				}
			}
			if(!flag) break;

			//for(j = 0; j < n; ++j) cout << d[j] << " ";
			//cout << endl;
		}

		for(i = 0; i < 2 * m; ++i)
		{
			if(d[arr_ec[i].b] < (d[arr_ec[i].a] - arr_ec[i].c) * arr_ec[i].r) break;
		}

		if(i < 2 * m) cout << "YES" << endl;
		else cout << "NO" << endl;

		delete [] d;
		delete [] arr_ec;

	//}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	while(n!=0)
	{
		vector<int> v;
		for(vector<int>::size_type i = 0; i != n; ++i)
		{
			v.push_back(i+1);
		}
		int k = 0;
		while((v.size()-1) != 0 )
		{
			k = (k + m - 1) % v.size();
			v.erase(v.begin() + k);

		}
		cout<<v[0]<<endl;
		cin>>n>>m;
	}
	return 0;
}
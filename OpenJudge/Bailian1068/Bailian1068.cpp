#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	//freopen("D://input.txt","r",stdin);

	int i,j;

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		int *arr_p = new int[n];

		for(i = 0; i < n; ++i) cin >> arr_p[i];

		//for(i = 0; i < n; ++i) cout << arr_p[i] << endl;


		vector<char> v_sym;

		int pre_p = 0;
		for(i = 0; i < n; ++i)
		{
			for(j = pre_p; j < arr_p[i]; ++j) v_sym.push_back('(');
			v_sym.push_back(')');
			pre_p = arr_p[i];
		}

		vector<char>::size_type sym_i;

		//for(sym_i = 0; sym_i != v_sym.size(); ++sym_i) cout << v_sym[sym_i];
		//cout << endl;

		stack<int> s_sym;// -1 (, -2 )
		for(sym_i = 0; sym_i != v_sym.size(); ++sym_i)
		{
			if('(' == v_sym[sym_i]) s_sym.push(-1);
			else
			{
				int count = 1;
				while(s_sym.top() != -1)
				{
					count += s_sym.top();
					s_sym.pop();
				}
				s_sym.pop();
				cout << count << " ";
				s_sym.push(count);
			}
		}
		cout << endl;



		delete [] arr_p;


	}

	return 0;
}
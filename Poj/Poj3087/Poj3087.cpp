#include <iostream>
#include <string>
#include <set>
#include <cstring>

using namespace std;

int main()
{
	//freopen("D://input.txt","r",stdin);

	int i;

	int n;
	cin >> n;

	for(int n_i = 1; n_i <= n; ++n_i)
	{
		int c;
		cin >> c;

		char *arr_s1 = new char[c];
		char *arr_s2 = new char[c];
		char *arr_s12 = new char[c * 2 + 1];
		arr_s12[c * 2] = '\0';

		for(i = 0; i < c; ++i) cin >> arr_s1[i];
		for(i = 0; i < c; ++i) cin >> arr_s2[i];

		//for(i = 0; i < c; ++i) cout << arr_s1[i] << " ";
		//cout << endl;
		//for(i = 0; i < c; ++i) cout << arr_s2[i] << " ";
		//cout << endl;


		string dst;
		cin >> dst;

		//cout << str << endl;

		set<string> s_str;

		int count = 0;
		while(true)
		{
			for(i = 0;i < c; ++i)
			{
				arr_s12[i * 2] = arr_s2[i];
				arr_s12[i * 2 + 1] = arr_s1[i];
			}
			string str = arr_s12;
			count++;

			if(str == dst) break;
			else if(s_str.find(str) != s_str.end())
			{
				count = -1;
				break;
			}
			else
			{
				s_str.insert(str);
				strncpy(arr_s1,arr_s12,c);
				strncpy(arr_s2,&arr_s12[c],c);
			}
		}

		cout << n_i << " " << count << endl;

		delete [] arr_s12;
		delete [] arr_s2;
		delete [] arr_s1;
	}

	return 0;
}
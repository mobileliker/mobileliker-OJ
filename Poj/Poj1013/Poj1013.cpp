#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string str_left[3];
	string str_right[3];
	string str_res[3];

	int n;
	cin>>n;

	int i,j,k;
	
	while(n--)
	{
		for(i = 0; i < 3; ++i) cin>>str_left[i]>>str_right[i]>>str_res[i];
		for(i = 0; i < 12; ++i)
		{
			for(j = 0; j < 2; ++j)
			{
				for(k = 0; k < 3; ++k)
				{
					char ch = 'A' + i;
					string::size_type idx_left = str_left[k].find(ch);
					string::size_type idx_right = str_right[k].find(ch);

					if(idx_left != string::npos)
					{
						if(j == 0) //heavy
						{
							if(str_res[k] != "up") break;
						}
						else
						{
							if(str_res[k] != "down") break;
						}
					}
					else if(idx_right != string::npos)
					{
						if(j == 0)
						{
							if(str_res[k] != "down") break;
						}
						else
						{
							if(str_res[k] != "up") break;
						}
					}
					else
					{
						if(str_res[k] != "even") break;
					}

				}
				if(k >= 3) break; 
			}
			if(j < 2) break;
		}
		if(j == 0) cout<<(char)('A' + i)<<" is the counterfeit coin and it is heavy."<<endl;
		else cout<<(char)('A' + i)<<" is the counterfeit coin and it is light."<<endl;
	}
	return 0;
}

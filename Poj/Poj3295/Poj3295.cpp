#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	//freopen("D://input.txt","r",stdin);

	string str;
	cin >> str;

	while(str.size() != 1 || str[0] != '0')
	{
		//cout << str << endl;

		int p,q,r,s,t;
		for(p = 0; p < 2; ++p)
		{
			for(q = 0; q < 2; ++q)
			{
				for(r = 0; r < 2; ++r)
				{
					for(s = 0; s < 2; ++s)
					{
						for(t = 0; t < 2; ++t)
						{
							stack<int> s_str;
							int w,x;
							for(string::reverse_iterator r_iter = str.rbegin(); r_iter != str.rend(); ++r_iter)
							//for(int str_i = str.size() - 1; str_i >= 0; --str_i)
							{
								if(*r_iter == 'p') s_str.push(p);
								else if(*r_iter == 'q') s_str.push(q);
								else if(*r_iter == 'r') s_str.push(r);
								else if(*r_iter == 's') s_str.push(s);
								else if(*r_iter == 't') s_str.push(t);
								else
								{
									w = s_str.top();
									s_str.pop();
									if(*r_iter == 'N') s_str.push(!w);
									else
									{
										x = s_str.top();
										s_str.pop();
										if(*r_iter == 'K') s_str.push(w&&x);
										else if(*r_iter == 'A') s_str.push(w||x);
										else if(*r_iter == 'C') {if(w == 1 && x == 0) s_str.push(0); else s_str.push(1);}
										else {if(w == x) s_str.push(1); else s_str.push(0);}
									}
								}
							}
							if(s_str.top() != 1) goto end;
						}
					}
				}
			}
		}

end:
		if(p >= 2) cout << "tautology" << endl;
		else cout << "not" << endl;

		cin >> str;
	}
	return 0;
}
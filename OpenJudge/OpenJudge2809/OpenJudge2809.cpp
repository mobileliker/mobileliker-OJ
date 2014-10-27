#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string mul(string str1,string str2)
{
    vector<int> v_res(str1.size()+str2.size(),0);
    string::size_type i,j;
    vector<int>::size_type k,p;

    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    for(i = 0; i != str1.size(); ++i)
    {
        for(j = 0; j != str2.size(); ++j)
        {
            v_res[i+j] += (str1[i]-'0') * (str2[j] - '0');
        }
    }
    for(k = 0; k != v_res.size() - 1; ++k)
    {
        v_res[k+1] += v_res[k] / 10;
        v_res[k] = v_res[k] % 10;
    }

    for(p = v_res.size() - 1; p != -1; --p)
    {
        if(v_res[p] != 0) break;
    }
    if(p == -1) p = 0;

    string s_res(p+1,'0');
    for(k = p; k != -1; --k) s_res[p-k] = char(v_res[k] + '0');
    

    return s_res;

}

int main()
{
	int n;
	cin>>n;
	string res = "1";

	while(n--)
	{
		res = mul(res,"2");
	}

	cout<<res<<endl;

	return 0;
}
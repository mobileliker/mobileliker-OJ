#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

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

string real_mul(string str1,string str2)
{
	string::size_type idx_str1_point = str1.find(".");
	if(idx_str1_point == string::npos)
	{
		str1 += ".0";
		idx_str1_point = str1.find(".");
	}
	str1.erase(idx_str1_point,1);

	string::size_type idx_str2_point = str2.find(".");
	if(idx_str2_point == string::npos)
	{
		str2 += ".0";
		idx_str2_point = str2.find(".");
	}
	str2.erase(idx_str2_point,1);

	string::size_type dec_res_len = (str1.size() - idx_str1_point) + (str2.size() - idx_str2_point);

	string res = mul(str1,str2);

	if(res.size() < dec_res_len + 1)
	{
		res = string(dec_res_len + 1 - res.size(),'0') + res;
	}

	res.insert(res.size() - dec_res_len,".");

	string::size_type idx_res_tail = res.find_last_not_of("0");
	res = res.substr(0,idx_res_tail+1);

	if(res[res.size() - 1] == '.') res.erase(res.size()-1);

	return res;
}

int main()
{
	string r;
	int n;
	while(cin>>r>>n)
	{
		string res = "1";
		while(n--)
		{
			res = real_mul(res,r);
		}
		string::size_type idx_res_pre = res.find_first_not_of("0");
		if(idx_res_pre != string::npos) res.erase(0,idx_res_pre);


		cout<<res<<endl;
	}


	return 0;
}
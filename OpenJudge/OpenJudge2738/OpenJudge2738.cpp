#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string sum(string s1,string s2)
{
    if(s1.length()<s2.length())
    {
        string temp=s1;
        s1=s2;
        s2=temp;
    }
    int i,j;
    for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--)
    {
        s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //×¢ÒâÏ¸½Ú
        if(s1[i]-'0'>=10)
        {
            s1[i]=char((s1[i]-'0')%10+'0');
            if(i) s1[i-1]++;
            else s1='1'+s1;
        }
    }
    return s1;
}

string real_sum(string s1,string s2)
{
	string::size_type idx_s1_point = s1.find(".");
	s1.erase(idx_s1_point,1);

	string::size_type idx_s2_point = s2.find(".");
	s2.erase(idx_s2_point,1);

	string::size_type int_res_len = idx_s1_point>idx_s2_point?idx_s1_point:idx_s2_point;

	string::size_type dec_s1_len = s1.size() - idx_s1_point;
	string::size_type dec_s2_len = s2.size() - idx_s2_point;

	string::size_type dec_res_len;
	if(dec_s1_len < dec_s2_len)
	{
		s1 += string(dec_s2_len - dec_s1_len, '0');
		dec_res_len = dec_s2_len;
	}
	else
	{
		s2 += string(dec_s1_len - dec_s2_len, '0');
		dec_res_len = dec_s1_len;
	}

	string res = sum(s1,s2);

	if(res.size() > int_res_len + dec_res_len)
	{
		++int_res_len;
	}

	string::size_type idx_res_tail = res.find_last_not_of("0");

	res = res.substr(0,idx_res_tail + 1);
	res.insert(int_res_len,".");

	return res;
}

int main()
{
	
	int n;
	cin>>n;

	string s1,s2;
	while(n--)
	{
		cin>>s1>>s2;
		cout<<real_sum(s1,s2)<<endl;
	}


	return 0;
}
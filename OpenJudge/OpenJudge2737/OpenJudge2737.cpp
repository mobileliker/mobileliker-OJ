#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string sub(string s1,string s2)
{
	int flag = 0;
    if(s1.length()<s2.length() || (s1.length()==s2.length() && s1 < s2))
    {
		flag = 1;
        string temp=s1;
        s1=s2;
        s2=temp;
    }


    int i,j;
    for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--)
    {
        s1[i]=char(s1[i]-(j>=0?s2[j]-'0':0));   //注意细节
        if(s1[i]-'0'<0)
        {
            s1[i]=char(s1[i] + 10);
            s1[i-1]--;
        }
    }

	for(i = 0; i < s1.length(); i++)
	{
		if(s1[i] != '0') break;
	}
	if(i == s1.length()) i = s1.length()-1;
	s1 = s1.substr(i);

	if(flag) s1 = "-" + s1;

    return s1;
}
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
        s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //注意细节
        if(s1[i]-'0'>=10)
        {
            s1[i]=char((s1[i]-'0')%10+'0');
            if(i) s1[i-1]++;
            else s1='1'+s1;
        }
    }
    return s1;
}

string div(string s1,string s2)
{
	string res = "0";
    if(s1.length()<s2.length() || (s1.length()==s2.length() && s1 < s2))
    {
		return "0";
    }

	int i;
	int sub_length = s1.length() - s2.length();
	for(i = sub_length; i >= 0; i--)
	{
		string s3(i,'0');
		string s4 = s2 + s3;
		
		do
		{
			string temp = sub(s1,s4);
			if(temp[0] == '-') break;
			else
			{
				s1 = temp;
				res = sum(res,("1" + s3));
			}
		}while(1);
	}
	return res;
}

int main()
{
	int n;
	cin>>n;
	string str1,str2;
	while(n--)
	{
		cin>>str1>>str2;
		cout<<div(str1,str2)<<endl;
	}
	return 0;
}
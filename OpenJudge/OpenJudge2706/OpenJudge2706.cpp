#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
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


int main()
{
	int n;
	scanf("%d",&n);

	printf("%d\n",(int)(n*log10(2)+1));

	int i,j;
	string str = "1";
	for(i = 1; i <= n; i++)
	{
		str = sum(str,str);
		if(str.length() > 500) str = str.substr(str.length() - 500);
	}
	str[str.size()-1] = char(str[str.size()-1] -1);
	if(str.length() < 500)
	{
		string temp(500-str.length(),'0');
		str = temp + str;
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 50; j++)
			{
				cout<<str[i*50+j];
			}
			cout<<endl;
		}
	}
	return 0;
}
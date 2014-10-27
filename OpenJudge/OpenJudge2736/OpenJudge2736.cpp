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
        s1[i]=char(s1[i]-(j>=0?s2[j]-'0':0));   //×¢ÒâÏ¸½Ú
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
	cin>>n;
	string str1,str2;
	while(n--)
	{
		cin>>str1>>str2;
		cout<<sub(str1,str2)<<endl;
	}
	return 0;
}
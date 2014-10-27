#include <iostream>
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

int main()
{
	string str;
	string::size_type i,j,size_str;
	while(cin>>str)
	{
		string str1(str);
		size_str= str.size();
		while(--size_str)
		{
			str1 = sum(str1,str);
			if(str1.size() != str.size()) break;
			for(i = 0; i < str.size(); i++)
			{
				for(j = 0; j < str1.size(); j++)
				{
					if(str1[j] != str[(i + j) % str.size()]) break;
				}
				if(j >= str1.size()) break;
			}
			if(i >= str.size()) break;
		}
		if(size_str) cout<<str<<" is not cyclic"<<endl;
		else cout<<str<<" is cyclic"<<endl;
	}
	return 0;
}
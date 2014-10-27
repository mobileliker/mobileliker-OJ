#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
using namespace std;


int main()
{
	string str0 = "1110111";
	string str1 = "0100100";
	string str2 = "1011101";
	string str3 = "1101101";
	string str4 = "0101110";
	string str5 = "1101011";
	string str6 = "1111011";
	string str7 = "0100101";
	string str8 = "1111111";
	string str9 = "1101111";

	string str = str9 + str8 + str7 + str6 + str5 + str4 + str3 + str2 + str1 + str0;

	bitset<70> bs(str);

	int s,n;
	cin>>s>>n;
	int flag;
	string::iterator iter;
	int i;
	while(s!=0 || n != 0)
	{
		ostringstream s1;
		s1<<n;
		string str_n = s1.str();

		flag = 0;
		for(iter = str_n.begin(); iter != str_n.end(); ++iter)
		{
			if(flag) cout<<" ";
			else flag = 1;
			int num = (*iter) - '0';
			cout<<" ";
			for(int i = 0; i < s; i++)
			{
				if(bs[num * 7]) cout<<"-";
				else cout<<" ";
			}
			cout<<" ";
		}
		cout<<endl;

		
		for(i = 0; i < s; i++)
		{
			flag = 0;
			for(iter = str_n.begin(); iter != str_n.end(); ++iter)
			{
				if(flag) cout<<" ";
				else flag = 1;
				int num = (*iter) - '0';
				if(bs[num * 7 + 1]) cout<<"|";
				else cout<<" ";
				for(int j = 0; j < s; j++) cout<<" ";
				if(bs[num * 7 + 2]) cout<<"|";
				else cout<<" ";
			}
			cout<<endl;
		}

		flag = 0;
		for(iter = str_n.begin(); iter != str_n.end(); ++iter)
		{
			if(flag) cout<<" ";
			else flag = 1;
			int num = (*iter) - '0';
			//step1
			cout<<" ";
			for(i = 0; i < s; i++)
			{
				if(bs[num * 7 + 3]) cout<<"-";
				else cout<<" ";
			}
			cout<<" ";
		}
		cout<<endl;

		for(i = 0; i < s; i++)
		{
			flag = 0;
			for(iter = str_n.begin(); iter != str_n.end(); ++iter)
			{
				if(flag) cout<<" ";
				else flag = 1;
				int num = (*iter) - '0';
				if(bs[num * 7 + 4]) cout<<"|";
				else cout<<" ";
				for(int j = 0; j < s; j++) cout<<" ";
				if(bs[num * 7 + 5]) cout<<"|";
				else cout<<" ";
			}
			cout<<endl;
		}

		flag = 0;
		for(string::iterator iter = str_n.begin(); iter != str_n.end(); ++iter)
		{
			if(flag) cout<<" ";
			else flag = 1;
			int num = (*iter) - '0';
			//step1
			cout<<" ";
			for(i = 0; i < s; i++)
			{
				if(bs[num * 7 + 6]) cout<<"-";
				else cout<<" ";
			}
			cout<<" ";
		}
		cout<<endl;/**/
		cout<<endl;
		cin>>s>>n;
	}
	return 0;
}
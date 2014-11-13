#include <iostream>
#include <string>

using namespace std;

const int Num = 100;

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
	//freopen("D://input.txt","r",stdin);

	int i;

	string str0,str1,str2,str3;

	while(cin >> str0 >> str1 >> str2)
	{
		//cout << str0 << endl;
		//cout << str1 << endl;
		//cout << str2 << endl;

		i = Num - 3;
		while(i--)
		{
			str3 = sum(str0,str1);
			str3 = sum(str3,str2);
			str0 = str1;
			str1 = str2;
			str2 = str3;
		}

		cout << str3 << endl;

	}

	return 0;
}
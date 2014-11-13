#include <string>
#include <cstdio>
#include <iostream>

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
	//freopen("D://input.txt","r",stdin);

	int i;

	int n;
	scanf("%d\n",&n);

	string str1(n,'\0');
	string str2(n,'\0');

	for(i = 0; i < n; ++i) scanf("%c %c\n",&str1[i],&str2[i]);

	//for(i = 0; i < n; ++i) printf("%c",str1[i]);
	//printf("\n");
	//for(i = 0; i < n; ++i) printf("%c",str2[i]);
	//printf("\n");

	string res = sum(str1,str2);

	if(res.size() < n)
	{
		i = n - res.size();
		while(i--) cout << "0";
	}
	cout << res << endl;

	return 0;
}
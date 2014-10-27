#include<iostream>
#include<cstring>
#include <cstdio>

using namespace std;
char c[26];
int main()
{
    int i;
	char a[81];
	int size;
    for(i=0;i<26;i++) cin>>c[i];
    getchar();
	gets(a);
	size=strlen(a);
	for(i=0;i<size;i++)
	{
	   if(a[i]==' ') cout<<a[i];
	   else if(a[i]>='A'&&a[i]<='Z') cout<<(char)(c[a[i]-'A']-'a'+'A');
	   else cout<<(c[a[i]-'a']);
	}    
    cout<<endl;
    //system("pause");
    return 0;
}
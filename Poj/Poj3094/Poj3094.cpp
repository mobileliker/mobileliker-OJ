#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	//freopen("D://input.txt","r",stdin);
	
	int i;
	
	char str[256];
	
	cin.getline(str,256);
	
	while(str[0] != '#')
	{
		int sum = 0;
		for(i = 0; i < strlen(str); ++i)
		{
			if(str[i] != ' ')
			{
				sum += (i + 1) * (str[i] - 'A' + 1); 
			} 
		}
		
		cout << sum << endl; 
		
		cin.getline(str,256);
	}
	
	return 0;
} 

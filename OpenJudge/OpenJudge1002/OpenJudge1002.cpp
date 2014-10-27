#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char maps[] = "22233344455566677778889999";
int hash_num[10000000];
//字符串简单处理+Hash 
int main()
{
	//freopen("F:\\input.txt","r",stdin);
	
	int i,j,n;
	cin>>n;
	
	char chs[200],chs1[7];
	int length;
	while(n--)
	{
		scanf("%s",chs);
		
		//处理
		length = strlen(chs);
		j = 0;
		for(i = 0; i < length; i++)
		{
			if(chs[i] == '-') continue;
			else if(chs[i] >= 'A' && chs[i] <= 'Z') chs1[j++] = maps[chs[i] - 'A'];
			else chs1[j++] = chs[i];
			if(j == 7) break;
		}
		
		//处理2
		int index_num = 0;
		for(i = 0; i < 7; i++) index_num = index_num * 10 + (chs1[i] - '0');
		
		hash_num[index_num]++; 
	} 
	
	int flag = 1;
	for(i = 0; i < 10000000; i++)
	{
		if(hash_num[i] > 1)
		{
			flag = 0;
			int k = i;
			for(j = 0; j < 7; j++)
			{
				chs1[6-j] = (k % 10) + '0';
				k = k / 10;
			}
			cout<<chs1[0]<<chs1[1]<<chs1[2]<<'-'<<chs1[3]<<chs1[4]<<chs1[5]<<chs1[6]<<' '<<hash_num[i]<<endl;
		}
	}
	
	if(flag) cout<<"No duplicates."<<endl;
	
	return 0;
}
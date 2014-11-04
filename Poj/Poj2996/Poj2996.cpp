#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Point_c
{
	char name;
	char p_ch;
	char p_num;
};

const char name_c[] = {'K','Q','R','R','B','B','N','N','P','P','P','P','P','P','P','P',
					   'k','q','r','r','b','b','n','n','p','p','p','p','p','p','p','p'};
const int num_c = 32;



int main()
{
	//freopen("D://input.txt","r",stdin);

	int i,j,k;
	char p_ch[num_c];
	char p_num[num_c];

	//cout << str << endl;
	memset(p_ch,0,sizeof(char) * num_c);
	memset(p_num,0,sizeof(char) * num_c);

	string *arr_str = new string[8];
	string str;
	for(i = 0; i < 8; ++i)
	{
		cin >> str;
		cin >> arr_str[i];
	}
	cin >> str;

	//for(i = 0; i < 8; ++i) cout << arr_str[i] << endl;

	
	for(i = 7; i >= 0; --i)
	{
		for(j = 0; j < 8; ++j)
		{
			for(k = 0; k < 16; ++k)
			{
				if(name_c[k] == arr_str[i][2 + 4 * j] && p_ch[k] == 0)
				{
					p_ch[k] = j + 'a';
					p_num[k] = (8 - i) + '0';
					break;
				}
			}
		}
	}

	for(i = 0; i < 8; ++i)
	{
		for(j = 0; j < 8; ++j)
		{
			for(k = 16; k < 32; ++k)
			{
				if(name_c[k] == arr_str[i][2 + 4 * j] && p_ch[k] == 0)
				{
					p_ch[k] = j + 'a';
					p_num[k] = (8 - i) + '0';
					break;
				}
			}
		}
	}

	int flag = 0;

	cout << "White: ";
	for(k = 0; k < 8; ++k) if(p_ch[k] != 0)
	{
		if(p_ch[k] != 0)
		{
			if(flag) cout << ",";
			else flag = 1;
			cout << name_c[k] << p_ch[k] << p_num[k];
		}
	}
	for(k = 8; k < 16; ++k)
	{		
		if(p_ch[k] != 0)
		{
			if(flag) cout << ",";
			else flag = 1;
			cout << p_ch[k] << p_num[k];
		}

	}
	cout << endl;

	flag = 0;
	cout << "Black: ";
	for(k = 16; k < 24; ++k) if(p_ch[k] != 0)
	{
		if(p_ch[k] != 0)
		{
			if(flag) cout << ",";
			else flag = 1;
			cout << (char)(name_c[k] + ('K' - 'k')) << p_ch[k] << p_num[k];
		}

	}
	for(k = 24; k < 32; ++k)
	{
		if(p_ch[k] != 0)
		{
			if(flag) cout << ",";
			else flag = 1;
			cout << p_ch[k] << p_num[k];
		}
	}
	cout << endl;

	delete [] arr_str;

	return 0;
}
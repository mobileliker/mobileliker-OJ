#include <iostream>
#include <string>

using namespace std;

int main()
{
	//freopen("D://input.txt","r",stdin);

	int i,j;

	//init output
	string str_out[8 + 9];
	str_out[0] = "+---+---+---+---+---+---+---+---+";
	for(i = 0; i < 8; ++i)
	{
		str_out[i * 2 + 1] = "|";
		for(j = 0; j < 8; ++j)
		{
			if((i + j) % 2 == 0) str_out[i * 2 + 1] += "...";
			else str_out[i * 2 + 1] += ":::";
			str_out[i * 2 + 1] += "|";
		}
		str_out[(i + 1) * 2] = "+---+---+---+---+---+---+---+---+";
	}


	string str;

	//white:
	cin >> str;
	cin >> str;

	str = "," + str;

	//cout << str << endl;
	int arr_ch[] = {'K','Q','R','B','N'};

	string::size_type str_i;
	for(str_i = 0; str_i != str.size(); ++str_i)
	{
		if(str[str_i] == ',')
		{
			for(i = 0; i < 5; ++i) if(str[str_i + 1] == arr_ch[i]) break;
			if(i < 5)
			{
				str_out[(8 - (str[str_i + 3] - '0')) * 2 + 1][2 + 4 * (str[str_i + 2] - 'a')] = arr_ch[i];
			}
			else
			{
				str_out[(8 - (str[str_i + 2] - '0')) * 2 + 1][2 + 4 * (str[str_i + 1] - 'a')] = 'P';
			}		
		}
	}

	//black:
	cin >> str;
	cin >> str;
	str = "," + str;

	//cout << str << endl;

	for(str_i = 0; str_i != str.size(); ++str_i)
	{
		if(str[str_i] == ',')
		{
			for(i = 0; i < 5; ++i) if(str[str_i + 1] == arr_ch[i]) break;
			if(i < 5)
			{
				str_out[(8 - (str[str_i + 3] - '0')) * 2 + 1][2 + 4 * (str[str_i + 2] - 'a')] = arr_ch[i] + ('a' - 'A');
			}
			else
			{
				str_out[(8 - (str[str_i + 2] - '0')) * 2 + 1][2 + 4 * (str[str_i + 1] - 'a')] = 'p';
			}		
		}
	}

	
	for(i = 0; i < 17; ++i) cout << str_out[i] << endl;

	//fclose(stdin);

	return 0;
}
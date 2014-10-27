#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ARR_ROW_SIZE 5
#define ARR_COL_SIZE 6

using namespace std;

int main()
{
	int n;
	cin>>n;

	bool arr_press[ARR_ROW_SIZE + 2][ARR_COL_SIZE + 2];
	bool arr_press_save[ARR_ROW_SIZE + 2][ARR_COL_SIZE + 2];
	bool arr_res[ARR_ROW_SIZE + 2][ARR_COL_SIZE + 2];

	int i,j,k;
	for(k = 1; k <= n; ++k)
	{
		memset(arr_press,0,sizeof(bool) * (ARR_ROW_SIZE + 2) * (ARR_COL_SIZE + 2));
		for(i = 1; i <= ARR_ROW_SIZE; ++i)
		{
			for(j = 1; j <= ARR_COL_SIZE; ++j)
			{
				cin>>arr_press[i][j];
			}
		}

		memcpy(arr_press_save,arr_press,sizeof(bool)* (ARR_ROW_SIZE + 2) * (ARR_COL_SIZE + 2));
		
		memset(arr_res[1],0,sizeof(bool) * (ARR_COL_SIZE + 2));
		while(1)
		{
			for(i = 1; i <= ARR_ROW_SIZE; ++i)
			{
				for(j = 1; j <= ARR_COL_SIZE; ++j)
				{
					arr_press[i - 1][j] ^= arr_res[i][j];
					arr_press[i][j - 1] ^= arr_res[i][j];
					arr_press[i][j + 1] ^= arr_res[i][j];
					arr_press[i + 1][j] ^= arr_res[i][j];
					arr_press[i][j] ^= arr_res[i][j];
				}
				memcpy(arr_res[i+1],arr_press[i],sizeof(bool) * (ARR_COL_SIZE + 2));
			}
			for(i = 1; i <= ARR_COL_SIZE; ++i) if(arr_press[ARR_ROW_SIZE][i]) break;
			if(i > ARR_COL_SIZE) break;
			else
			{
				memcpy(arr_press,arr_press_save,sizeof(bool) * (ARR_ROW_SIZE + 2) * (ARR_COL_SIZE + 2));
				for(i = ARR_COL_SIZE; i >= 0; --i)
				{
					if(!arr_res[1][i]) break;
				}
				while(i <= ARR_COL_SIZE) {arr_res[1][i] = !arr_res[1][i];i++;}
			}
		}
		cout<<"PUZZLE #"<<k<<endl;
		for(i = 1; i <= ARR_ROW_SIZE; ++i)
		{
			cout<<arr_res[i][1];
			for(j = 2; j <= ARR_COL_SIZE; ++j)
			{
				cout<<" "<<arr_res[i][j];
			}
			cout<<endl;
		}
	}

	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int m;
	cin>>m;
	int i,j,x;
	int temp;
	while(m--)
	{
		int n,k;
		cin>>n>>k;
		int *arr = new int[n];
		for(i = 0; i < n; i++) cin>>arr[i];
		while(k--)
		{
			for(i = n-1; i > 0; i--)
			{
				if(arr[i-1] < arr[i])
				{
					int idx = i;
					for(j = i+1;j < n;j++)
					{
						if(arr[j] > arr[i-1] && arr[j] < arr[idx])
						{
							idx = j;
						}
					}
					temp = arr[idx];
					arr[idx] = arr[i-1];
					arr[i-1] = temp;
					for(j = n-1; j >= i; j--)
					{
						for(x = i; x < j; x++)
						{
							if(arr[x] > arr[x+1])
							{
								temp = arr[x];
								arr[x] = arr[x+1];
								arr[x+1] = temp;
							}
						}
					}
					break;
				}
			}
			if(i == 0)
			{
				for(j = 0; j < n/2; j++)
				{
					temp = arr[j];
					arr[j] = arr[n-1-j];
					arr[n-1-j] = temp;
				}
			}

		}
		int flag = 0;
		for(i = 0; i < n; i++)
		{
			if(flag) cout<<" ";
			else flag = 1;
			cout<<arr[i];
		}
		cout<<endl;
		delete [] arr;
	}
	return 0;
}
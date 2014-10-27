#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	char ch;
	int sum,temp;
	while((ch=getchar()) != '0')
	{
		sum = 0;
		do
		{
			sum += (ch - '0');
		}while((ch=getchar()) != '\n');
		while(sum >= 10)
		{
			temp = 0;
			while(sum)
			{
				temp += (sum % 10);
				sum = sum / 10;
			}
			sum = temp;
		}
		printf("%d\n",sum);
	}
	return 0;
}
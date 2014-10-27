#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define LEN 125

void mul4(int *a,int *b)
{
	int c[LEN];
	int temp;
	memset(c,0,sizeof(int)*LEN);
	for(int i = 0; i < LEN; i++)
	{
		temp = 0;
		for(int j = 0; j < LEN; j++)
		{
			if(i + j >= LEN) break;
			c[i + j] += a[i] * b[j] + temp;
			temp = c[i + j] / 10000;
			c[i + j] = c[i + j] % 10000;
		}
	}
	memcpy(a,c,LEN * sizeof(int));
}

int main()
{
	int a[LEN],b[LEN];
	int i,j;
	memset(a,0,sizeof(int)*LEN);
	memset(b,0,sizeof(int)*LEN);
	b[0] = 2; a[0] = 1;
	int p;
	scanf("%d",&p);
	printf("%d\n",(int)(p * log10(2)) + 1);
	while(p)
	{
		if(p & 1)
		{
			mul4(a,b);
		}
		p >>= 1;
		mul4(b,b);
	}
	a[0]--;

	char out_str[LEN * 4 + 1];
	for(i = 0; i < LEN; i++)
	{
		sprintf(&out_str[i*4],"%04d",a[LEN-1-i]);
	}

	for(i = 0;i < 10; i++)
	{
		for(j = 0; j < 50; j++)
		{
			printf("%c",out_str[i*50+j]);
		}
		printf("\n");
	}
	return 0;
}
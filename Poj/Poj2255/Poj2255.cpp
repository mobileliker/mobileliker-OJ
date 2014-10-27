#include "stdio.h"
#include "string.h"
#define NUM 27
char ans[NUM];
int pos;
void func(char a[],char b[],int al,int bl,int len)
{
	int i;
	if(len==0) return;
	else if(len==1) ans[pos--]=a[al];
	else
	{
		ans[pos--]=a[al];
		for(i=bl;i<bl+len;i++) if(b[i]==a[al]) break;
		func(a,b,al+(i-bl)+1,i+1,bl+(len-1)-i);
		func(a,b,al+1,bl,i-bl);	
	}
}
int main()
{
	char a[NUM],b[NUM];
	int len;
	while(scanf("%s%s",a,b) != EOF)
	{
		len=strlen(a);
		pos=len-1;
		func(a,b,0,0,len);
		ans[len]='\0';
		printf("%s\n",ans);
	}
	return 0;
}

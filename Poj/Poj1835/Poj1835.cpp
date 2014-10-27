#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char arr_dir[][10] = {"forward","back","left","right","up","down"};
int main()
{
	int m;
	int n;
	int x,y,z,f,fr,h;
	char dir[10];
	int mov;
	int temp;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&n);
		x = 0; y = 0; z = 0; f = 0; fr = 1; h = 2;//f forword,h head,fr forward right
		while(n--)
		{
			scanf("%s%d",dir,&mov);
			if(!strcmp(dir,arr_dir[1]))//back
			{
				f = (f + 3) % 6;
				fr = (fr + 3) % 6;
			}
			else if(!strcmp(dir,arr_dir[2]))//left
			{
				temp = f;
				f = (fr + 3) % 6;
				fr = temp;
			}
			else if(!strcmp(dir,arr_dir[3]))//right
			{
				temp = f;
				f = fr;
				fr = (temp + 3) % 6;
			}
			else if(!strcmp(dir,arr_dir[4]))//up
			{
				temp = f;
				f = h;
				h = (temp + 3) % 6;
			}
			else if(!strcmp(dir,arr_dir[5]))//down
			{
				temp = f;
				f = (h + 3) % 6;
				h = temp;
			}
			if(f==0) x+=mov;
			else if(f == 1) y+=mov;
			else if(f == 2) z+=mov;
			else if(f == 3) x-=mov;
			else if(f == 4) y-=mov;
			else z-=mov;
		}
		printf("%d %d %d %d\n",x,y,z,f);
	}
	return 0;
}
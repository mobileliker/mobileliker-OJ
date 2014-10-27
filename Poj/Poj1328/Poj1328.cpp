#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

struct LINE
{
    double l;
    double r;
};

int cmp(const void *a,const void *b)
{
	LINE line1 = *((LINE *)a);
	LINE line2 = *((LINE *)b);
	/*if(line1.r == line2.r)
	{
		if(line1.l == line2.l) return 0;
		return line1.l > line2.l ? 1 : -1;	
	}	
	else return line1.r > line2.r ? 1 : -1;*/
	if(line1.r == line2.r) return 0;
	else return line1.r > line2.r ? 1 : -1;
}


int main()
{
	//freopen("D://input.txt", "r", stdin);

	int i;

	int n,d;
	int count = 1;
	int x,y;
	int flag;
	double ins;
	
	cin >> n >> d;
	while(n!= 0 || d != 0)
	{

		LINE *lines = new LINE[n];

		flag = 1;
		for(i = 0; i < n; ++i)
		{
			cin>>x>>y;
			if(d < y) flag = 0;
			else
			{
				ins = sqrt(d * d - y * y);
				lines[i].l = x - ins;
				lines[i].r = x + ins;
			}
		}

		if(flag == 0) cout<<"Case "<< (count++) <<": -1"<<endl;
		else
		{
			qsort(lines,n,sizeof(LINE),cmp);
			
			/*for(i = 0; i < n; ++i)
			{
				cout << lines[i].l << " " << lines[i].r << endl;
			}*/
			
			int num = 1;
			double max_r = lines[0].r;
			for(i = 1; i < n; ++i)
			{
				if(max_r < lines[i].l)
				{
					num++;
					max_r = lines[i].r;
				}
			}
			cout << "Case " << (count++) << ": " << num <<endl;
		}
				
		delete [] lines;
		
		cin >> n >> d; 
	}

	//fclose(stdin);
	return 0;
}

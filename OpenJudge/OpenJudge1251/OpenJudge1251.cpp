#include<stdio.h>
#include<iostream>
#define MAX 30
#define MAXLOW 9999999
using namespace std;
struct
{
	int lowcost;
}closedge[MAX];
int G[MAX][MAX];
/*int minimum(int size)
{
	//在g[][]已经init的前提下
	int i,min;
	for(i=0;i<size;i++)
	{
		if(closedge[i].lowcost>0)
		{
			min=i;
			break;
		}
	}
	for(i=i;i<size;i++)
	{
		if(closedge[i].lowcost>0&&closedge[i].lowcost<closedge[min].lowcost)
		{
			min=i;
		}
	}
	return min;
}*/
int minimum(int size)
{
	int i,min,min_num=MAXLOW;
	for(i=0;i<size;i++)
	{
		if(closedge[i].lowcost!=0 && closedge[i].lowcost<min_num)
		{
			min_num=closedge[i].lowcost;
			min=i;
		}
	}
	return min;
}
int MiniSpanTree_PRIM(int G[][MAX],int k,int size)
{
	
	int count=0;
	int i,j;
	//初始化辅助数组
	for(j=0;j<size;j++)
	{
		if(j!=k) closedge[j].lowcost=G[k][j];
	}
	closedge[k].lowcost=0;//初始，U={start}
	//测试辅助数组是否正确
	/*for(j=0;j<size;j++)
	{
		cout<<closedge[j].lowcost<<" ";
	}
	cout<<endl;*/
	for(i=1;i<size;i++)
	{
		k=minimum(size);
		count+=closedge[k].lowcost;
		closedge[k].lowcost=0;
		for(j=0;j<size;j++)
		{
			if(G[k][j]<closedge[j].lowcost)
			{
				closedge[j].lowcost=G[k][j];
			}
		}
		/*for(j=0;j<size;j++)
		{
			cout<<closedge[j].lowcost<<" ";
		}
		cout<<endl;*/
	}
	return count;
}
void InitGraph(int G[][MAX])
{
	int i,j;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			G[i][j]=MAXLOW;
		}
	}
}
int findStart(int G[][MAX],int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(G[i][j]!=MAXLOW) return i;
		}
	}
}
int main()
{
	int size;
	int m,n,num,cost;
	int i,j;
	char c1,c2;
	//size为村庄数
	while(scanf("%d",&size)!=EOF && size)
	{
		//m为第几个村庄
		InitGraph(G);
		/*for(m=0;m<size-1;m++)
		{
			//num为村庄的路的数量（不完全的）
			cin>>i>>num;
			for(n=0;n<num;n++)
			{
				cin>>j>>cost;
				G[i-'A'][j-'A']=G[j-'A'][i-'A']=cost;
			}
		}*/
		for(i=0;i<size-1;i++)
		{
			cin>>c1>>n;
			for(j=0;j<n;j++)
			{
				cin>>c2>>num;
				G[c1-'A'][c2-'A']=G[c2-'A'][c1-'A']=num;
			}
		}
		//make sure input
		/*for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				cout<<G[i][j]<<" ";
			}
			cout<<endl;
		}*/
		cout<<MiniSpanTree_PRIM(G,findStart(G,size),size)<<endl;
		//cout<<findStart(G,size)<<size<<endl;测试找边是否正确
	}

	return 1;
}
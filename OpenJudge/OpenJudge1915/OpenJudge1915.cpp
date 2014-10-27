#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;
typedef struct
{
	int row;
	int col;
	//int step;
}data;
int a[300][300];
int colStep[8]={1,2,-1,-2,1,2,-1,-2};
int rowStep[8]={2,1,-2,-1,-2,-1,2,1};
bool in(int row,int col,int size)
{
	if(row<0||row>=size) return false;
	if(col<0||col>=size) return false;
	return true;
}
void initArray(int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			a[i][j]=-1;
		}
	}
}
int f(int i,int j,int m,int n,int size)
{
	queue<data> q;
	int k;
	int newRow,newCol;
	data start,aData;
	start.row=i;
	start.col=j;
	initArray(size);
	//start.step=1;
	a[i][j]=0;
	q.push(start);
	while(!q.empty())
	{
		aData=q.front();
		if(aData.row==m&&aData.col==n)
		{
			return a[aData.row][aData.col];
		}
		else
		{
			for(k=0;k<8;k++)
			{
				newRow=aData.row+rowStep[k];
				newCol=aData.col+colStep[k];
				if(in(newRow,newCol,size))
				{
					if(a[newRow][newCol]==-1)
					{
						data newData;
						newData.col=newCol;
						newData.row=newRow;
						a[newRow][newCol]=a[aData.row][aData.col]+1;
						q.push(newData);
					}
				}
			}
		}
		q.pop();
	}
	return 0;
}
int main()
{
	int sum,k;
	int i,j,m,n,size;
	cin>>sum;
	for(k=0;k<sum;k++)
	{
		cin>>size>>i>>j>>m>>n;
		cout<<f(i,j,m,n,size)<<endl;
	}
	return 1;
}
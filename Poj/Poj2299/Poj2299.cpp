#include<iostream>
#include<stdio.h>
using namespace std;
int a[500002];

//递归2路归并排序 
/*void Merge(long long a[],long long b[],int s,int m,int t)
{
     int i=s,j=m+1,k=s;
     while((i<=m)&&(j<=t))
     {
         if(a[i]<=a[j]) b[k++]=a[i++];  
         else b[k++]=a[j++];
     }
     while(i<=m) b[k++]=a[i++];
     while(j<=t) b[k++]=a[j++];
}
void MSort(long long a[],long long b[],int s,int t ,int size)
{
     int m;
     long long c[size];
     if(s==t) b[s]=a[t];
     else
     {
         m=(s+t)/2;
         MSort(a,c,s,m,size);
         MSort(a,c,m+1,t,size);
         Merge(c,b,s,m,t);
     }
}
void MergeSort(long long a[],int size)
{
     MSort(a,a,0,size-1,size);
}*/


// 非递归合并排序
/*template<class T>
void Merge(T a[],T b[],int s,int m,int t)
{
 	 int i=s,j=m+1,k=s;
 	 while(i<=m&&j<=t)
 	 {
	     if(a[i]<a[j]) b[k++]=a[i++];
	     else b[k++]=a[j++];
	  }
	  while(i<=m) b[k++]=a[i++];
	  while(j<=t) b[k++]=a[j++]; 
}
template<class T>
void MergePass(T a[],T b[],int s,int t)
{
 	 int i;
 	 for(i=0;i+2*s<=t;i=i+2*s)
 	 {
        Merge(a,b,i,i+s-1,i+2*s-1);
     }
     //剩下的元素个数少于2s
     if(i+s<t) Merge(a,b,i,i+s-1,t);
     else for(int j=i;j<=t;j++) b[j]=a[j]; 
}
template<class T>
void MergeSort(T a[],int n)
{
     T *b=new T[n];
     //T b[n];
     int s=1;
     while(s<n)
     {
         MergePass(a,b,s,n);
         s+=s;
         MergePass(b,a,s,n);
         s+=s;
     }
}*/

long long count=0;
//求逆序对
void Merge(int a[],int b[],int s,int m,int t)
{
 	 int i=s,j=m+1,k=s;
	 //int count=0;
 	 while(i<=m&&j<=t)
 	 {
	     if(a[i]<=a[j]) b[k++]=a[i++];
	     else
		 {
			 b[k++]=a[j++];
	 		count+=m-i+1;
		 }
			 
	  }
	  while(i<=m) b[k++]=a[i++];
	  while(j<=t) b[k++]=a[j++];
	  //return count;
}
void MergePass(int a[],int b[],int s,int t)
{
 	 int i;
	 //int count=0;
 	 for(i=0;i+2*s<=t;i=i+2*s)
 	 {
        Merge(a,b,i,i+s-1,i+2*s-1);
     }
     //剩下的元素个数少于2s
     if(i+s<t) Merge(a,b,i,i+s-1,t-1);
     else for(int j=i;j<=t;j++) b[j]=a[j]; 
	 //return count;
}
void MergeSort(int a[],int n)
{
     int *b=new int[n];
	 //int b[n];
	 //int count=0;
     int s=1;
     while(s<n)
     {
         MergePass(a,b,s,n);
         s+=s;
         MergePass(b,a,s,n);
         s+=s;
     }
}



int main()
{
    
    //测试排序正确性 
    /*int a[10];
    for(i=0;i<10;i++) a[i]=10-i;
    for(i=0;i<10;i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<MergeSort(a,10)<<endl;
    for(i=0;i<10;i++) cout<<a[i]<<" ";*/

    int size;
    int i;
    while((cin>>size)&&size!=0)
    {
        count=0;
        for(i=0;i<size;i++)
        {
           scanf("%lld",&a[i]);
        }
        MergeSort(a,size);
        printf("%lld\n",count);
		//测试排序正确性
		//for(i=0;i<size;i++) printf("%lld ",a[i]);
    }
    //system("pause");
    return 1;
}

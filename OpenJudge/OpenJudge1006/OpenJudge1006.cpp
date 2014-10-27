#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int p,e,i,d;
	int j;
	int k = 0;
	while(cin>>p>>e>>i>>d)
	{
		if(p == -1 && e == -1 && i == -1 && d == -1) break;
		j = (d + 1 - p) / 23 * 23 + p;
		if(j < d + 1) j += 23;
		//for(j = d + 1; j < 21252; j++) if((j - p) % 23 == 0) break;
		for(;j < 21252;j += 23) if((j - e) % 28 == 0) break;
		for(;j < 21252;j += 23 * 28) if((j - i) % 33 == 0) break;
		cout<<"Case "<<(++k)<<": the next triple peak occurs in "<<(j - d)<<" days."<<endl;
	}
	return 0;
}
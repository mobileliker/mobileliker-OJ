#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

double f()
{
	string str;
	cin>>str;
	if(str == "+") return f() + f();
	else if(str == "-") return f() - f();
	else if(str == "*") return f() * f();
	else if(str == "/") return f() / f();
	else return atof(str.c_str());
}

int main()
{
	printf("%f\n",f());
	return 0;
}
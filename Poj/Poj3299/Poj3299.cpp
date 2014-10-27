#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

//humidex = temperature + h
//h = (0.5555)¡Á (e - 10.0)
//e = 6.11 ¡Á exp [5417.7530 ¡Á ((1/273.16) - (1/(dewpoint+273.16)))]

int main()
{
	//freopen("D://input.txt","r",stdin);
	
	int i;
	
	double humidex,dewpoint,temperature;
	char ch;
	int mark;
	
	while(1)
	{
		mark = 0;
		for(i = 0; i < 2; ++i)
		{
			cin >> ch;
			if(ch == 'E') 
			{
				return 0;
			}
			else if(ch == 'T')
			{
				cin >> temperature;
				mark += 1;
			}
			else if(ch == 'D')
			{
				cin >> dewpoint;
				mark += 2;
			}
			else
			{
				cin >> humidex;
				mark += 4;
			}
		} 
		
		double h,e; 
		if(mark == 3)
		{
			e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(dewpoint+273.16))));
			h = (0.5555) * (e - 10.0);
			humidex = temperature + h;
		}
		else if(mark == 5)
		{
			h = humidex - temperature;
			e = h / 0.5555 + 10.0;
			dewpoint = 1 / ((1 / 273.16) - log(e / 6.11) / 5417.7530) - 273.16;
		}
		else
		{
			e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(dewpoint+273.16))));
			h = (0.5555) * (e - 10.0);
			temperature = humidex - h;
		}
		
		//T number D number H number
		cout << fixed << setprecision(1); 
		cout << "T " << temperature << " D " << dewpoint << " H " << humidex << endl; 
	}
	
	return 0;
} 

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    char ch;

    while(1)
    {
        double temperature = 200, dewpoint = 200, humidex = 200;
        for(int i = 0; i < 2; i++)
        {
            cin >> ch;
            if(ch == 'E')
            {
                return 0;
            }
            else if(ch == 'T')
            {
                cin >> temperature;
            }
            else if(ch == 'D')
            {
                cin >> dewpoint;
            }
            else
            {
                cin >> humidex;
            }
        }

        if(temperature == 200)
        {
            double e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(dewpoint+273.16))));
            double h = (0.5555) * (e - 10.0);
            temperature = humidex - h;
        }
        else if(dewpoint == 200)
        {
            double h = humidex - temperature;
            double e = h / 0.5555 + 10.0;
            dewpoint = 1 / (1 / 273.16 - log(e / 6.11) / 5417.7530) - 273.16;
        }
        else
        {
            double e = 6.11 * exp (5417.7530 * ((1/273.16) - (1/(dewpoint+273.16))));
            double h = (0.5555) * (e - 10.0);
            humidex = temperature + h;
        }

        cout << fixed << setprecision(1);
        cout << "T " << temperature << " D " << dewpoint << " H " << humidex << endl;
    }

}

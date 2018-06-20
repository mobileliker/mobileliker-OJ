#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
    double sum = 0;
    for(int i = 0; i < 12; i++)
    {
        double m;
        cin >> m;
        sum += m;
    }
    cout << fixed << setprecision(2) << "$" << (sum / 12) << endl;

    return 0;
}

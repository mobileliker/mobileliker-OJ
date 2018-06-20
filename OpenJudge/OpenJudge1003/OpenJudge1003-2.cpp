#include <iostream>

using namespace std;

int main()
{
    double length;

    cin >> length;

    while(length != 0.00)
    {
        int n = 1;
        double sum = 0;

        while(sum <= length)
        {
            sum += 1.0 / (n + 1);
            n++;
        }

        cout << (n - 1) <<  " card(s)" << endl;

        cin >> length;
    }

    return 0;
}

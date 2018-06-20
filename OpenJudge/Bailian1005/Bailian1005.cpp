#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        float x, y;
        cin >> x >> y;

        int z = (int) (3.14 * (x * x + y * y) / 2 / 50) + 1;

        cout << "Property " << (i + 1) <<": This property will begin eroding in year " << z << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a, b;
    int *res = new int[10002];
    memset(res, 0, sizeof(int) * 10002);

    while(cin >> a >> b)
    {
        int i, j;
        if(a > b)
        {
            i = b;
            j = a;
        }
        else
        {
            i = a;
            j = b;
        }

        int max = 1;
        for(int n = i; n <= j; n++)
        {
            if(res[n] == 0)
            {
                int count = 1;
                int k = n;
                while(k != 1) {
                    if(k % 2 != 0) k = 3 * k + 1;
                    else k =  k / 2;
                    count++;
                }
                res[n] = count;
            }
            if(max < res[n]) max = res[n];
        }
        cout << a << " " << b << " " << max << endl;
    }

    return 0;
}

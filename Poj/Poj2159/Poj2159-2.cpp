#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int **arr_chs = new int*[2];
    for(int i = 0; i < 2; i++)
    {
        arr_chs[i] = new int[26];
        memset(arr_chs[i], 0, sizeof(int) * 26);
    }

    char ch;
    for(int i = 0; i < 2; i++)
    {
        int j = 0;
        ch = cin.get();
        while(ch != '\n')
        {
            arr_chs[i][(int)(ch - 'A')]++;
        ch = cin.get();
            j++;
        }
    }

    for(int j0 = 0; j0 < 26; j0++)
    {
        int j1;
        for(j1 = j0; j1 < 26; j1++)
        {
            if(arr_chs[0][j0] == arr_chs[1][j1])
            {
                arr_chs[1][j1] = arr_chs[1][j0];
                break;
            }
        }
        if(j1 >= 26)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}

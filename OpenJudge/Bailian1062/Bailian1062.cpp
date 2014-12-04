#include <iostream>
#include <cstring>
#include <limits>
#include <cstdlib>
#include <cmath>

using namespace std;

int intMax = numeric_limits<int>::max();

int main()
{
    //freopen("D://input.txt","r",stdin);
    int i,j, k, ii;

    int m, n;
    cin >> m >> n;
    //cout << m << " " << n << endl;

    int **arr_map = new int*[n];
    for(i = 0; i < n; ++i)
    {
        arr_map[i] = new int[n];
        for(j = 0; j < n; ++j) arr_map[i][j] = intMax;
    }

    int *arr_p = new int[n];
    int *arr_L = new int[n];

    int p,L,x;
    for(i = 0; i < n; ++i)
    {
        cin >> p >> L >> x;
        arr_p[i] = p;
        arr_L[i] = L;

        int t,v;
        for(j = 0; j < x; ++j)
        {
            cin >> t >> v;
            arr_map[t - 1][i] = v;
        }
    }

    //for(j = 0; j < n; ++j)
    //{
    //    for(k = 0; k < n; ++k) cout << arr_map[j][k] << " ";
    //    cout << endl;
    //}
    //cout << endl;

    int min_p = arr_p[0];

    int *arr_d = new int[n];
    bool *arr_m = new bool[n];

    int **arr_map2 = new int*[n];
    for(i = 0; i < n; ++i) arr_map2[i] = new int[n];

    for(i = 1; i < n; ++i)
    {
        for(ii = 0; ii <= m; ++ii)
        {
            int l_bettom = arr_L[i] - m + ii;
            int l_top = arr_L[i] + ii;

            for(j = 0; j < n; ++j) memcpy(arr_map2[j], arr_map[j], sizeof(int) * n);
            for(j = 0; j < n; ++j)
            {
                /*if(abs(arr_L[j] - arr_L[i]) > m)
                {
                    for(k = 0; k < n; ++k)
                    {
                        arr_map2[k][j] = intMax;
                        arr_map2[j][k] = intMax;
                    }
                }*/
                if(arr_L[j] < l_bettom || arr_L[j] > l_top)
                {
                    for(k = 0; k < n; ++k)
                    {
                        arr_map2[k][j] = intMax;
                        arr_map2[j][k] = intMax;
                    }
                }
            }

            //for(j = 0; j < n; ++j)
            //{
            //    for(k = 0; k < n; ++k) cout << arr_map2[j][k] << " ";
            //    cout << endl;
            //}
            //cout << endl;

            memcpy(arr_d, arr_map2[i], sizeof(int) * n);
            memset(arr_m, 0 ,sizeof(bool) * n);

            arr_d[i] = 0;
            arr_m[i] = true;

            for(j = 1; j < n; ++j)
            {
                int min_d = intMax;
                int idx_d;

                for(k = 0; k < n; ++k)
                {
                    if(!arr_m[k] && min_d > arr_d[k])
                    {
                        min_d = arr_d[k];
                        idx_d = k;
                    }
                }
                if(min_d == intMax) break;

                arr_m[idx_d] = true;
                for(k = 0; k < n; ++k)
                {
                    if(!arr_m[k] && arr_map2[idx_d][k] != intMax && min_d + arr_map2[idx_d][k] < arr_d[k])
                    {
                        arr_d[k] = min_d + arr_map2[idx_d][k];
                    }
                }

                //for(k = 0; k < n; ++k) cout << arr_d[k] << " ";
                //cout << endl;
            }

            if(arr_d[0] != intMax && min_p > arr_d[0] + arr_p[i]) min_p = arr_d[0] + arr_p[i];
        }
    }

    cout << min_p << endl;

    for(i = 0; i < n; ++i) delete [] arr_map2[i];
    delete [] arr_map2;

    delete [] arr_m;
    delete [] arr_d;

    delete [] arr_L;
    delete [] arr_p;

    for(i = 0; i < n; ++i) delete [] arr_map[i];
    delete [] arr_map;


    return 0;
}
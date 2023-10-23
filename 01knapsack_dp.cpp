#include <iostream>
using namespace std;

int main()
{

    int pr[] = {0, 1, 2, 5, 6};
    int wt[] = {0, 2, 3, 4, 5};
    int m = 8;
    int k[5][9];

    for (int i = 0; i <= 4; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (w == 0 || i == 0)
            {
                k[i][w] = 0;
            }
            else if (wt[i] <= w)
            {
                k[i][w] = max(k[i - 1][w], pr[i] + k[i - 1][w - wt[i]]);
            }
            else
            {
                k[i][w] = k[i - 1][w];
            }
            cout<<k[i][w]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
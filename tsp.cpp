#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int inf = numeric_limits<int>::max();

void display(vector<vector<int>> mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int red_row(vector<vector<int>> &mat, int n)
{
    int *mini = new int[n];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int minn = 999;
        for (int j = 0; j < n; j++)
        {
            int ele = mat[i][j];
            if (mat[i][j] == 999)
            {
                continue;
            }
            minn = min(minn, mat[i][j]);
        }
        if (minn == 999)
        {
            minn = 0;
        }
        mini[i] = minn;
        for (int j = 0; j < n; j++)
        {
            int ele = mat[i][j];
            if (mat[i][j] == 999)
            {
                continue;
            }
            mat[i][j] -= mini[i];
        }
        sum += mini[i];
    }
    return sum;
}

int red_col(vector<vector<int>> &mat, int n)
{
    int row = red_row(mat, n);
    int mini[10];
    int col = 0;

    for (int i = 0; i < n; i++)
    {
        int minn = 999;
        for (int j = 0; j < n; j++)
        {

            if (mat[j][i] == 999)
            {
                continue;
            }
            minn = min(minn, mat[j][i]);
        }
        if (minn == 999)
        {
            minn = 0;
        }
        mini[i] = minn;
        for (int j = 0; j < n; j++)
        {

            if (mat[j][i] == 999)
            {
                continue;
            }
            mat[j][i] -= mini[i];
        }
        col += mini[i];
    }
    return col + row;
}

void mk_inf(vector<vector<int>> &mat, int n, int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == x || j == y || (i == y && j == x))
            {
                mat[i][j] = 999;
            }
        }
    }
}

int tsp(vector<vector<int>> mat, int n, int x, int y, vector<bool> vis)
{
    vector<vector<int>> copy = mat;
    vector<bool> visited = vis;
    if (!visited[x])
    {
        visited[x] = true;
        mk_inf(copy, n, x, y);
        display(copy, n);
         red_col(copy, n);
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> matrix = {{999, 20, 30, 10, 11},
                                  {15, 999, 16, 4, 2},
                                  {3, 5, 999, 2, 4},
                                  {19, 6, 18, 999, 3},
                                  {16, 4, 7, 16, 999}};
    cout << red_col(matrix, n) << endl;
    // display(matrix, n);

    /* code */

    return 0;
}

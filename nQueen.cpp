#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    int row = x;
    int col = y;
    for (col = 0; col < n; col++)
    {
        if (arr[x][col] == 1)
        {
            return false;
        }
        if (arr[col][y] == 1)
        {
            return false;
        }
    }

    // upper left
    row = x;
    col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    // upper right
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    // lower left
    row = x;
    col = y;
    while (row < n && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row++;
        col--;
    }

    // lower right
    row = x;
    col = y;
    while (row < n && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row++;
        col++;
    }

    return true;
}

bool nQueen(int **bord, int row, int n)
{

    if (row >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(bord, row, col, n))
        {
            bord[row][col] = 1;
            if (nQueen(bord, row + 1, n))
            {
                return true;
            }
            bord[row][col] = 0; // backtrack
        }
    }

    return false;
}

int main()
{
    int n;
    cout<<"enter n\n";
    cin>>n;

    int **bord = new int*[n];

    for (int i = 0; i < n; i++)
    {
        bord[i] = new int [n];
        for(int j = 0 ; j < n;j++){
            bord[i][j] = 0;
        }
    }

    nQueen(bord,0,n);
    
    for (int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n;j++){
            cout<<bord[i][j]<<" "; 
        }cout<<endl;
    }

    return 0;
}
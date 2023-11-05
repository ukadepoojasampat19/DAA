#include <iostream>
using namespace std;
#define N 4

bool isSafe(int arr[N][N], int row, int col) {

  // check that no queens are present in same column above the current queen
  for (int i = 0; i < row; i++) {
    if (arr[i][col] == 1) {
      return false;
    }
  }

  // check upper left diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (arr[i][j] == 1) {
      return false;
    }
  }

  
// check upper right diagonal
for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
  if (arr[i][j] == 1) {
    return false;
  }
}

  return true;
}

bool solveNQueens(int arr[N][N], int row) {
  if (row == N) {
    return true; // all queens are placed
  }
  for (int col = 0; col < N; col++) {
    if (isSafe(arr, row, col)) {
      arr[row][col] = 1;

      // Recur for the next row
      if (solveNQueens(arr, row + 1)) {
        return true;
      }

      // If placing the queen doesn't lead to a solution, backtrack
      arr[row][col] = 0;
    }
  }
  return false; // No safe position found in this row
}

void printBoard(int arr[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int arr[N][N] = {0};

  if (solveNQueens(arr, 0)) {
    cout << "Solution found:\n";
    printBoard(arr);
  } else {
    cout << "No solution exists for N = " << N << ".\n";
  }

  return 0;
}

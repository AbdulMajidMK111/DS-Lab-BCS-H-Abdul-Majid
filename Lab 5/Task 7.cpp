#include <iostream>
using namespace std;

const int MAX = 20;

bool isSafe(int board[MAX][MAX], int row, int col, int n) 
{
    for (int i = 0; i < row; i++) 
    {
        if (board[i][col] == 1) 
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) 
    {
        if (board[i][j] == 1) 
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) 
    {
        if (board[i][j] == 1) 
        {
            return false;
        }
    }
    return true;
}

void printBoard(int board[MAX][MAX], int n, int solutionCount) 
{
    cout << "Solution " << solutionCount << ":" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int board[MAX][MAX], int row, int n, int &solutionCount) 
{
    if (row == n) 
    {
        solutionCount++;
        printBoard(board, n, solutionCount);
        return;
    }

    for (int col = 0; col < n; col++) 
    {
        if (isSafe(board, row, col, n)) 
        {
            board[row][col] = 1;
            solveNQueens(board, row + 1, n, solutionCount);
            board[row][col] = 0; 
        }
    }
}

int main() 
{
    int n;
    cout << "Enter N for N-Queens: ";
    cin >> n;

    if (n > MAX) 
    {
        cout << "Max N = " << MAX << endl;
        return 0;
    }
    int board[MAX][MAX] = {0};
    int solutionCount = 0;

    solveNQueens(board, 0, n, solutionCount);

    if (solutionCount == 0) 
    {
        cout << "No solutions exist for N = " << n << endl;
    } 
    else 
    {
        cout << "Total solutions: " << solutionCount << endl;
    }
    return 0;
}

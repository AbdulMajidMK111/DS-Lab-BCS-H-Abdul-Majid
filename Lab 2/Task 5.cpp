#include <iostream>
using namespace std;

int** createMatrix(int rows, int cols) 
{
    int** mat = new int*[rows];
    for (int i = 0; i < rows; ++i) 
    {
        mat[i] = new int[cols]{0};  
    }
    return mat;
}

void deleteMatrix(int** mat, int rows) 
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

void inputMatrix(int** mat, int rows, int cols) 
{
    cout << "Enter elements of matrix (" << rows << "x" << cols << "): " << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int** mat, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int** addMatrices(int** A, int** B, int rows, int cols) 
{
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** A, int** B, int rows, int cols) 
{
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

int main() 
{
    int rows, cols;
    cout << "Enter rows and columns of matrices: ";
    cin >> rows >> cols;

    int** A = createMatrix(rows, cols);
    int** B = createMatrix(rows, cols);

    cout << "Input Matrix A:\n";
    inputMatrix(A, rows, cols);
    cout << "Input Matrix B:\n";
    inputMatrix(B, rows, cols);

    int** sum = addMatrices(A, B, rows, cols);
    int** diff = subtractMatrices(A, B, rows, cols);

    cout << "Sum (A + B):\n";
    printMatrix(sum, rows, cols);
    cout << "Difference (A - B):\n";
    printMatrix(diff, rows, cols);

    deleteMatrix(A, rows);
    deleteMatrix(B, rows);
    deleteMatrix(sum, rows);
    deleteMatrix(diff, rows);
    return 0;
}

#include <iostream>
using namespace std;

int main() 
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) 
    {
        matrix[i] = new int[cols];
    }

    cout << "\nEnter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nMatrix in normal form:" << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                nonZeroCount++;
            }
        }
    }

    int** compressed = new int*[nonZeroCount];
    for (int i = 0; i < nonZeroCount; i++) 
    {
        compressed[i] = new int[3];
    }

    int k = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                compressed[k][0] = i;
                compressed[k][1] = j;
                compressed[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    cout << "\nMatrix in compressed form (row, column, value):" << endl;
    for (int i = 0; i < nonZeroCount; i++) 
    {
        cout << compressed[i][0] << " " << compressed[i][1] << " " << compressed[i][2] << endl;
    }

    for (int i = 0; i < rows; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < nonZeroCount; i++) 
    {
        delete[] compressed[i];
    }
    delete[] compressed;
    return 0;
}

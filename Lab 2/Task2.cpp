/* Task#2:
Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
=> Rows represent benches, columns represent seats on each bench.
=> Initialize the array with 0 (empty).
=> Let the user fill seats (1 for occupied).
=> Print the final seating chart in matrix form. */

#include <iostream>
using namespace std;

int main() 
{
    int rows, cols;
    cout << "Enter number of benches (rows): ";
    cin >> rows;
    cout << "Enter number of seats per bench (columns): ";
    cin >> cols;

    int** seating = new int*[rows];
    for (int i = 0; i < rows; ++i) 
    {
        seating[i] = new int[cols];
        for (int j = 0; j < cols; ++j) 
        {
            seating[i][j] = 0;
        }
    }

    char choice;
    do 
    {
        int r, c;
        cout << "Enter bench number: " << rows - 1;
        cin >> r;
        cout << "Enter seat number: " << cols - 1;
        cin >> c;

        if (r < 0 || r >= rows || c < 0 || c >= cols) 
        {
            cout << "Invalid seat number" << endl;
            continue;
        }

        seating[r][c] = 1;

        cout << "Do you want to occupy another seat:y/n: ";
        cin >> choice;
    } 
    while (choice == 'y' || choice == 'Y');

    cout << "Final seating chart: " << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << seating[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) 
    {
        delete[] seating[i];
    }
    delete[] seating;
    return 0;
}

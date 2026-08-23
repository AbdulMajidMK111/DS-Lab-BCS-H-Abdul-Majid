/* Task#1:
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly. */

#include <iostream>
using namespace std;

int main() 
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) 
    {
        arr[i] = 0;
    }

    char choice;
    do 
    {
        int pos, val;
        cout << "Enter the position to update: " << size - 1;
        cin >> pos;

        if (pos < 0 || pos >= size) 
        {
            cout << "Invalid position" << endl;
            continue;
        }

        cout << "Enter the new value: ";
        cin >> val;

        arr[pos] = val;

        cout << "Do you want to update another value:y/n: ";
        cin >> choice;

    } 
    while (choice == 'y' || choice == 'Y');

    cout << "Final array: ";
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << std::endl;

    delete[] arr;
    return 0;
}

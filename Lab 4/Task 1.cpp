/* Task#1:
Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array. */

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Enter target value: ";
    cin >> target;

    int index = -1;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == target) 
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        cout << "Element found at index " << index << endl;
    }
    else
    {
        cout << "Element not found in array" << endl;
    }
    return 0;
}

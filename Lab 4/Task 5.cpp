/* Task#5:
Implement the Interpolation Search algorithm. The program should take a sorted array
with uniformly distributed values and a target value from the user. The algorithm should
estimate the position of the target and check if the estimated position holds the correct
value. If the element is found, print its index; otherwise, indicate that it's not present. */

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the sorted elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Enter target value: ";
    cin >> target;

    int low = 0, high = n - 1, index = -1;

    while (low <= high && target >= arr[low] && target <= arr[high]) 
    {
        if (low == high) 
        {
            if (arr[low] == target)
            {
                index = low;
            }
            break;
        }

        int pos = low + ((double)(target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) 
        {
            index = pos;
            break;
        }
        if (arr[pos] < target)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
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

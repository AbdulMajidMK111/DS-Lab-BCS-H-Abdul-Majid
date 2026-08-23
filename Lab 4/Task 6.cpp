/* Task#6:
Implement the Comb Sort algorithm to sort an array of integers. This algorithm improves
upon bubble sort by reducing the number of comparisons and swaps using a "gap" that
decreases over time. After sorting, perform a complexity analysis: count and display the
total number of swaps and comparisons performed during the sorting process. */

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int gap = n;
    float shrink = 1.3;
    int comparisons = 0, swaps = 0;
    bool swapped = true;

    while (gap > 1 || swapped) 
    {
        gap = gap/shrink;
        if (gap < 1) 
        {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i + gap < n; i++) 
        {
            comparisons++;
            if (arr[i] > arr[i + gap]) 
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;
    return 0;
}

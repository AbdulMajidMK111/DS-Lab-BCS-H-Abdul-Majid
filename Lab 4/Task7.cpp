/* Task#7:
Implement the Shell Sort algorithm to sort an array of integers. The algorithm should start
with a large gap, then perform a gapped insertion sort, and gradually reduce the gap until
it's 1. After sorting, compare its performance against the Bubble Sort and Insertion Sort
algorithms for the same input array size (e.g., 1000 elements). Record and display the time
taken and the number of comparisons/swaps for all three algorithms to demonstrate why
Shell Sort is an improvement over Insertion Sort. */

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> arr, long long &comparisons, long long &swaps) 
{
    int n = arr.size();
    comparisons = swaps = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - 1; j++) 
        {
            comparisons++;
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

void insertionSort(vector<int> arr, long long &comparisons, long long &swaps) 
{
    int n = arr.size();
    comparisons = swaps = 0;
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) 
        {
            comparisons++;
            if (arr[j] > key) 
            {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } 
            else 
            {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void shellSort(vector<int> arr, long long &comparisons, long long &swaps) 
{
    int n = arr.size();
    comparisons = swaps = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap) 
            {
                comparisons++;
                if (arr[j - gap] > temp) 
                {
                    arr[j] = arr[j - gap];
                    swaps++;
                    j -= gap;
                } 
                else 
                {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

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

    long long comps, swaps;

    bubbleSort(arr, comps, swaps);
    cout << "Bubble Sort:\nComparisons: " << comps << ", Swaps: " << swaps << endl;

    insertionSort(arr, comps, swaps);
    cout << "Insertion Sort:\nComparisons: " << comps << ", Swaps: " << swaps << endl;

    shellSort(arr, comps, swaps);
    cout << "Shell Sort:\nComparisons: " << comps << ", Swaps: " << swaps << endl;
    return 0;
}

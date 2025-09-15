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

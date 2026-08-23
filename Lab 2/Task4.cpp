#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "Enter number of months to track expenses: ";
    cin >> n;

    int* expenses = new int[n];

    cout << "Enter expenses for each month: " << endl;
    for (int i = 0; i < n; ++i) 
    {
        cout << "Month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    char choice;
    do 
    {
        cout << "Do you want to add more months:y/n: ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') 
        {
            int extra;
            cout << "Enter no of more months: ";
            cin >> extra;

            int* temp = new int[n + extra];
            for (int i = 0; i < n; ++i) 
            {
                temp[i] = expenses[i];
            }

            cout << "Enter expenses for new months: " << endl;
            for (int i = n; i < n + extra; ++i) 
            {
                cout << "Month " << i + 1 << ": ";
                cin >> temp[i];
            }

            delete[] expenses;
            expenses = temp;
            n += extra;
        }
    } 
    while (choice == 'y' || choice == 'Y');

    int total = 0;
    for (int i = 0; i < n; ++i) 
    {
        total += expenses[i];
    }

    int average = (n > 0) ? total / n : 0;

    cout << "\nTotal expenses for " << n << " months: " << total << endl;
    cout << "Average monthly expense: " << average << endl;

    delete[] expenses;
    return 0;
}

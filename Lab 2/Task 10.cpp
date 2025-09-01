#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int categories;
    cout << "Enter number of categories: ";
    cin >> categories;

    string* categoryNames = new string[categories];
    int* bookCount = new int[categories];
    int** books = new int*[categories];

    for (int i = 0; i < categories; i++) 
    {
        cout << "\nEnter name of category " << i + 1 << ": ";
        cin >> categoryNames[i];
        cout << "Enter number of books in " << categoryNames[i] << ": ";
        cin >> bookCount[i];

        books[i] = new int[bookCount[i]];
        cout << "Enter book IDs for " << categoryNames[i] << ":" << endl;
        for (int j = 0; j < bookCount[i]; j++) 
        {
            cin >> books[i][j];
        }
    }

    int searchID;
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < categories; i++) 
    {
        for (int j = 0; j < bookCount[i]; j++) 
        {
            if (books[i][j] == searchID) 
            {
                cout << "Book ID " << searchID << " is available in category: " << categoryNames[i] << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) 
    {
        cout << "Book ID " << searchID << " not found" << endl;
    }

    for (int i = 0; i < categories; i++) 
    {
        delete[] books[i];
    }
    delete[] books;
    delete[] bookCount;
    delete[] categoryNames;
    return 0;
}

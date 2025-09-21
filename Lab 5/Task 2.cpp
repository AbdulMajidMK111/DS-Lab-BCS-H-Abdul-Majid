#include <iostream>
using namespace std;

void printNumbers(int n) 
{
    if (n == 0) 
    {
        return;
    }
    cout << n << " ";
    printNumbers(n - 1);
}

void functionB(int n);

void functionA(int n) 
{
    if (n <= 0) 
    {
        return;
    }
    cout << n << " ";
    functionB(n - 1);
}

void functionB(int n) 
{
    if (n <= 0) 
    {
        return;
    }
    cout << n << " ";
    functionA(n - 1);
}

int main() 
{
    int num;
    cout << "Enter a number for direct recursion: ";
    cin >> num;
    cout << "Direct recursion output: ";
    printNumbers(num);

    cout << "\nEnter a number for indirect recursion: ";
    cin >> num;
    cout << "Indirect recursion output: ";
    functionA(num);
    return 0;
}

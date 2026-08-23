#include <iostream>
using namespace std;

class SafePointer 
{
private:
    int* ptr;

public:
    SafePointer() : ptr(new int(0)) {}  

    void setValue(int val) 
    {
        if (ptr)
        {
            *ptr = val;
        }
    }

    int getValue() const 
    {
        if(ptr != NULL)
        {
            return *ptr;
        }
        else
        {
            *ptr = 0;
            return *ptr;
        }
    }

    void release() 
    {
        if (ptr) 
        {
            delete ptr;
            ptr = nullptr;
        }
    }

    ~SafePointer() 
    {
        release();
    }
};

int main() 
{
    const int n = 5;
    SafePointer marks[n];

    for (int i = 0; i < n; ++i) 
    {
        int mark;
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> mark;
        marks[i].setValue(mark);
    }

    cout << "\nStudent marks: " << endl;
    for (int i = 0; i < n; ++i) 
    {
        cout << "Student " << i + 1 << ": " << marks[i].getValue() << endl;
    }

    for (int i = 0; i < n; ++i) 
    {
        marks[i].release();
    }
    return 0;
}

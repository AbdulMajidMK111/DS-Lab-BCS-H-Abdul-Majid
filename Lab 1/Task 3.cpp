#include <iostream>
using namespace std;

class Box{
private:
    int* value;

public:
    Box(int val = 0) 
    {
        value = new int(val);
        cout << "Value = " << *value << endl;
    }

    ~Box() 
    {
        cout << "Deleting value = " << *value << endl;
        delete value;
    }

    Box(const Box& other) 
    {
        value = new int(*other.value);
        cout << "Copied value = " << *value << endl;
    }

    Box& operator=(const Box& other) 
    {
        if (this != &other) 
        {
            delete value;
            value = new int(*other.value);
            cout << "Assigned value = " << *value << endl;
        }
        return *this;
    }

    void setValue(int val) 
    {
        *value = val;
    }

    void display() const 
    {
        cout << "Value = " << *value << endl;
    }
};

int main() 
{
    cout << "Deep Copy" << endl;

    Box b1(10);
    Box b2 = b1;
    b2.setValue(20);
    cout << "b1: "; b1.display();
    cout << "b2: "; b2.display();

    Box b3;
    b3 = b1;
    b3.setValue(30);
    cout << "b1: "; b1.display();
    cout << "b3: "; b3.display();

    cout << "\nShallow Copy" << endl;

    Box* s1 = new Box(100);
    Box* s2 = s1;
    s2->setValue(200);

    cout << "s1: "; s1->display();
    cout << "s2: "; s2->display();

    delete s1;

    return 0;
}

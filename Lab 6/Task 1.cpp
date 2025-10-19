#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() 
    {
        top = -1;
    }

    void push(int value) 
    {
        if (top == MAX - 1) 
        {
            cout << "Stack Overflow" << endl;
        } 
        else 
        {
            arr[++top] = value;
            cout << value << " pushed" << endl;
        }
    }

    void pop() 
    {
        if (top == -1) 
        {
            cout << "Stack Underflow" << endl;
        } 
        else 
        {
            cout << arr[top--] << " popped" << endl;
        }
    }

    void peek() 
    {
        if (top == -1) 
        {
            cout << "Stack is empty" << endl;
        } 
        else 
        {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display() 
    {
        if (top == -1) 
        {
            cout << "Stack is empty" << endl;
        } 
        else 
        {
            cout << "Stack contents: ";
            for (int i = top; i >= 0; i--) 
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    Stack s;
    int choice, value;

    while (true) 
    {
        cout << "\nStack Menu" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}

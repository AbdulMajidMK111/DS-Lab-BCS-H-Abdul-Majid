#include <iostream>
using namespace std;

#define MAX 100

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() 
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) 
    {
        if (rear == MAX - 1) 
        {
            cout << "Queue Overflow" << endl;
        } 
        else 
        {
            if (front == -1)
            {
                front = 0;
            }
            arr[++rear] = value;
            cout << value << " enqueued" << endl;
        }
    }

    void dequeue() 
    {
        if (front == -1 || front > rear) 
        {
            cout << "Queue Underflow" << endl;
        } 
        else 
        {
            cout << arr[front++] << " dequeued" << endl;
            if (front > rear)
            {
                front = rear = -1;
            }
        }
    }

    void display() 
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else 
        {
            cout << "Queue contents: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void checkStatus() 
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else if (rear == MAX - 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            cout << "Queue is neither full nor empty" << endl;
        }
    }
};

int main() 
{
    Queue q;
    int choice, value;

    while (true) 
    {
        cout << "\nQueue Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Check Status" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.checkStatus();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}

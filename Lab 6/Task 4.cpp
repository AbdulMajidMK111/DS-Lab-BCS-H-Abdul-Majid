#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() 
    {
        front = -1;
        rear = -1;
    }

    bool isFull() 
    {
        return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
    }

    bool isEmpty() 
    {
        return front == -1;
    }

    void enqueue(int value) 
    {
        if (isFull()) 
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        cout << value << " enqueued" << endl;
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << arr[front] << " dequeued" << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue contents: ";
        int i = front;
        while (true) 
        {
            cout << arr[i] << " ";
            if (i == rear)
            {
                break;
            }
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() 
{
    CircularQueue q;
    int choice, value;

    while (true) 
    {
        cout << "\nCircular Queue Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
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
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}
